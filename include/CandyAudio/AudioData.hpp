#pragma once

#include "libs/dr_libs/dr_mp3.h"
#include "libs/dr_libs/dr_wav.h"
#include "libs/dr_libs/dr_flac.h"
#include "libs/stb_vorbis/stb_vorbis.h"

#include <filesystem>

namespace CandyAudio {
 
class AudioData
{
  public:
    AudioData(const std::filesystem::path& path);
    ~AudioData();

  public:
    // Read the frames of the audio clip
    unsigned long Read(unsigned long frameCount, float* buffer);
    
    // Start the audio clip from the very beginning 
    void Rewind(); 

    const int GetChannels();
    const int GetSampleRate();

  private:
    enum class AudioType
    {
      MP3 = 0,
      WAV,
      FLAC,
      OGG
    };

  private:
    std::filesystem::path m_Path;

    AudioType m_Type;
    
    drmp3 m_Mp3;
    drwav m_Wav;
    drflac m_Flac; 
    
    stb_vorbis* m_Ogg;
    stb_vorbis_info m_OggInfo;   
};

}
