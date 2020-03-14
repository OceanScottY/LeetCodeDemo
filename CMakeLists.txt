cmake_minimum_required(VERSION 3.8)
project(LeetCodeDemo)

set(CMAKE_CXX_STANDARD 11)

set(DEMO_SRC
        main.cpp
        ArrayDemo/ArrayDemo.h
        ArrayDemo/ArrayDemo.cpp
        TreeDemo/TreeDemo.cpp
        TreeDemo/TreeDemo.h
        standardDemo/CPPStanderDemo.cpp
        standardDemo/CPPStanderDemo.h
        standardDemo/CStrDemo.cpp standardDemo/CStrDemo.h standardDemo/CplusDemo.cpp
        Other/Other.cpp Other/Other.h
        DynamicPrograming/DynamicPrograming.cpp DynamicPrograming/DynamicPrograming.h
        DynamicPrograming/TestYhy.cpp DynamicPrograming/TestYhy.h
        JZOffer/File1.cpp JZOffer/File1.h
        BackTracing/BackTracing.cpp BackTracing/BackTracing.h
        GreedyDemo/GreedyDemo.cpp GreedyDemo/GreedyDemo.h C++Demo/BigDecimal.cpp C++Demo/BigDecimal.h)
add_executable(LeetCodeDemo ${DEMO_SRC} )