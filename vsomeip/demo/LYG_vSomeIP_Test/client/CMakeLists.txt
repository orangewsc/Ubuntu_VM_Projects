cmake_minimum_required (VERSION 2.8)

set (CMAKE_CXX_FLAGS "-g -std=c++0x")

set(Boost_LIBRARIES "/home/trj/thirdparty/boost_1_64_0/stage/lib")
set(Boost_INCLUDE_DIR "/home/trj/thirdparty/boost_1_64_0")
set(VSOMEIP_INCLUDE_DIRS "/home/trj/thirdparty/vsomeip/interface")
#set(VSOMEIP_LIBRARIES "/opt/workspace/vsomeip-master/lib")

find_package (vsomeip 2.6.0 REQUIRED)
find_package( Boost 1.55 COMPONENTS system thread log REQUIRED )

include_directories (
    ${Boost_INCLUDE_DIR}
    ${VSOMEIP_INCLUDE_DIRS}
	./inc
)

aux_source_directory(./src DIR_SRCS)

add_executable(client ${DIR_SRCS})
target_link_libraries(client vsomeip ${Boost_LIBRARIES} pthread rt)
