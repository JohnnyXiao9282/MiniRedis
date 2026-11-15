#include <iostream>
#include "test_vector.h"
#include "test_hashmap.h"

int main() {
    TestVector vectorTests;
    vectorTests.runAll();

    TestHashMap hashmapTests;
    hashmapTests.runAll();

    std::cout << "All MiniSTL tests passed!" << std::endl;
    return 0;
}
