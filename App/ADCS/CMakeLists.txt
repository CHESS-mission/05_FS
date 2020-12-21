set(SOURCE_FILES
	"${CMAKE_CURRENT_LIST_DIR}/ADCSComponentAi.xml"
	"${CMAKE_CURRENT_LIST_DIR}/ADCSComponentImpl.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/ADCSHelper.cpp"
)

register_fprime_module()

set(UT_SOURCE_FILES
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/TestMain.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/Tester.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/TesterBase.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/GTestBase.cpp"
)

register_fprime_ut()