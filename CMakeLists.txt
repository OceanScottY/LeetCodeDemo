cmake_minimum_required(VERSION 3.8)
project(LeetCodeDemo)

set(CMAKE_CXX_STANDARD 11)

set(DEMO_SRC
        main_back.cpp
        old_test/ArrayDemo/ArrayDemo.h
        old_test/ArrayDemo/ArrayDemo.cpp
        old_test/TreeDemo/TreeDemo.cpp
        old_test/TreeDemo/TreeDemo.h
        old_test/standardDemo/CPPStanderDemo.cpp
        old_test/standardDemo/CPPStanderDemo.h
        old_test/standardDemo/CStrDemo.cpp old_test/standardDemo/CStrDemo.h
        old_test/standardDemo/CplusDemo.cpp
        old_test/Other/Other.cpp old_test/Other/Other.h
        old_test/DynamicPrograming/DynamicPrograming.cpp old_test/DynamicPrograming/DynamicPrograming.h
        old_test/DynamicPrograming/TestYhy.cpp old_test/DynamicPrograming/TestYhy.h
        old_test/JZOffer/File1.cpp old_test/JZOffer/File1.h
        old_test/BackTracing/BackTracing.cpp old_test/BackTracing/BackTracing.h
        old_test/GreedyDemo/GreedyDemo.cpp old_test/GreedyDemo/GreedyDemo.h
        C++Demo/BigDecimal.cpp C++Demo/BigDecimal.h
        old_test/ThreadDemo/SingleThreadDemo.cpp old_test/ThreadDemo/SingleThreadDemo.h

        old_test/standardDemo/MyString.cpp old_test/standardDemo/MyString.h old_test/sortDemo/sort_demo.h old_test/sortDemo/sort_demo.cpp old_test/CommanAlgorithm/LRUCache.h main.cpp)
add_executable(LeetCodeDemo ${DEMO_SRC} old_test/sortDemo/sort_demo.h old_test/sortDemo/sort_demo.cpp old_test/CommanAlgorithm/LRUCache.h)