cmake_minimum_required(VERSION 3.5)
project (playground)

set(playground_INCLUDE_DIRS
	"."
)

set(playground_SOURCES
	"Window.cpp"
	"Application.cpp"
	"main.cpp"
)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")

set(CMAKE_CXX_COMPILER clang++)

include_directories("${playground_INCLUDE_DIRS}")
add_executable(${PROJECT_NAME}  ${playground_SOURCES})

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)


INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARY} ${OPENGL_LIBRARY})
