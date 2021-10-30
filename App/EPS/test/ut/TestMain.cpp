#include <Fw/Test/UnitTest.hpp>
#include "Tester.hpp"

TEST(Nominal, TestSendCmd) {
    App::Tester tester;
    TEST_CASE(EPS.1,"Test sending cmd with good payload");
    tester.cmdCmdGoodpayloadGoodPort();
    TEST_CASE(EPS.2,"Test sending cmd with 3 bad payloads");
    tester.cmdCmdbadPayload();
    /*TEST_CASE(EPS.3,"Test sending cmd with bad port");
    tester.cmdCmdbadPort();*/
}
TEST(Nominal, TestPort) {
    App::Tester tester;
    TEST_CASE(EPS.3,"Test port with good data");
    tester.portStatusOKNoSched();
    TEST_CASE(EPS.4,"Test port with shed");
    tester.portStatusOKSched();
    TEST_CASE(EPS.5,"Test port status error");
    tester.portStatusNOK();
    TEST_CASE(EPS.6,"Test port Change mode");
    tester.portChangeMode();
    TEST_CASE(EPS.7,"Test port low batt");
    tester.portTestLowVolt();
    TEST_CASE(EPS.8,"Test port high");
    tester.portTestHighTemp();
}

TEST(Nominal, TestPing) {
    App::Tester tester;
    TEST_CASE(EPS.9,"Test cmd send ping");
    tester.cmdSendPing();
    TEST_CASE(EPS.10,"Test port ping");
    tester.cmdPortPingOk();
    TEST_CASE(EPS.11,"Test port ping not ok");
    tester.cmdPortPingOk();
}