#include "include/AudioSource.hpp"
#include "include/AudioData.hpp"

#include <portaudio.h>

#include <filesystem>
#include <iostream>

namespace CandyAudio {

AudioSource::AudioSource(const std::filesystem::path& path)
{
  m_Data = new AudioData(path);
  m_IsPlaying = false;
  m_IsPaused = false;
  m_IsFinished = false;
  m_IsStopped = true;
}

AudioSource::~AudioSource()
{
  // No need to close the stream since it's already stopped
  if(m_IsStopped)
    return;

  int err = Pa_CloseStream(m_Stream);
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';
}
    
void AudioSource::Play()
{
  // Only open a new stream if the previous stream was closed completely
  if(!m_IsStopped)
    return;

  InitPAStream();

  m_IsPlaying = true;
  m_IsStopped = false;
}

void AudioSource::Stop()
{
  // Stream already stopped
  if(m_IsStopped)
    return;
  
  int err = Pa_CloseStream(m_Stream);
  m_Data->Rewind();
  
  m_IsStopped = true;
  m_IsPlaying = false;

  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';
}

void AudioSource::Pause()
{
  // Audio is already paused or stopped
  if(Pa_IsStreamStopped(m_Stream) == 1 || m_IsStopped)
    return;
  
  // Aborting the stream only stops the audio processing 
  // which can be picked up again once the stream stops. 
  // Essentially, giving the illusion of pause and resume.
  int err = Pa_AbortStream(m_Stream); 
  m_IsPaused = true;
  
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << std::endl;
}

void AudioSource::Resume()
{
  // Audio is already playing or stopped 
  if(!m_IsPaused || m_IsStopped)
    return;
 
  // Restart the stream from it left off
  int err = Pa_StartStream(m_Stream); 
  m_IsPaused = false;
  
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << std::endl;
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
                          paNoFlag, // Flags
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

  // The clip is completed if no more frames can be read 
  if(framesRead < frameCount)
  {
    src->m_IsFinished = true;
    return paComplete;
  }

  return paContinue;
}
    
void AudioSource::FinishedCallback(void* userData)
{
  AudioSource* src = (AudioSource*)userData;
  
  src->m_IsPlaying = false;
  src->m_IsFinished = true;
}

} 
