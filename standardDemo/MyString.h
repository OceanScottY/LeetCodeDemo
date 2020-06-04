//
// Created by Mac on 2020/4/2.
//
#pragma once
#ifndef LEETCODEDEMO_MYSTRING_H
#define LEETCODEDEMO_MYSTRING_H

#include <iostream>
#include <istream>
#include <ostream>
/*
class MyString{
public:
    MyString();

    MyString(int len);

    MyString(const char* s);

    MyString(const MyString &s);

    //重载>>运算符,只能在类外实现
    friend std::ostream& operator<<(std::ostream &os,  MyString &s);
    //重载<<运算符,只能在类外实现
    friend  std::istream& operator>>(std::istream &is, MyString &s);
    //重载()运算符
    MyString& operator()(const MyString &str);
    //重载=运算符
    MyString& operator=(const MyString &str);
    //重载+运算符
    MyString operator+(const MyString &str);
    //重载[]运算符
    char& operator[](int index);

    int length() const ();

    ~MyString();


private:
    //长度
    int len;
    //指针
    char *str;

};

*/

#endif //LEETCODEDEMO_MYSTRING_H
