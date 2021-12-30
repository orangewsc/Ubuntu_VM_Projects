project(connectTC297)
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

if(VSOMEIP2)
	INCLUDE_DIRECTORIES(
		${PROJECT_SOURCE_DIR}/include
		/opt/3thPart_Lib/J3_3thPart_lib/vsomeip/vsomeip2/include
		# /home/wsc/HorizonRobotics_PIE/J3/auto_sw/out/horizon_xj3-debug.64/target/sdk/appuser/include
		)
else()
	INCLUDE_DIRECTORIES(
		${PROJECT_SOURCE_DIR}/include
		/opt/3thPart_Lib/J3_3thPart_lib/vsomeip/vsomeip3/include
		# /home/wsc/HorizonRobotics_PIE/J3/auto_sw/out/horizon_xj3-debug.64/target/sdk/appuser/include
		)
endif()


file(GLOB_RECURSE PROJECT_HEADERS "include/*.h" "include/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})


if(CROSS_COMPILE)
	if(VSOMEIP2)
		target_link_libraries(
			${PROJECT_NAME}
			${TARGET_ARM_LIB_PATH}/libstdc++.so.6
			${TARGET_ARM_LIB_PATH}/libpthread.so.0
			/opt/3thPart_Lib/J3_3thPart_lib/vsomeip/vsomeip2/lib/libvsomeip.so.2.8.0
			/opt/3thPart_Lib/J3_3thPart_lib/boost/boost_1.65/lib/libboost_system.so.1.65.0
			/opt/3thPart_Lib/J3_3thPart_lib/boost/boost_1.65/lib/libboost_thread.so.1.65.0
			/opt/3thPart_Lib/J3_3thPart_lib/boost/boost_1.65/lib/libboost_filesystem.so.1.65.0)
	else()
		target_link_libraries(
			${PROJECT_NAME}
			${TARGET_ARM_LIB_PATH}/libstdc++.so.6
			${TARGET_ARM_LIB_PATH}/libpthread.so.0
			/opt/3thPart_Lib/J3_3thPart_lib/vsomeip/vsomeip3/lib/libvsomeip3.so.3.1.20
			/opt/3thPart_Lib/J3_3thPart_lib/boost/boost_1.74/lib/libboost_system.so.1.74.0
			/opt/3thPart_Lib/J3_3thPart_lib/boost/boost_1.74/lib/libboost_thread.so.1.74.0
			/opt/3thPart_Lib/J3_3thPart_lib/boost/boost_1.74/lib/libboost_filesystem.so.1.74.0)
	endif()
else()
	target_link_libraries(
		${PROJECT_NAME}
		pthread
		/usr/local/vsomeip-3.1.20/lib/libvsomeip.so.2.8.0
		)
endif()




