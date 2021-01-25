// ----------------------------------------------------------------------
// TestMain.cpp
// ----------------------------------------------------------------------
#include <Fw/Test/UnitTest.hpp>
#include "Tester.hpp"

TEST(Nominal, TestSendTMData){
    TEST_CASE(TcpSocket.1, "test sending TM to python ADCS simulator");
    Drv::Tester tester;
    tester.testSendTM();
}

TEST(Nominal, TestSendTCData){
    Drv::Tester tester;
    TEST_CASE(TcpSocket.2, "test sending TC  to python ADCS simulator");
    tester.testSendTC();
    TEST_CASE(TcpSocket.3, "test sending TC with wrong CRC to python ADCS simulator");
    tester.testSendTCWrongCrc();
    
}

TEST(Nominal, TestSendBadUARTFrame){
    Drv::Tester tester;
    TEST_CASE(TcpSocket.4, "test sending TM with a bad start byte");
    tester.testSendTMWrongStartByte();
    TEST_CASE(TcpSocket.5, "test sending TM with a bad end byte");
    tester.testSendTMWrongEndByte();
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
