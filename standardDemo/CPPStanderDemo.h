//
// Created by Scott on 2019/11/7.
//

#ifndef LEETCODEDEMO_CPPSTANDERDEMO_H
#define LEETCODEDEMO_CPPSTANDERDEMO_H

#include <iostream>

class Student{
public:
    std::string name_;
    int age_;
    Student(std::string name, int age):name_(name),age_(age){}
    Student(){}

    std::string show(){
        return "name:" + name_ + ", age:" + std::to_string(age_);
    }

    bool operator < (const Student &s) const {
        std::cout << "operator : < " << std::endl;
        if(name_ != s.name_){
            return name_ < s.name_;
        }else{
            return age_ < s.age_;
        }
    }

};

class Comp{
public:
    bool operator () (const Student &left, const Student &right) const {
        std::cout << "operator ()" << std::endl;
        if(left.name_ != right.name_){
            return left.name_ < right.name_;
        }else{
            return left.age_ < right.age_;
        }
    }
};


#endif //LEETCODEDEMO_CPPSTANDERDEMO_H
