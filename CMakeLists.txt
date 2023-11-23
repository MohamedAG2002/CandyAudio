cmake_minimum_required(VERSION 3.27)

project(candyaudio)

find_library(portaudio portaudio REQUIRED)

set(CA_LIBRARY_BUILD_TYPE SHARED)

set(CA_SOURCES 
  src/AudioDevice.cpp
  src/AudioSource.cpp
  src/AudioData.cpp
)

set(CA_INCLUDES
  include/CandyAudio/AudioDevice.hpp
  include/CandyAudio/AudioSource.hpp
  include/CandyAudio/AudioData.hpp
)
  
add_library(${PROJECT_NAME} ${CA_LIBRARY_BUILD_TYPE} ${CA_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/CandyAudio/include)

target_link_libraries(${PROJECT_NAME} PUBLIC ${portaudio})

install(TARGETS ${PROJECT_NAME} 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib 
        ARCHIVE DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)
