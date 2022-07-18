project(J3_TCPTest_Server_Demo)
cmake_minimum_required(VERSION 3.13)


SET(CMAKE_BUILD_TYPE RELEASE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -fPIC -g2")


if(CROSS_COMPILE)
	message("###################### build for J3 target ARM ######################")
	SET(CMAKE_SYSTEM_NAME Linux)
	set(TARGET_ARM_LIB_PATH "/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/aarch64-linux-gnu/libc")
	set(CMAKE_C_COMPILER 		/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc-6.5.0)
	set(CMAKE_CXX_COMPILER 		/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc-6.5.0)
	set(CMAKE_FIND_ROOT_PATH 	/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu)
	# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
endif()


INCLUDE_DIRECTORIES(
						${PROJECT_SOURCE_DIR}/include
						/usr/local/zeromq/zeromq-4.3.1/include
						# /home/wsc/HorizonRobotics_PIE/J3/auto_sw/out/horizon_xj3-debug.64/target/sdk/appuser/include
			)

file(GLOB_RECURSE PROJECT_HEADERS "include/*.h" "include/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})


if(CROSS_COMPILE)
	target_link_libraries(
		${PROJECT_NAME}
		/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/root/usr/lib/libstdc++.so.6
		/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/hbre/third_party/zmq/lib/aarch64/libzmq.so
		)

else()
	target_link_libraries(
		${PROJECT_NAME}
		pthread
		)
endif()




