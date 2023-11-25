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
    void Play();
    void Stop();
    void Pause();
    void Resume();

    void SetVolume(float volume);
    float GetVolume() { return m_Volume; } 
    
    bool IsPlaying() { return m_IsPlaying; }
    bool IsFinished() { return m_IsFinished; } 
    bool IsPaused() { return m_IsPaused; }

  private:
    PaStream* m_Stream; 
    PaStreamParameters m_StreamParam;

    AudioData* m_Data;
    float m_Volume;
    bool m_IsPlaying, m_IsFinished, m_IsPaused, m_IsStopped;

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
