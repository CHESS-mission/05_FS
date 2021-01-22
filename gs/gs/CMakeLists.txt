# Generate MDB before make
# > ../../fprime/Lib/bin/poconfig.exe ../mdb/pusopen_ground_mdb.xml ../mdb/pusopen_ground_mdb.c

# Compile GS :
# > cmake .
# > make

cmake_minimum_required(VERSION 3.0)

project(gs)

SET(FPRIME_PATH ${CMAKE_CURRENT_BINARY_DIR}/../../fprime)
# Classes copied and customized from F' for Buffer and Packet handling
SET(CUSTOM_FPRIME_PATH ${CMAKE_CURRENT_BINARY_DIR}/fprime) 
SET(PUSOPEN_PATH ${FPRIME_PATH}/Lib)
SET(MDB_PATH ${CMAKE_CURRENT_BINARY_DIR}/../mdb)

message("${MDB_PATH}")

add_definitions(-D_LINUB1804_GCC750)

# If pusopen_ground_mdb.c do not exist, generate it (see header)
add_custom_command(
    OUTPUT ${MDB_PATH}/pusopen_ground_mdb.c
    COMMAND mono ${PUSOPEN_PATH}/bin/poconfig.exe ${MDB_PATH}/pusopen_ground_mdb.xml ${MDB_PATH}/pusopen_ground_mdb.c
    DEPENDS ${MDB_PATH}/pusopen_ground_mdb.xml
)

# GS Sources
file(GLOB sources *.cpp common/clientserver.c ${MDB_PATH}/pusopen_ground_mdb.c)

# "Custom" FPrime
include_directories(${CUSTOM_FPRIME_PATH} ${CUSTOM_FPRIME_PATH}/config ${MDB_PATH} ${FPRIME_PATH}/config)     # headers
file(GLOB_RECURSE fprime_sources ${CUSTOM_FPRIME_PATH}/*.cpp)   # sources


add_executable(${CMAKE_PROJECT_NAME} ${sources} ${fprime_sources}) 

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC  ${PUSOPEN_PATH}/Includes common/)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC  ${PUSOPEN_PATH}/lib/libpusopen.a -lstdc++)