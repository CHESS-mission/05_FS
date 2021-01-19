// ----------------------------------------------------------------------
// TestMain.cpp
// ----------------------------------------------------------------------

#include <Fw/Test/UnitTest.hpp>
#include "Tester.hpp"

TEST(Nominal, TestSendCMD) {
    TEST_CASE(CspIpSocket.1, "test sending CMD to python EPS simulator");
    Drv::Tester tester;
    tester.testSendCmdPort7();

    TEST_CASE(CspIpSocket.2, "test sending CMD to python EPS simulator with sched on");
    tester.testSendSchedPort7();
}

TEST(Nominal, TestPing) {
    TEST_CASE(CspIpSocket.3, "Test sending ping");
    Drv::Tester tester;
    tester.testSendPing();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
