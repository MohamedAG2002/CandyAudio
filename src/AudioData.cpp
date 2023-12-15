#include "WonderAudio/AudioData.hpp"

#define DR_MP3_IMPLEMENTATION
#include "dr_libs/dr_mp3.h"

#define DR_WAV_IMPLEMENTATION
#include "dr_libs/dr_wav.h"

#define DR_FLAC_IMPLEMENTATION
#include "dr_libs/dr_flac.h"
#include "stb_vorbis/stb_vorbis.h"

#include <filesystem>
#include <iostream>

namespace WonderAudio {

AudioData::AudioData(const std::filesystem::path& path)
  :m_Path(path)
{
  if(m_Path.extension() == ".mp3" || m_Path.extension() == ".MP3") 
  {
    m_Type = AudioType::MP3; 
    drmp3_init_file(&m_Mp3, m_Path.c_str(), NULL);
  }
  else if(m_Path.extension() == ".wav" || m_Path.extension() == ".WAV") 
  {
    m_Type = AudioType::WAV; 
    drwav_init_file(&m_Wav, m_Path.c_str(), NULL);
  }
  else if(m_Path.extension() == ".flac" || m_Path.extension() == ".FLAC") 
  {
    m_Type = AudioType::FLAC; 
    m_Flac = *drflac_open_file(m_Path.c_str(), NULL);
  }
  else if(m_Path.extension() == ".ogg" || m_Path.extension() == ".OGG") 
  {
    m_Type = AudioType::OGG; 
    m_Ogg = stb_vorbis_open_filename(path.c_str(), 0, NULL);
    m_OggInfo = stb_vorbis_get_info(m_Ogg);

    if(m_Ogg == NULL)
      std::cerr << "ERROR: File at \'" << path.c_str() << "\' failed to load\n";
  }
  else 
    std::cerr << "ERROR: File at \'" << path.c_str() << "\' has unknown extension\n";
}

AudioData::~AudioData()
{
  switch (m_Type) 
  {
    case AudioType::MP3:
      drmp3_uninit(&m_Mp3);
      break;
    case AudioType::WAV:
      drwav_uninit(&m_Wav);
      break;
    case AudioType::FLAC:
      drflac_close(&m_Flac);
      break;
    case AudioType::OGG:
      stb_vorbis_close(m_Ogg);
      break;
    default:
      break;
  }
}

unsigned long AudioData::Read(unsigned long frameCount, float* buffer)
{
  switch (m_Type) 
  {
    case AudioType::MP3:
      return drmp3_read_pcm_frames_f32(&m_Mp3, frameCount, buffer);
      break;
    case AudioType::WAV:
      return drwav_read_pcm_frames_f32(&m_Wav, frameCount, buffer);
      break;
    case AudioType::FLAC:
      return drflac_read_pcm_frames_f32(&m_Flac, frameCount, buffer);
      break;
    case AudioType::OGG:
      return stb_vorbis_get_samples_float_interleaved(m_Ogg, m_OggInfo.channels, buffer, frameCount * m_OggInfo.channels);
    default:
      return 0;
      break;
  }
}
    
void AudioData::Rewind()
{
  switch (m_Type) 
  {
    case AudioType::MP3:
      drmp3_seek_to_pcm_frame(&m_Mp3, 0);
      break;
    case AudioType::WAV:
      drwav_seek_to_pcm_frame(&m_Wav, 0);
      break;
    case AudioType::FLAC:
      drflac_seek_to_pcm_frame(&m_Flac, 0);
      break;
    case AudioType::OGG:
      stb_vorbis_seek_start(m_Ogg);
      break;
    default:
      break;
  }
}
    
const int AudioData::GetChannels()
{
  switch (m_Type) 
  {
    case AudioType::MP3:
      return m_Mp3.channels;
      break;
    case AudioType::WAV:
      return m_Wav.channels;
      break;
    case AudioType::FLAC:
      return m_Flac.channels;
      break;
    case AudioType::OGG:
      return m_OggInfo.channels;
      break;
    default:
      return 0;
      break;
  }
}

const int AudioData::GetSampleRate()
{
  switch (m_Type) 
  {
    case AudioType::MP3:
      return m_Mp3.sampleRate;
      break;
    case AudioType::WAV:
      return m_Wav.sampleRate;
      break;
    case AudioType::FLAC:
      return m_Flac.sampleRate;
      break;
    case AudioType::OGG:
      return m_OggInfo.sample_rate;
      break;
    default:
      return 0;
      break;
  }
}

} 
