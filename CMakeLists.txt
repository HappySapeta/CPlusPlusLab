cmake_minimum_required(VERSION 4.4.0)

project(CPlusPlusLab VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
source_group(
	TREE "${CMAKE_CURRENT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${PROJECT_HEADERS}
)

source_group(
	TREE "${CMAKE_CURRENT_SOURCE_DIR}/src"
	PREFIX "Source Files"
	FILES ${PROJECT_SOURCES}
)

if (MSVC)
	target_compile_options(CPlusPlusLab PRIVATE /W4 /permissive-)
else ()
	target_compile_options(CPlusPlusLab PRIVATE -Wall -Wextra)
endif ()