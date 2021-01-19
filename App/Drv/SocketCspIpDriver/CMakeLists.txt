set(SOURCE_FILES
	"${CMAKE_CURRENT_LIST_DIR}/SocketCspIpDriverComponentAi.xml"
	"${CMAKE_CURRENT_LIST_DIR}/SocketCspIpDriverComponentImpl.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/SocketCspIpHelper.cpp"
)

register_fprime_module()

# Includes
include_directories(../../Lib/includes)

find_library(CSP csp ../../Lib/lib)
find_library(ZMQ zmq ../../Lib/lib)

target_link_libraries(App_Drv_SocketCspIpDriver ${CSP} ${ZMQ})

set(UT_SOURCE_FILES
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/TestMain.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/Tester.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/TesterBase.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/GTestBase.cpp"
)

register_fprime_ut()



