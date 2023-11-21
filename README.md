# CandyAudio
An audio library for playing and loading audio clips. Can be easily integrated into any project. Just follow the build instructions and use it as you please. 
If you want to see some examples of the library in action, please head over to the examples section of this readme.

# Currently supported audio formats:
 - MP3
 - WAV
 - Flac

# Dependencies
 - [PortAudio](https://github.com/PortAudio/portudio)
 - [dr_libs](https://github.com/mackron/dr_libs)

# How To Build It? 
As I'm sure you noticed, this project uses CMake as its build system. So if you hate CMake and can not stand it, then have fun trying to switch the build system for this library. Nonetheless, this project only has two dependencies as you can see in the section above. However, you only need to fetch PortAudio. As for dr_libs, it's already in the project and does not need to be configured. 

Run the following commands to clone and build the library.

~~~
git clone https://github.com/MohamedAG2002/CandyAudio.git
mkdir build
cd build
cmake ..
cmake --build . 
~~~

You can also build this library either statically or dynamically by setting the `CA_LIBRARY_BUILD_TYPE` variable. You can do that by replacing the `cmake ..` by `cmake -DCA_LIBRARY_BUILD_TYPE=SHARED/STATIC`. Obviously, only pick one out of the two options. Either `SHARED` or `STATIC`.

# How Does This Work?
This library only consists of three classes: AudioData, AudioSource, and AudioDevice. Out of the three classes, you will only use two: AudioSource and AudioDevice. The AudioDevice class needs to be called before doing anything with the library. It is responsible for setting up PortAudio. If AudioDevice is not initialized at the beginning of your program, there can be and there will be errors. The program might just quit. Even though the library does handle all of the errors that can occur with PortAudio, it is still a consideration to have on your part. 

Once the AudioDevice has been initialized, you can declare an AudioSource. The AudioSource is the main part. If you want to play a sound effect, use AudioSource. If you want to play music, use AudioSource. If you want to get rid of your debt, you can probably do other things but you can also use AudioSource. AudioSource's constructor takes a path to the audio clip you want to play. Although extra functionality is planned in the future, you can only play, stop, pause, and resume the AudioSource currently. Here's an example: 

~~~c++
#include <CandyAudio/AudioDevice.hpp>
#include <CandyAudio/AudioSource.hpp>

int main()
{
    // Make sure to initialize an AudioDevice first.
    CandyAudio::AudioDevice device;

    // Takes the valid path, takes the audio clip there, checks 
    // what type it is (mp3, flac, wav, etc), and plays it
    CandyAudio::AudioSource song("assets/audio/never_gonna_give_you_up.mp3");

    // Start the audio clip immedietaly. Although you can delay this and put 
    // it anywhere
    song.Play();

    // You can also pause the audio clip 
    song.Pause();

    // Resume it as well 
    song.Resume();

    // And just completely stop it 
    song.Stop();

    // You can restart it if you want of course 
    song.Play();

    // Some black magic to play the full clip. You don't have to do this 
    // if you have some sort of main loop in your program. In fact, don't do 
    // this at all. Just make sure to have a loop somewhere especially if you 
    // didn't start your clip at the beginning of the program.
    while(true)
    {}

    // The AudioDevice and the AudioSource will handle any allocated memory once 
    // the scope ends. You don't have to worry about any of that. You do have to 
    // worry about your own memory, though. The library does not handle *that*
}
~~~

The only class in the library you don't have to touch is the AudioData. It is only used internally by the library to handle different audio formats. The library does that already for you so you don't have to worry about it. Just ignore AudioData completely.
