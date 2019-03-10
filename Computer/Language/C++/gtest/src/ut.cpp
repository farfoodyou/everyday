#include "../include/main.h"
#include <gtest/gtest.h>
namespace gtest{

TEST(test, tet) {
    EXPECT_EQ(999, test());
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

}