#include "../include/CandyAudio/AudioSource.hpp"
#include "../include/CandyAudio/AudioData.hpp"

#include <portaudio.h>

#include <filesystem>
#include <math.h>
#include <iostream>

namespace CandyAudio {

AudioSource::AudioSource(const std::filesystem::path& path)
{
  m_Data = new AudioData(path);
  m_Volume = 0.5f;

  m_IsPlaying = false;
  m_IsFinished = false;
}

AudioSource::~AudioSource()
{
  // No need to close the stream since it's already stopped
  if(m_IsFinished)
    return;

  int err = Pa_CloseStream(m_Stream);
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';
}
    
void AudioSource::Play()
{ 
  // No need to play the stream if it's already playing
  if(m_IsPlaying)
    return;

  // Only initialize the stream at the beginning
  if(!m_Stream)
  {
    InitPAStream();
    
    m_IsPlaying = true;
    m_IsFinished = false;
    
    return;
  }
  
  // If a stream was in fact initialized already, just rewind 
  // the bytes from the beginning and start the stream if it was stopped 
  m_Data->Rewind();
 
  // Only when the stream was already stopped
  if(m_IsFinished)
  {
    int err = Pa_StartStream(m_Stream); 
    if(err != paNoError)
      std::cerr << "ERROR: " << Pa_GetErrorText(err) << std::endl;
  }
  // Only when the stream was not stopped. The stream will need to be stopped 
  // and started again for the rewinding to work.
  else 
  {
    int err = Pa_AbortStream(m_Stream); 
    if(err != paNoError)
      std::cerr << "ERROR: " << Pa_GetErrorText(err) << std::endl;
    
    err = Pa_StartStream(m_Stream);
    if(err != paNoError)
      std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';
  }
    
  m_IsPlaying = true;
  m_IsFinished = false;
}

void AudioSource::Stop()
{
  // Stream already finished
  if(m_IsFinished)
    return;

  int err = Pa_AbortStream(m_Stream); 
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << std::endl;
 
  m_IsPlaying = false;
  m_IsFinished = true;
}

void AudioSource::Pause()
{
  // Audio is already paused
  if(!m_IsPlaying)
    return;
  
  // Aborting the stream only stops the audio processing 
  // which can be picked up again once the stream stops. 
  // Essentially, giving the illusion of pause and resume.
  int err = Pa_AbortStream(m_Stream); 
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << std::endl;
  
  m_IsPlaying = false;
}

void AudioSource::Resume()
{
  // Audio is already playing or stopped 
  if(m_IsPlaying)
    return;
 
  // Restart the stream from it left off
  int err = Pa_StartStream(m_Stream); 
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << std::endl;
  
  m_IsPlaying = true;
  m_IsFinished = false;
}

void AudioSource::SetVolume(float volume)
{
  // Make sure to clamp the volume between 0 and 100
  if(volume >= 0 && volume <= 100)
    m_Volume = volume;
}

void AudioSource::InitPAStream()
{
  // Stream params init 
  m_StreamParam.device = Pa_GetDefaultOutputDevice();
  if(m_StreamParam.device == paNoDevice)
    std::cerr << "ERROR: Could not find sutible device\n";

  m_StreamParam.channelCount = m_Data->GetChannels();
  m_StreamParam.sampleFormat = paFloat32;
  m_StreamParam.suggestedLatency = Pa_GetDeviceInfo(m_StreamParam.device)->defaultLowOutputLatency;
  m_StreamParam.hostApiSpecificStreamInfo = NULL;

  // Open the stream
  int err = Pa_OpenStream(&m_Stream, // Stream
                          NULL, // Input params
                          &m_StreamParam, // Output params
                          m_Data->GetSampleRate(), // Sample rate
                          1024, // Frames per buffer
                          paClipOff, // Flags
                          Callback, // Callback
                          this); // User data
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';

  // Pass callback for PortAudio to call when the stream is finished 
  err = Pa_SetStreamFinishedCallback(m_Stream, FinishedCallback);
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';

  // Always start the stream at initialization
  err = Pa_StartStream(m_Stream);
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';
}

int AudioSource::Callback(const void* inputBuffer,
                          void* outputBuffer,
                          unsigned long frameCount,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags flags,
                          void* userData)
{
  float* output = (float*)outputBuffer;
  AudioSource* src = (AudioSource*)userData;
  unsigned long framesRead; 

  framesRead = src->m_Data->Read(frameCount, output);

  for(int i = 0; i < frameCount; i++)
  {
    *output++ *= src->m_Volume;
    
    // This line is only for stareo audio not for mono
    if(src->m_StreamParam.channelCount > 1)
      *output++ *= src->m_Volume;
  }

  // The clip is completed if no more frames can be read 
  if(framesRead < frameCount)
    return paComplete;

  return paContinue;
}
    
void AudioSource::FinishedCallback(void* userData)
{
  AudioSource* src = (AudioSource*)userData;
  
  src->m_IsPlaying = false;
  src->m_IsFinished = true;
}

} 
