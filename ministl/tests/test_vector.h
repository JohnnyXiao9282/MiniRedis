#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include "../vector.h"

class TestVector {
public:
    void runAll() {
        testDefaultConstructor();
        testPushBackAndIndex();
        testGrow();
        testPopBack();
        testClear();
        testCopyConstructor();
        testCopyAssignment();
        testSelfAssignment();
        testConstAccess();
        testIteration();
        testStrings();
        std::cout << "All vector tests passed!" << std::endl;
    }

private:
    void testDefaultConstructor() {
        vector<int> v;
        assert(v.size() == 0);
        assert(v.empty());
    }

    void testPushBackAndIndex() {
        vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        assert(v.size() == 3);
        assert(!v.empty());
        assert(v[0] == 10 && v[1] == 20 && v[2] == 30);

        v[1] = 99;
        assert(v[1] == 99);
    }

    void testGrow() {
        vector<int> v;
        for (int i = 0; i < 1000; i++) {
            v.push_back(i);
        }
        assert(v.size() == 1000);
        for (int i = 0; i < 1000; i++) {
            assert(v[i] == i);
        }
    }

    void testPopBack() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.pop_back();
        assert(v.size() == 1);
        assert(v[0] == 1);
        v.pop_back();
        assert(v.empty());
    }

    void testClear() {
        vector<int> v;
        for (int i = 0; i < 5; i++) {
            v.push_back(i);
        }
        v.clear();
        assert(v.empty());

        v.push_back(42);   // reuse after clear
        assert(v.size() == 1 && v[0] == 42);
    }

    void testCopyConstructor() {
        vector<int> a;
        a.push_back(1);
        a.push_back(2);

        vector<int> b(a);
        assert(b.size() == 2 && b[0] == 1 && b[1] == 2);

        b[0] = 100;          // deep copy: a must not change
        assert(a[0] == 1);
    }

    void testCopyAssignment() {
        vector<int> a;
        a.push_back(1);
        a.push_back(2);

        vector<int> b;
        b.push_back(9);
        b = a;
        assert(b.size() == 2 && b[0] == 1 && b[1] == 2);

        b[1] = 200;
        assert(a[1] == 2);

        vector<int> c;
        vector<int> d;
        c = d = a;           // chained assignment
        assert(c.size() == 2 && d.size() == 2);
    }

    void testSelfAssignment() {
        vector<int> a;
        a.push_back(7);
        vector<int>& ref = a;
        a = ref;
        assert(a.size() == 1 && a[0] == 7);
    }

    void testConstAccess() {
        vector<int> v;
        v.push_back(5);
        const vector<int>& cv = v;
        assert(cv[0] == 5);
        assert(cv.size() == 1);
    }

    void testIteration() {
        vector<int> v;
        for (int i = 1; i <= 4; i++) {
            v.push_back(i);
        }

        int sum = 0;
        for (int x : v) {
            sum += x;
        }
        assert(sum == 10);

        for (int& x : v) {
            x *= 2;
        }
        assert(v[3] == 8);

        const vector<int>& cv = v;
        int constSum = 0;
        for (const int& x : cv) {
            constSum += x;
        }
        assert(constSum == 20);
    }

    void testStrings() {
        vector<std::string> v;
        v.push_back("SET");
        v.push_back("key");
        v.push_back("value");
        assert(v.size() == 3);
        assert(v[0] == "SET" && v[2] == "value");

        vector<std::string> copy = v;
        copy[0] = "GET";
        assert(v[0] == "SET");
    }
};
