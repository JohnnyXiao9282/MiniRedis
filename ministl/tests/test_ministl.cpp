#include <iostream>
#include "test_vector.h"

int main() {
    TestVector vectorTests;
    vectorTests.runAll();

    std::cout << "All MiniSTL tests passed!" << std::endl;
    return 0;
}
