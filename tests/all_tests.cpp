#include "../gtest/gtest.h"
#include "../include/proto.h"

TEST(SolutionTest, CanPackData_1)
{
    double a = 10.5, b = 2.5;
    Operation op = ADD;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    EXPECT_NO_THROW(packData(buffer, op, a, b));
}

TEST(SolutionTest, CanPackData_2)
{
    double a = -17.5, b = 2.5;
    Operation op = MULTIPLY;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    EXPECT_NO_THROW(packData(buffer, op, a, b));
}

TEST(SolutionTest, CanPackData_3)
{
    double a = 1e-5, b = 0.3;
    Operation op = SUBTRACT;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    EXPECT_NO_THROW(packData(buffer, op, a, b));
}

TEST(SolutionTest, CanPackData_4)
{
    double a = 10.5, b = -7.34e-6;
    Operation op = DIVIDE;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    EXPECT_NO_THROW(packData(buffer, op, a, b));
}

TEST(SolutionTest, CanUnpackData_1)
{
    double a = 10.5, b = 2.5;
    Operation op = ADD;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    EXPECT_NO_THROW(unpackData(buffer, unpackedOp, unpackedA, unpackedB));
}

TEST(SolutionTest, CanUnpackData_2)
{
    double a = -17.5, b = 2.5;
    Operation op = MULTIPLY;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    EXPECT_NO_THROW(unpackData(buffer, unpackedOp, unpackedA, unpackedB));
}
TEST(SolutionTest, CanUnpackData_3)
{
    double a = 1e-5, b = 0.3;
    Operation op = SUBTRACT;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    EXPECT_NO_THROW(unpackData(buffer, unpackedOp, unpackedA, unpackedB));
}
TEST(SolutionTest, CanUnpackData_4)
{
    double a = 10.5, b = -7.34e-6;
    Operation op = DIVIDE;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    EXPECT_NO_THROW(unpackData(buffer, unpackedOp, unpackedA, unpackedB));
}


TEST(SolutionTest, UnpackedIsCorrect_1)
{
    double a = 10.5, b = 2.5;
    Operation op = ADD;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    unpackData(buffer, unpackedOp, unpackedA, unpackedB);

    EXPECT_EQ(a, unpackedA);
    EXPECT_EQ(b, unpackedB);
    EXPECT_EQ(op, unpackedOp);
}

TEST(SolutionTest, UnpackedIsCorrect_2)
{
    double a = -17.5, b = 2.5;
    Operation op = MULTIPLY;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    unpackData(buffer, unpackedOp, unpackedA, unpackedB);

    EXPECT_EQ(a, unpackedA);
    EXPECT_EQ(b, unpackedB);
    EXPECT_EQ(op, unpackedOp);
}

TEST(SolutionTest, UnpackedIsCorrect_3)
{
    double a = 1e-5, b = 0.3;
    Operation op = SUBTRACT;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    unpackData(buffer, unpackedOp, unpackedA, unpackedB);

    EXPECT_EQ(a, unpackedA);
    EXPECT_EQ(b, unpackedB);
    EXPECT_EQ(op, unpackedOp);
}

TEST(SolutionTest, UnpackedIsCorrect_4)
{
    double a = 10.5, b = -7.34e-6;
    Operation op = DIVIDE;
    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    unpackData(buffer, unpackedOp, unpackedA, unpackedB);

    EXPECT_EQ(a, unpackedA);
    EXPECT_EQ(b, unpackedB);
    EXPECT_EQ(op, unpackedOp);
}

TEST(SolutionTest, CanPerformOperation_1)
{
    double a = 10.5, b = 2.5;
    Operation op = ADD;

    EXPECT_NO_THROW(performOperation(op, a, b));
    EXPECT_EQ(a + b, performOperation(op, a, b));
}

TEST(SolutionTest, CanPerformOperation_2)
{
    double a = -17.5, b = 2.5;
    Operation op = MULTIPLY;

    EXPECT_NO_THROW(performOperation(op, a, b));
    EXPECT_EQ(a * b, performOperation(op, a, b));
}

TEST(SolutionTest, CanPerformOperation_3)
{
    double a = 1e-5, b = 0.3;
    Operation op = SUBTRACT;

    EXPECT_NO_THROW(performOperation(op, a, b));
    EXPECT_EQ(a - b, performOperation(op, a, b));
}

TEST(SolutionTest, CanPerformOperation_4)
{
    double a = 10.5, b = -7.34e-6;
    Operation op = DIVIDE;

    EXPECT_NO_THROW(performOperation(op, a, b));
    EXPECT_EQ(a / b, performOperation(op, a, b));
}

TEST(SolutionTest, ThrowWhenZeroDevision)
{
    double a = 10.5, b = 0;
    Operation op = DIVIDE;

    EXPECT_ANY_THROW(performOperation(op, a, b));
}