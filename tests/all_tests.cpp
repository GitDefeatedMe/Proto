#include "../gtest/gtest.h"
#include "../include/proto.h"

TEST(SolutionTest, CanPackData)
{
    double a = 10.5, b = 2.5;
    Operation op = MULTIPLY;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    EXPECT_NO_THROW(packData(buffer, op, a, b));
}
