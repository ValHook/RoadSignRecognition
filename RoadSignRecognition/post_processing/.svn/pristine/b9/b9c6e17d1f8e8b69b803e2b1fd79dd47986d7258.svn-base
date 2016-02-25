cmake_minimum_required (VERSION 2.8.3) 

# Project Name
project(ihls_nhs)

find_package(OpenCV)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../RotationalOffset/)


# Sources
set( SOURCES    main.cpp
                PostProcessing.cpp )

# Target
add_executable( post_processing ${SOURCES} )
target_link_libraries( post_processing ${OpenCV_LIBS} )