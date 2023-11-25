#pragma once

#include "AudioData.hpp"

#include <portaudio.h>

#include <filesystem>

namespace CandyAudio {
 
class AudioSource
{
  public:
    AudioSource(const std::filesystem::path& path);
    ~AudioSource();

  public:
    // Play an audio source from the start
    void Play();

    // Stop an audio source completely
    void Stop();

    // Pause an audio clip from playing. Can be reversed with Resume()
    void Pause();

    // Resume an audio clip again after being stopped or paused
    void Resume();

    // Sets the internal volume of the source to the given volume. 
    // The internal volume of the source is between 0 and 1. Therefore, 
    // the volume given to this function should be between 0 and 100. The volume 
    // internally is clamped between 0 and 1. Any values greater than or less than will 
    // be ignored.
    void SetVolume(float volume);

    // Returns the internal volume of the source. Since the volume internally is 
    // a value between 0 and 1, it will be converted to a range between 0 and 100 
    // before being returned. 
    float GetVolume(); 
    
    bool IsPlaying() { return m_IsPlaying; }
    bool IsFinished() { return m_IsFinished; } 
    bool IsPaused() { return m_IsPlaying; }

  private:
    PaStream* m_Stream; 
    PaStreamParameters m_StreamParam;

    AudioData* m_Data;
    float m_Volume;
    bool m_IsPlaying, m_IsFinished;

  private:
    void InitPAStream();
    static int Callback(const void* inputBuffer,
                        void* outputBuffer,
                        unsigned long frameCount,
                        const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags flags,
                        void* userData);
    static void FinishedCallback(void* userData); 
};

}
