cmake_minimum_required(VERSION 3.27)

project(candyaudio)

find_library(portaudio portaudio REQUIRED)
find_library(raylib raylib REQUIRED)

set(SOURCES 
  src/main.cpp
  src/AudioDevice.cpp
  src/AudioSource.cpp
  src/AudioData.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

target_link_libraries(${PROJECT_NAME} PUBLIC ${portaudio} ${raylib})
