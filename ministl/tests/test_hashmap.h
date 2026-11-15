#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include "../hashmap.h"

class TestHashMap {
public:
    void runAll() {
        testDefaultConstructor();
        testPutAndGet();
        testUpdate();
        testGetMissing();
        testContains();
        testRemoveHead();
        testRemoveMiddle();
        testRemoveMissing();
        testRehash();
        testCopyConstructor();
        testCopyAssignment();
        testSelfAssignment();
        testIntKeys();
        std::cout << "All hashmap tests passed!" << std::endl;
    }

private:
    void testDefaultConstructor() {
        hashmap<std::string, int> m;
        assert(m.size() == 0);
        assert(m.empty());
    }

    void testPutAndGet() {
        hashmap<std::string, int> m;
        m.put("a", 1);
        m.put("b", 2);

        int value;
        assert(m.get("a", value) && value == 1);
        assert(m.get("b", value) && value == 2);
        assert(m.size() == 2);
        assert(!m.empty());
    }

    void testUpdate() {
        hashmap<std::string, int> m;
        m.put("a", 1);
        m.put("a", 100);

        int value;
        assert(m.get("a", value) && value == 100);
        assert(m.size() == 1);   // update must not add a new entry
    }

    void testGetMissing() {
        hashmap<std::string, int> m;
        int value = 42;
        assert(!m.get("missing", value));
        assert(value == 42);     // untouched when not found
    }

    void testContains() {
        hashmap<std::string, int> m;
        m.put("a", 1);
        assert(m.contains("a"));
        assert(!m.contains("b"));
    }

    void testRemoveHead() {
        hashmap<std::string, int> m;
        m.put("a", 1);
        m.remove("a");
        assert(!m.contains("a"));
        assert(m.empty());
    }

    void testRemoveMiddle() {
        hashmap<std::string, int> m;
        for (int i = 0; i < 100; i++) {
            m.put(std::to_string(i), i);
        }

        m.remove("50");
        assert(!m.contains("50"));
        assert(m.size() == 99);

        // every other key must survive
        int value;
        for (int i = 0; i < 100; i++) {
            if (i == 50) {
                continue;
            }
            assert(m.get(std::to_string(i), value) && value == i);
        }
    }

    void testRemoveMissing() {
        hashmap<std::string, int> m;
        m.put("a", 1);
        m.remove("zzz");
        assert(m.size() == 1);
        assert(m.contains("a"));
    }

    void testRehash() {
        hashmap<std::string, int> m;
        for (int i = 0; i < 1000; i++) {
            m.put("key" + std::to_string(i), i);
        }
        assert(m.size() == 1000);

        int value;
        for (int i = 0; i < 1000; i++) {
            assert(m.get("key" + std::to_string(i), value) && value == i);
        }
    }

    void testCopyConstructor() {
        hashmap<std::string, int> a;
        a.put("x", 1);
        a.put("y", 2);

        hashmap<std::string, int> b(a);
        assert(b.size() == 2);

        int value;
        assert(b.get("x", value) && value == 1);

        b.put("x", 100);         // deep copy: a must not change
        assert(a.get("x", value) && value == 1);

        b.put("z", 3);
        assert(!a.contains("z"));
    }

    void testCopyAssignment() {
        hashmap<std::string, int> a;
        a.put("x", 1);

        hashmap<std::string, int> b;
        b.put("old", 9);
        b = a;
        assert(b.size() == 1);
        assert(b.contains("x"));
        assert(!b.contains("old"));

        b.remove("x");
        assert(a.contains("x"));

        hashmap<std::string, int> c;
        hashmap<std::string, int> d;
        c = d = a;               // chained assignment
        assert(c.contains("x") && d.contains("x"));
    }

    void testSelfAssignment() {
        hashmap<std::string, int> a;
        a.put("x", 7);
        hashmap<std::string, int>& ref = a;
        a = ref;

        int value;
        assert(a.size() == 1);
        assert(a.get("x", value) && value == 7);
    }

    void testIntKeys() {
        hashmap<int, std::string> m;
        m.put(1, "one");
        m.put(-5, "minus five");  // negative keys must still work

        std::string value;
        assert(m.get(1, value) && value == "one");
        assert(m.get(-5, value) && value == "minus five");
    }
};
