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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
