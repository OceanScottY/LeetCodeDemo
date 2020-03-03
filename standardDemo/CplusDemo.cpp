//
// Created by Mac on 2020/1/31.
//
#include <iostream>
#include <string>

using namespace std;
class Stu
{
public:
    Stu()= default;
    Stu(int a, string n):age(a),name(n){
        cout << "this is Stu. " << endl;
    }
    void show(){
        cout << "Stu : name = " << name << ", age = " << age << endl;
    }

private:
    int age;
    string name;
};

class Stu1 : Stu
{
public:
    Stu1()= default;
    Stu1(int age, string name, string addr):Stu(age, name),addr(addr){
        cout << "this is Stu1. " << endl;
    }
    void show(){
        cout << "addr = " << addr << endl;
    }

private:
    string addr;
};

class Stu2 : Stu1
{
public:
    Stu2()= default;
    Stu2(int age, string name, string addr, string birth):Stu1(age, name, addr), birth(birth){
            cout << "this is Stu2. " << endl;
    }
    void show(){
        cout << "birth :" << birth << endl;
    }
private:
    string birth;
};