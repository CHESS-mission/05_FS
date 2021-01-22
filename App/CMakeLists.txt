####
# 'App' Deployment:
#
# This sets up the build for the 'Ref' Application, including the custom reference
# components. In addition, it imports FPrime.cmake, which includes the core F Prime
# components.
#
# This file has several sections.
#
# 1. Header Section: define basic properties of the build
# 2. F prime core: includes all F prime core components, and build-system properties
# 3. Local subdirectories: contains all deployment specific directory additions
####

##
# Section 1: Basic Project Setup
#
# This contains the basic project information. Specifically, a cmake version and
# project definition.
##
project(App C CXX)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
add_definitions(-D_PUS)     # to use PUS with GS
#add_definitions(-D_GDS)    # to use F' GDS (without PUS)

##
# Section 2: F prime Core
#
# This includes all of the F prime core components, and imports the make-system. F prime core
# components will be placed in the F-Prime binary subdirectory to keep them from
# colliding with deployment specific items.
##
include("${FPRIME_FRAMEWORK_PATH}/cmake/FPrime.cmake")
# NOTE: register custom targets between these two lines
include("${FPRIME_FRAMEWORK_PATH}/cmake/FPrime-Code.cmake")
##
# Section 3: Components and Topology
#
# This section includes deployment specific directories. This allows use of non-
# core components in the topology, which is also added here.
##

# Generate PUSOpen mission database c file from xml description
## NOT WORKING (?) - Do it manually when changes in pusopen_onboard_mdb.xml
add_custom_command(
    OUTPUT ${FPRIME_FRAMEWORK_PATH}/Lib/mdb/pusopen_onboard_mdb.c
    WORKING_DIR ${FPRIME_FRAMEWORK_PATH}/Lib
    COMMAND mono ./bin/poconfig.exe ./mdb/pusopen_onboard_mdb.xml ./Lib/mdb/pusopen_onboard_mdb.c 
)

# Includes
include_directories(Lib/includes)   # App Lib (CSP)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../gs/mdb) # hk_param.h in Topology.cpp

# Add component subdirectories
add_fprime_subdirectory("${FPRIME_FRAMEWORK_PATH}/Ref/PingReceiver/")
add_fprime_subdirectory("${FPRIME_FRAMEWORK_PATH}/Ref/RecvBuffApp/")
add_fprime_subdirectory("${FPRIME_FRAMEWORK_PATH}/Ref/SendBuffApp/")
add_fprime_subdirectory("${FPRIME_FRAMEWORK_PATH}/Ref/SignalGen/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/EventAction/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/EPS/EPSPort/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Drv/SocketTcpDriver/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Drv/SocketCspIpDriver/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ADCS/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/EPS/")


# Add Topology subdirectory
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Top/")

