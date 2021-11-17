project(ShmTest)
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
file(GLOB_RECURSE PROJECT_SOURCES_1 "src/procress1.cpp" "src/include.cpp")
file(GLOB_RECURSE PROJECT_SOURCES_2 "src/procress2.cpp" "src/include.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(shm_write ${PROJECT_SOURCES_1} ${PROJECT_HEADERS})
target_link_libraries(
			shm_write
			/usr/local/lib/
			pthread
			rt
			)

add_executable(shm_read ${PROJECT_SOURCES_2} ${PROJECT_HEADERS})
target_link_libraries(
			shm_read
			/usr/local/lib/    
			pthread
			rt
			)


