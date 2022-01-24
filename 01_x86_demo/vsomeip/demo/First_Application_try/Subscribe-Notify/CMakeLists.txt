# Copyright (C) 2015-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

cmake_minimum_required (VERSION 2.8.7)
project (vSomeIPFirstApplication)

find_package(Threads REQUIRED)
# find_package(Boost REQUIRED)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(VSOMEIP_NAME "vsomeip3")

include_directories(${VSOMEIP_INCLUDE_DIRS})

find_package(${VSOMEIP_NAME})
if (NOT ${VSOMEIP_NAME}_FOUND)
    message("${VSOMEIP_NAME} was not found. Please specify vsomeip_DIR")
endif()



file(GLOB_RECURSE PROJECT_SOURCES_1 "src/service-example.cpp")
file(GLOB_RECURSE PROJECT_SOURCES_2 "src/client-example.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(vSomeIPFirstApplication_Service ${PROJECT_SOURCES_1})
target_link_libraries(vSomeIPFirstApplication_Service
                        ${VSOMEIP_LIBRARIES} )           

add_executable(vSomeIPFirstApplication_Client ${PROJECT_SOURCES_2})
target_link_libraries(vSomeIPFirstApplication_Client
                        ${VSOMEIP_LIBRARIES}
                        pthread )   