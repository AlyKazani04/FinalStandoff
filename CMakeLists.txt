cmake_minimum_required(VERSION 3.15)
project(FinalStandoff)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable colored diagnostics and debug symbols
add_compile_options(-fdiagnostics-color=always -g)

# Define SFML root directory
set(SFML_ROOT "DISK:/PATH/TO/SFML-3.0.0")

# Include directories
include_directories("${SFML_ROOT}/include")
link_directories("${SFML_ROOT}/lib")

# Set sources (adjust this to include your real source files)
file(GLOB_RECURSE SOURCES 
    src/main.cpp 
    src/Constants/*.cpp 
    src/UI/*.cpp 
    src/UI/Crawls/*.cpp 
    src/Sound/*.cpp 
    src/Levels/*.cpp
    src/Character/*.cpp
    src/Enemy/*.cpp
)

# Create executable
add_executable(FinalStandoff ${SOURCES})

# Define SFML static
target_compile_definitions(FinalStandoff PRIVATE SFML_STATIC)


# Link static SFML and system libraries
target_link_libraries(FinalStandoff
sfml-graphics-s
sfml-window-s
sfml-audio-s
sfml-system-s
opengl32
freetype
winmm
gdi32
flac
vorbisenc
vorbisfile
vorbis
ogg
ws2_32
user32
advapi32
)

# Static linking options
target_link_options(FinalStandoff PRIVATE -static -static-libgcc -static-libstdc++)

# Suppress console window (Windows GUI app)
if(WIN32)
    set_target_properties(FinalStandoff PROPERTIES LINK_FLAGS "-mwindows")
endif()

# message(STATUS "Sources: " ${SOURCES})

# set(CMAKE_VERBOSE_MAKEFILE ON)
