// ----------------------------------------------------------------------
// TestMain.cpp
// ----------------------------------------------------------------------
#include <Fw/Test/UnitTest.hpp>
#include "Tester.hpp"

TEST(Nominal, TestTMCmd) {
    App::Tester tester;
    TEST_CASE(ADCS.1,"Test the down limit of the TM id");
    tester.testCmdTMBadId();
    TEST_CASE(ADCS.2, "Test with a good TM id");
    tester.testCmdTMGoodId();
}

TEST(Nominal, TestTCCmd) {
    App::Tester tester;
    TEST_CASE(ADCS.3,"Test the up limit of the TC id");
    tester.testCmdTCBadId();
    TEST_CASE(ADCS.4, "Test with a good TC id");
    tester.testCmdTCGoodIdPayload();
    TEST_CASE(ADCS.5,"Test with bad payload");
    tester.testCmdTCBadPayloadData();
    TEST_CASE(ADCS.6, "Test with a good payload");
    tester.testCmdTCBadPayloadSize();
}

TEST(Nominal, TestDataInPort) {
    App::Tester tester;
    TEST_CASE(ADCS.7,"Test Data in for TM");
    tester.testPortTM();
    TEST_CASE(ADCS.8, "Test Data in for TC");
    tester.testPortTC();

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
