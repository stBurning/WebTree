
cmake_minimum_required(VERSION 3.12)
project(cgi_reviews)
set(CMAKE_CXX_STANDARD 14)
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
    set(EXECUTABLE_OUTPUT_PATH "C:/OSPanel/domains/localhost")
    add_executable(cgi_tree main.cpp cgi/cgi.cpp cgi/cgi.h)
    set_target_properties(
            cgi_tree
            PROPERTIES
            OUTPUT_NAME "tree"
            SUFFIX ".cgi"
    )
else()
    add_executable(cgi_tree main.cpp cgi/cgi.cpp cgi/cgi.h students.cpp)
endif()