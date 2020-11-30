#include "Tester.hpp"

//
TEST(Nominal, AddTest) {
    App::Tester tester;
    Fw::CmdStringArg seq("seq");
    tester.testAdd(0x80, seq);
}
//*/

//
TEST(Nominal, RemoveExistingTest) {
    App::Tester tester;
    tester.testRemoveExisting();
}
//*/

//
TEST(Nominal, RemoveEmptyTest) {
    App::Tester tester;
    tester.testRemoveEmpty();
}
//*/

//
TEST(Nominal, RemoveUnexistingTest) {
    App::Tester tester;
    tester.testRemoveUnexisting();
}
//*/

//
TEST(Nominal, DumpEmptyTest) {
    App::Tester tester;
    tester.testDumpEmpty();
}
//*/

//
TEST(Nominal, DumpTest) {
    App::Tester tester;
    tester.testDump();
}
//*/

//
TEST(Nominal, AddFulltest) {
    App::Tester tester;
    tester.testAddFull(EVENT_ACTION_TABLE_SIZE);
}
//*/

//
TEST(Nominal, AddSameTest) {
    App::Tester tester;
    tester.testAddSame();
}
//*/

/*/
TEST(Nominal, EventSequenceTest) {
    App::Tester tester;
    tester.testEventSequence();
}
//*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}   
