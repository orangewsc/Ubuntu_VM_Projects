project(processfork)
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE RELEASE)
#add_definitions(-D _GLIBCXX_USE_CXX11_ABI=1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g -O2")

#set(WORK_DIR /home/wsc/Projects/H2_LCMTest)
INCLUDE_DIRECTORIES(
			include
			/usr/local/include
			)

file(GLOB_RECURSE PROJECT_HEADERS "include/*.h" "include/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp" )

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(processfork ${PROJECT_SOURCES} ${PROJECT_HEADERS})

link_directories(/usr/local/lib)
target_link_libraries(
			processfork
			/usr/local/lib/
			pthread
			rt
			)



