#pragma once
#include <cstring>
#include <stdexcept>

enum Operation {
    ADD = 0x01,
    SUBTRACT = 0x02,
    MULTIPLY = 0x03,
    DIVIDE = 0x04
};

struct Header {
    uint8_t operation;
    uint32_t dataSize;
};

double performOperation(Operation op, double a, double b) {
    switch (op) {
    case ADD: return a + b;
    case SUBTRACT: return a - b;
    case MULTIPLY: return a * b;
    case DIVIDE:
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    default: throw std::runtime_error("Unknown operation");
    }
}

void packData(char* buffer, Operation op, double a, double b) {
    Header header;
    header.operation = op;
    header.dataSize = sizeof(double) * 2;

    std::memcpy(buffer, &header, sizeof(Header));
    std::memcpy(buffer + sizeof(Header), &a, sizeof(double));
    std::memcpy(buffer + sizeof(Header) + sizeof(double), &b, sizeof(double));
}

void unpackData(const char* buffer, Operation& op, double& a, double& b) {
    Header header;
    std::memcpy(&header, buffer, sizeof(Header));

    op = static_cast<Operation>(header.operation);
    std::memcpy(&a, buffer + sizeof(Header), sizeof(double));
    std::memcpy(&b, buffer + sizeof(Header) + sizeof(double), sizeof(double));
}