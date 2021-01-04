// ----------------------------------------------------------------------
// TestMain.cpp
// ----------------------------------------------------------------------

#include "Tester.hpp"

TEST(Nominal, ToDo) {
    Drv::Tester tester;
    tester.toDo();
}
TEST(Nominal, ToDo2) {
    Drv::Tester tester;
    tester.toDo2();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
