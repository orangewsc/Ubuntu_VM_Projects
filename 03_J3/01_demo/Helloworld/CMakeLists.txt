project(J3_HelloWorld_Demo)
cmake_minimum_required(VERSION 3.13)

SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_BUILD_TYPE RELEASE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -fPIC -g2")

set(TARGET_ARM_LIB_PATH "/home/wsc/HorizonRobotics_PIE/J3/auto_sw/out/horizon_xj3-debug.64/target/sdk/appuser/lib")


if(CROSS_COMPILE)
	message("###################### build for J3 target ARM ######################")
	set(CMAKE_C_COMPILER 		/home/wsc/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc-6.5.0)
	set(CMAKE_CXX_COMPILER 		/home/wsc/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc-6.5.0)
	set(CMAKE_FIND_ROOT_PATH 	/home/wsc/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu)
	# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
endif()


INCLUDE_DIRECTORIES(
						${PROJECT_SOURCE_DIR}/include
						# /home/wsc/HorizonRobotics_PIE/J3/auto_sw/out/horizon_xj3-debug.64/target/sdk/appuser/include
			)

file(GLOB_RECURSE PROJECT_HEADERS "include/*.h" "include/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})


if(CROSS_COMPILE)
	target_link_libraries(
		${PROJECT_NAME}
		${TARGET_ARM_LIB_PATH}/libstdc++.so.6
		${TARGET_ARM_LIB_PATH}/libpthread.so.0
		)

else()
	target_link_libraries(
		${PROJECT_NAME}
		pthread
		)
endif()




