#include <iostream>
#include "..\include\proto.h"

int main() {
    double a = 10.5, b = 2.5;
    Operation op = ADD;

    char buffer[sizeof(Header) + 2 * sizeof(double)];
    packData(buffer, op, a, b);

    Operation unpackedOp;
    double unpackedA, unpackedB;
    unpackData(buffer, unpackedOp, unpackedA, unpackedB);
    
    double result = performOperation(unpackedOp, unpackedA, unpackedB);
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}