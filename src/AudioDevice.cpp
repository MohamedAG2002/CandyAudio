#include "../include/CandyAudio/AudioDevice.hpp"

#include <portaudio.h>

#include <iostream>

namespace CandyAudio {
 
AudioDevice::AudioDevice()
{
  int err = Pa_Initialize();
  
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';
  else
    std::cout << "LOG INFO: PortAudio was successfully initialized\n";
}

AudioDevice::~AudioDevice()
{
  int err = Pa_Terminate();
  
  if(err != paNoError)
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << '\n';
  else 
    std::cout << "LOG INFO: PortAudio was successfully terminated\n";
}

}
