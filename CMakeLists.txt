cmake_minimum_required(VERSION 3.27)

project(WonderAudio)

find_library(portaudio portaudio REQUIRED)

set(WA_LIBRARY_BUILD_TYPE SHARED)

set(WA_SOURCES 
  src/AudioDevice.cpp
  src/AudioSource.cpp
  src/AudioData.cpp
)

set(WA_LIBS_SOURCES
  src/stb_vorbis/stb_vorbis.c
)
  
add_library(${PROJECT_NAME} ${WA_LIBRARY_BUILD_TYPE} ${WA_SOURCES})

target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/libs)

target_link_libraries(${PROJECT_NAME} PUBLIC ${portaudio})

install(TARGETS ${PROJECT_NAME} 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib 
        ARCHIVE DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)
