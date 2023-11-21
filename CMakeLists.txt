cmake_minimum_required(VERSION 3.27)

project(candyaudio)

find_library(portaudio portaudio REQUIRED)

set(CA_LIBRARY_BUILD_TYPE SHARED)

set(SOURCES 
  CandyAudio/src/AudioDevice.cpp
  CandyAudio/src/AudioSource.cpp
  CandyAudio/src/AudioData.cpp
)
  
add_library(${PROJECT_NAME} ${CA_LIBRARY_BUILD_TYPE} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/CandyAudio/src/include)

target_link_libraries(${PROJECT_NAME} PUBLIC ${portaudio})
