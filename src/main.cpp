#include "include/AudioDevice.hpp"
#include "include/AudioSource.hpp"

#include <raylib.h>

int main()
{
  CandyAudio::AudioDevice device;
  CandyAudio::AudioSource source("/home/mohamed/Downloads/baly.mp3");

  InitWindow(256, 240, "CandyAudio");

  while (!WindowShouldClose()) 
  {
    if(IsKeyPressed(KEY_R))
      source.Resume();
    else if(IsKeyPressed(KEY_P))
      source.Pause();
    else if(IsKeyPressed(KEY_Q))
      source.Stop();
    else if(IsKeyPressed(KEY_SPACE))
      source.Play();

    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
  }

  CloseWindow();
}
