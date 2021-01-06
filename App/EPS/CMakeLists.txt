set(SOURCE_FILES
	"${CMAKE_CURRENT_LIST_DIR}/EPSComponentAi.xml"
	"${CMAKE_CURRENT_LIST_DIR}/EPSComponentImpl.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/EPSHkAnalyser.cpp"
)

register_fprime_module()

set(UT_SOURCE_FILES
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/TestMain.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/Tester.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/TesterBase.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/GTestBase.cpp"
)

register_fprime_ut()
