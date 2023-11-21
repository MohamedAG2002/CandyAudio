#pragma once

#include "../../lib/dr_libs/dr_mp3.h"
#include "../../lib/dr_libs/dr_flac.h"
#include "../../lib/dr_libs/dr_wav.h"

#include <filesystem>

namespace CandyAudio {
 
class AudioData
{
  public:
    AudioData(const std::filesystem::path& path);
    ~AudioData();

  public:
    unsigned long Read(unsigned long frameCount, float* buffer);
    const int GetChannels();
    const int GetSampleRate();

  private:
    enum class AudioType
    {
      MP3 = 0,
      WAV,
      FLAC
    };

  private:
    std::filesystem::path m_Path;

    AudioType m_Type;
    
    drmp3 m_Mp3;
    drwav m_Wav;
    drflac m_Flac; 
};

}
