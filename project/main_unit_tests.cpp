#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char *argv[]) {
    std::cout << "estoy ejecutando otro main" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}