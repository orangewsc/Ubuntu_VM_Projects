project(USBCom_Receiver)
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE RELEASE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g2")

#set(WORK_DIR /home/wsc/Projects/H2_LCMTest)
INCLUDE_DIRECTORIES(
			include
			/usr/local/include/lcm
			include/LCM_Header
			)

file(GLOB_RECURSE PROJECT_HEADERS "include/*.h" "include/*.hpp" "include/LCM_Header/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(
			${PROJECT_NAME}
			/usr/local/lib/liblcm.so.1.4.0     #origin:1.3.4
			pthread
			)


