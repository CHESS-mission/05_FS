#include <Fw/Test/UnitTest.hpp>

#include "Tester.hpp"

//
TEST(Nominal, AddTest) {
    TEST_CASE(EventAction.1, "Add event-sequence entry");

    App::Tester tester;
    Fw::CmdStringArg seq("seq");
    tester.testAdd(0x80, seq);
}
//*/

//
TEST(Nominal, RemoveExistingTest) {
    TEST_CASE(EventAction.2, "Remove existing event-sequence entry");

    App::Tester tester;
    tester.testRemoveExisting();
}
//*/

//
TEST(Nominal, RemoveEmptyTest) {
    TEST_CASE(EventAction.1, "Remove event-sequence entry when empty");

    App::Tester tester;
    tester.testRemoveEmpty();
}
//*/

//
TEST(Nominal, RemoveUnexistingTest) {
    TEST_CASE(EventAction.4, "Remove unexisting event-sequence entry");

    App::Tester tester;
    tester.testRemoveUnexisting();
}
//*/

//
TEST(Nominal, DumpEmptyTest) {
    TEST_CASE(EventAction.5, "Dump event-sequence entry when empty");

    App::Tester tester;
    tester.testDumpEmpty();
}
//*/

//
TEST(Nominal, DumpTest) {
    TEST_CASE(EventAction.6, "Dump event-sequence entries");

    App::Tester tester;
    tester.testDump();
}
//*/

//
TEST(Nominal, AddFulltest) {
    TEST_CASE(EventAction.7, "Add event-sequence entry when full");

    App::Tester tester;
    tester.testAddFull(EVENT_ACTION_TABLE_SIZE);
}
//*/

//
TEST(Nominal, AddSameTest) {
    TEST_CASE(EventAction.8, "Add two event-sequence entries for the same event id");

    App::Tester tester;
    tester.testAddSame();
}
//*/

//
TEST(Nominal, EntryCorrespondingEventTest) {
    TEST_CASE(EventAction.9,"Add event-sequence entry and receive corresponding event");
    REQUIREMENT("seq.bin sequence file in CmdDispatcher");

    App::Tester tester;
    tester.testEntryCorrespondingEvent();
}
//*/

//
TEST(Nominal, EntryNonCorrespondingEventTest) {
    TEST_CASE(EventAction.10,"Add event-sequence entry and receive non-corresponding event");

    App::Tester tester;
    tester.testEntryNonCorrespondingEvent();
}
//*/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
