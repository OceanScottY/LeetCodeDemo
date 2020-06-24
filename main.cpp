#include <iostream>
#include <vector>
#include "ArrayDemo/ArrayDemo.h"
#include "standardDemo/CplusDemo.cpp"
#include <memory>
#include <mutex>

using namespace std;

void test_array_generate(){
    vector<vector<int>> res = generate(5);
}

void test_array_getRow(){
    vector<int> res = getRow(3);
    for(auto p = res.begin(); p != res.end(); p++){
        cout << *p << ",";
    }
    cout << endl;
}

void test_array_merge(){
    vector<int> v1 = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {2, 5, 6};
    merge(v1, 3, v2, 3);
    cout << endl;
    for(int i = 0; i < 6; i ++){
        cout << v1[i] << ", ";
    }
    cout << endl;
}

#include <map>
vector<pair<string, string>> test_map(){
    map<string, string> res_map;
//    res_map.insert(pair<string, string>("f1", "v1"));
//    res_map.insert(pair<string, string>("f2", "v2"));
//    res_map.insert(pair<string, string>("f3", "v3"));
//
    vector<pair<string, string>> res_vec;
//    for(auto p = res_map.begin(); p != res_map.end(); p++){
//        res_vec.push_back(*p);
//    }

    map<int , string > res_int;
    res_int.insert(pair<int, string>(1,"1"));
    res_map.insert(pair<string, string>("1", "2"));
    cout << res_int[1] << endl;
    cout << res_map["1"] << endl;

    return res_vec;
}

void test_array_twoSum(){
    vector<int > src = {2, 7, 11, 13, 15};
    vector<int > res = twoSum(src, 15);
    for(auto it = res.begin(); it != res.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}

void test_array_threeSum(){
    vector<int> src = {-1, 0, 2, 1, -1, -4};
    vector<int> src_1 = {0, 0, 0};
    vector<vector<int >> res = threeSum(src_1);
    cout << "[ " << endl;
    for(auto vec = res.begin(); vec != res.end(); vec++){
        cout << "    [ " ;
        for(auto it = vec->begin(); it != vec->end(); it++){
            cout << *it << ",";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
}

void test_array_fourSum(){
    vector<int> src = {1, 0, -1, 0, -2, 2};
    vector<vector<int >> res = fourSum(src, 0);
    cout << "[ " << endl;
    for(auto vec = res.begin(); vec != res.end(); vec++){
        cout << "    [ " ;
        for(auto it = vec->begin(); it != vec->end(); it++){
            cout << *it << ",";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
}

void test_array_findMin(){
    vector<int> src = {1, 2, 3};
    int res = findMin(src);
    cout << "res:" << res << endl;
}

void test_array_findmin2(){
    vector<int> src = {1, 1, 1};
    int res = findMin2(src);
    cout << "res:" << res << endl;
}

void test_array_largestRectangleArea(){
    vector<int> src = {2, 1, 5, 6, 2, 3};
//    vector<int> src = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
//    vector<int> src = {0, 9};
    int area = largestRectangleArea(src);
    cout << "res: " << area << endl;
}
//using namespace std;
#include <algorithm>
void test_algorithem(){
//    vector<int> src = {2, 1, 5, 6, 2, 3, 0};
    vector<int> src = {0, 9};
    vector<int>::iterator minimum = std::min_element(src.begin(), src.begin() + src.size());
    cout << "min:" << *minimum << endl;
}
void test_maximalRectangle(){
    vector<vector<char >> src;
    src.push_back({'1', '0', '1', '0', '0'});
    src.push_back({'1', '0', '1', '1', '1'});
    src.push_back({'1', '1', '1', '1', '1'});
    src.push_back({'1', '0', '0', '1', '0'});
    int res = maximalRectangle(src);
    cout << "res：" << res << endl;
}

void test_isPalindrome(){
    int src = 123;
    cout << isPalindrome(src) << endl;
}

void test_searchMatrix(){
    /*vector<vector<int >> src = {
            {1,3,5,7},
            {10,11,16,20},
            {23,30,34,50}
    };*/
    vector<vector<int>> src = {{1}};

    bool res = searchMatrix(src, 1);

    if(res)
        cout << "res : true." << endl;
    else
        cout << "res : false." << endl;
}

#include <math.h>

bool test_str_contain(string src, string contain_str){
    string::size_type idx = src.find(contain_str);
    if(idx != string::npos){
        return true;
    }else{
        return false;
    }
}

void test_searchInsert(){
//    vector<int > src = {1, 3, 5, 6};
//    int target = 5;
//    int position = searchInsert(src, target);
//    cout << " position is " << position << endl;
}

string strPlus(string num1, string num2){
    if(num1.size()<num2.size()){//把num1固定为位数较大的那个数，方便后面处理
        string temp=num1;
        num1=num2;
        num2=temp;
    }
    int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;//flag是进位标记
    while(length1>0){//从低位开始把对应的位相加
        a=num1[length1-1]-'0';//获取num1当前位的数字
        if(length2>0)//如果num2还没加完（注意，num2是位数较少的）
            b=num2[length2-1]-'0';//获取num2当前位的数字
        else
            b=0;//如果num2加完了，num2对应位上就没有数来加了
        //这时我没有break，因为虽然num2没有数字来加了，但可能还有进位需要加
        sum=a+b+flag;//num1与num2对应位上的数字相加，再加上进位位
        if(sum>=10){//如果加起来大于于10，那就需要进位了
            num1[length1-1]='0'+sum%10;//计算加完之后，当前位应该是多少
            flag=1;//把进位标记置1
        }else{
            num1[length1-1]='0'+sum;//计算加完之后，当前位应该是多少
            flag=0;//把进位标记置0
        }
        length1--;//向高位移动1位
        length2--;//向高位移动1位
    }
    //如果两个数对应位都加完了，进位位是1，说明位数要增加1了
    //比如99+1，加完之后，变成了三位数100，其实就是再在前面加一位1
    if(1==flag)
        num1="1"+num1;
    return num1;
}

#include <set>
#include <iomanip>

void test_isPowerOfTwo(){
    bool res = isPowerOfTwo(2);
    if(res){
        cout << "this is true" << endl;
    }else{
        cout << "this is false" << endl;
    }
}
#include "TreeDemo/TreeDemo.h"
void test_preorderTraversal(){

    TreeNode* n2 = new TreeNode(3);
    n2->left = NULL;
    n2->right = NULL;
    TreeNode* n1 = new TreeNode(2);
    n1->left = n2;
    n1->right = NULL;
    TreeNode* root = new TreeNode(1);
    root->left = NULL;
    root->right = n1;

    vector<int> res = preorderTraversal(root);
    for(auto it = res.begin(); it != res.end(); it++){
        cout << *it << "->";
    }
    cout << endl;
}

void test_connect(){
    Node* root = new Node(1);

    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    root->left = n2;
    root->right = n3;

    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n2->left = n4;
    n2->right = n5;

    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    n3->left = n6;
    n3->right = n7;

    Node* res = connect(root);
    cout << "eqawr" << endl;
}


void test_path_sum(){
    TreeNode *root = new TreeNode(5);

    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(8);
    root->left = n1;
    root->right = n2;

    TreeNode *n3 = new TreeNode(11);
    TreeNode *n4 = new TreeNode(13);
    TreeNode *n5 = new TreeNode(7);
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;

//    TreeNode *n1 = new TreeNode(4);
    vector<vector<int>> res = pathSum(root, 20);
    cout << "{" << endl;
    for(auto vec : res){
        cout << "[ ";
        for(auto i : vec){
            cout << i << ", ";
        }
        cout << "]" << endl;
    }
    cout << "}" << endl;
}

void test_flatten(){
    TreeNode *root = new TreeNode(0);

//    TreeNode *n1 = new TreeNode(1);
//    TreeNode *n2 = new TreeNode(2);
//    root->left = n1;
//    root->right = n2;
//
//    TreeNode *n3 = new TreeNode(3);
//    TreeNode *n4 = new TreeNode(4);
//    TreeNode *n5 = new TreeNode(5);
//    TreeNode *n6 = new TreeNode(6);
//    n1->left = n3;
//    n1->right = n4;
//    n2->left = n5;
//    n2->right = n6;

    flatten(root);
}

void test_c_standard(){
    int a[2][3] = {1,2,3,4,5,6};
    cout << a << endl;
}

#include <stdlib.h>
#include <vector>
void test_vector(){
    int num[] = {1,2,3,4,5,6,7};

    vector<int > vec(num, num+7);
    for (int i = 0; i < vec.size(); ++i) {
        cout << " i = " << i << ", num :" << num[i] << endl;
    }

    vector<int >::iterator it = find(vec.begin(), vec.end(), 5);
    if(it == vec.end()){
        cout << "not found" << endl;
    }else{
        cout << *it << " found" << endl;

    }

}


#include <map>
void test_map_val_pku(){
    map<string, string> mTemp;
    mTemp["a"] = "aa";
    mTemp["b"] = "bb";
    mTemp["c"] = "cc";
    mTemp["d"] = "dd";

    for(auto it = mTemp.begin(); it != mTemp.end();it++){
        if(it->second == "bb"){
            mTemp.erase(it);
        }
    }

    for(auto it = mTemp.begin(); it != mTemp.end(); it++){
        cout << "first:" << it->first << ", second:" << it->second << endl;
    }

}

struct Stest{
    string name;
    void show(){
        cout << "name:" << name << endl;
    }
};


void print_int(const int (&i)[6]){
    cout << "cout int array" << endl;
}
class Tes{
public:
    Tes(){

    }
    void show(){
        lock_guard<mutex> lock(t_mutex);
        cout << " this is a show method 1 " << endl;
        show2();
    }
    void show2(){
        cout << "2" << endl;
        lock_guard<mutex> lock(t_mutex);
        cout << " this is a show method 2" << endl;
        show3();
    }
    void show3(){
        cout << "3" << endl;
        lock_guard<mutex> lock(t_mutex);
        cout << " this is a show method 3" << endl;
    }

private:
    string name;
    mutex t_mutex;
};
#include <cctype>
void test_c_yhy_standard(){
    const char t[5] = "qwer";
    int len = sizeof(t)/sizeof(char);
    cout << "length : " << len << endl;

    auto test = begin(t);
    cout << *test << endl;
    cout << " ********* " << endl;
    Tes *tes = new Tes();
    shared_ptr<Tes> test_ptr(tes);
    shared_ptr<Tes> test_ptr2(tes);
    cout << test_ptr.use_count() << endl;
    cout  << "asdasd" << endl;


}


class Scott{
public:
    Scott()= default;
    Scott(const string &name):name_(name){

    }
    Scott(const string &name, const string &addr):name_(name),addr_(addr){

    }
    Scott(const string &name, const int &i, const int &j, const string &addr):
            name_(name),addr_(addr),index(i),row(j){

    }
    Scott(const int &i):row(i),index(row){

    }
    ~Scott(){}
    void set(const string &str){
        this->name_ = str;
    }
    string get(){
        return this->name_;
    }
    void set_addr(const string addr) const {
        addr_ = addr;
    }
    string get_addr(){
        return addr_;
    }
    void show_int(){
        cout << "index: " << index << ", row:" << row << endl;
    }
    Scott& combine(const Scott& s){
        name_ += s.name_;
        return *this;
    }

    void show_name(){
        cout << "name: " << name_ << endl;
    }

private:
    string name_;
    int row,index;
    mutable string addr_;

};



#include "Other/Other.h"

void test_lengthOfLongestSubstring(){
    string str = "abcabcdbd";
    int len = lengthOfLongestSubstring(str);
    cout << "result : " << len << endl;
}



#include <iterator>
void shared_int(shared_ptr<int> p){

}
void test_itr(){
    vector<int> vec;
    auto it = back_inserter(vec);
    cout << " before operation " << endl;
    for(auto iter = vec.begin(); iter != vec.end(); iter++){
        cout << *iter << ", " ;
    }
    cout << endl;
    *it = 42;
    *it = 46;
    cout << "after operation " << endl;
    for(auto iter = vec.begin(); iter != vec.end(); iter++){
        cout << *iter << ", " ;
    }

    int *i(new int);
    shared_int(shared_ptr<int>(i));
    int j = *i;
    cout << "nums :" << j << endl;


}

void test_sumNumbers(){
    TreeNode* root = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    root->left = n2;
    root->right = n3;
    n2->right = n5;

    sumNumbers(root);
}
#include "DynamicPrograming/DynamicPrograming.h"
void test_uniquePathsWithObstacles(){
    vector<vector<int>> test = {
            {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
            {1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},
            {0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
            {0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0},
            {1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0},
            {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0},
            {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
            {1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},
            {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},
            {0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0},
            {0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1},
            {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0},
            {0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},
            {0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1},
            {1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},
            {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0}

    };
    int res = uniquePathsWithObstacles(test);
    cout << "res : " << res << endl;
}


void test_maxProfit3(){
    vector<int> prices = {6,1,3,2,4,7};
    int max_pro = maxProfit3(prices);
    cout << max_pro << endl;
}

void test_minPathSum(){
    vector<vector<int>> test = {
            {1,3,1},
            {1,5,1},
            {4,2,1}
    };
    int res = minPathSum(test);
    cout << "res : " << res << endl;
}

void test_numSquars(){
    int num = 12;
    int res = numSquars(num);
    cout << "res:" << res << endl;
}

extern int test_yhy;
extern void test_yhy_m();

extern int name_yhy;
extern void name_yhy_m();

#include "JZOffer/File1.h"
void test_offer(){
    JZListNode *head = new JZListNode(1);
    JZListNode *p1 = new JZListNode(2);
    JZListNode *p2 = new JZListNode(3);
    JZListNode *p3 = new JZListNode(4);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    vector<int> res = printListFromTailToHead(head);

    for(auto it = res.begin(); it != res.end(); it++){
        cout << *it << "->" ;
    }
}

#include "BackTracing/BackTracing.h"
void test_combinationSum(){

    vector<int> can = {2, 3, 5};
    std::vector<std::vector<int>>  res = combinationSum(can, 8);
    for(int i = 0; i < res.size(); i++){
        for(int j=0; j < res[i].size(); j++){
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
}

class A{
private:
    string name;
public:
    A()= default;
    A(string n):name(n){}
    ~A(){}
    void change_and_show() {
        name = "wahaha";
        cout << "name:" << (*this).name << endl;
    }
};

#include <queue>
#include <algorithm>

void test_combinationSum2(){
    vector<int> can = {2, 2, 1, 2, 5};
    vector<vector<int>> res = combinationSum2(can, 5);
    for(int i = 0; i < res.size(); i++){
        for(int j=0; j < res[i].size(); j++){
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
}

#include "GreedyDemo/GreedyDemo.h"

void test_canCompleteCircuit(){
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int res = canCompleteCircuit(gas, cost);
    cout << "res:" << res << endl;
}

void test_set(){
    set<string> str_set;
    str_set.emplace("java");
    str_set.emplace("avaj");
    str_set.emplace("dvaj");
    str_set.emplace("bava");

    for(auto it : str_set){
        cout << "," << it;
    }
    cout << "." << endl;
}

#include "standardDemo/CPPStanderDemo.h"

bool comp (const Student &left, const Student &right){
    cout << "comp method" << endl;
    if(left.name_ != right.name_){
        return left.name_ < right.name_;
    }else{
        return left.age_ < right.age_;
    }
}

void test_student(){
//    set<Student, decltype(comp)*> s(comp);
//    set<Student, Comp> s;
//    pair<set<Student>::iterator, bool > res =  s.emplace(Student("Janney", 23));
//    if(res.second){
//        cout << "successful." << endl;
//    }
//    s.emplace(Student("Danney", 22));
//    s.emplace(Student("LiMing", 20));
//    s.emplace(Student("LiMing", 18));
//    s.emplace(Student("于海洋", 18));
//    s.emplace(Student("黎明", 18));
//    s.emplace(Student("哈哈", 18));
//    s.emplace(Student("梵蒂冈", 18));
//
//    s.insert(res.first,Student("Yuhy", 26));
//
//    for(auto it : s){
//        cout << it.show() << endl;
//
//    }

    set<int> sInt;
    //元素添加
    //1、返回pair对象，second表示是否添加成功
    pair<set<int>::iterator, bool > isSu = sInt.insert(5);
    if(isSu.second){
        cout << "successful!" << endl;
    }
    //2、在iterator前插入元素 insert(&pos, value)，返回新元素的位置
    sInt.insert(isSu.first,9);
    //3、添加区间，将区间[&first, &last)区间内的元素添加到set中
    int array[] = {4, 10, 6};
    sInt.insert(array, array+3);

    for(auto it : sInt){
        cout << it << ", ";
    }

    //元素删除
    //1、erase(value),返回移除元素的个数
//    auto num = sInt.erase(6);
//    cout << "移除元素个数：" << num << endl;
//    //2、erase(&pos),移除pos上的元素,无返回值
//    auto iter = sInt.begin();
//    sInt.erase(iter);
//    for(auto it : sInt){
//        cout << it << ", ";
//    }
//    //3、erase(&first, &last),移除[&first， &last)区间内的元素
//
////    sInt.erase(sInt.begin(), sInt.end());
//    cout << endl << "after [fir, last) : " << endl;
//    for(auto it : sInt){
//        cout << it << ", ";
//    }
//    //4、移除所有元素
//    sInt.clear();
//    cout << endl << "after clear : " << endl;
//    for(auto it : sInt){
//        cout << it << ", ";
//    }

    //查找
    //1、count（value），返回value的个数
    cout << sInt.count(10) << endl;
    //2、iterator find（value），返回value的位置，如果找不到，则返回end（）
    auto res_find_f = sInt.find(10);
    if(res_find_f == sInt.end()){
        cout << "未找到" << endl;
    }else{
        cout << "已找到" << endl;

    }
    auto res_find_s = sInt.find(20);
    if(res_find_s == sInt.end()){
        cout << "未找到" << endl;
    }else{
        cout << "已找到" << endl;

    }








}

bool cmp_value(const pair<Student, string>& a, const pair<Student, string>& b) {
    return b.second < a.second;
}

void test_map_learn(){
    map<int, string> m_str;
    pair<map<int, string>::iterator, bool> is_suc;
    //map的插入有三种方式
    //1、insert（pair<>）
    is_suc = m_str.insert(pair<int, string>(2, "yuhy"));
    //可以用is_suc判断是否插入成功
    if(is_suc.second){
        cout << "successful" << endl;
    }else{
        cout << "failed" << endl;
    }
    //2、insert （value_type）
    m_str.insert(map<int, string>::value_type(5, "scott"));
    //3、用数组方式插入数据
    m_str[1] = "LiMing";


    //遍历方式四种：
    //1、for each
    for(auto it : m_str){
        cout << "key:" << it.first << ", value:" << it.second << endl;
    }
    cout << "-------" << endl;
    //2、前向迭代器
    for(auto it = m_str.begin(); it != m_str.end(); it++){
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
    cout << "-------" << endl;
    //3、反向迭代器
    for(auto it = m_str.rbegin(); it != m_str.rend(); it++){
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
    cout << "-------" << endl;
    //4、数组遍历方式
//    for(int i=0; i<m_str.size(); i++){
//        cout << "value:" << m_str[i] << endl;
//    }

    //查找，两种
    //1、count，查询关键字是否出现，无法判定其位置，返回值0或者1，1表示存在
    cout << "5 是否出现 ：" ;
    if(m_str.count(5) == 1){
        cout << "是";
    }else{
        cout << "否";
    }
    cout << endl;
    //2、find，返回值是迭代器，如果不存在则返回end()
    map<int, string>::iterator res_find = m_str.find(5);
    if(res_find == m_str.end()){
        cout << "yuhy 不存在" << endl;
    }else{
        cout << "yuhy key：" << res_find->first << ", value:" << res_find->second << endl;
    }

    //删除
    //1、erase(k),删除键为k的元素，并返回删除的个数
    cout << "--- 删除 ----" << endl;
    for(auto it : m_str){
        cout << "key:" << it.first << ", value:" << it.second << endl;
    }
    cout << "-------" << endl;
    map<int, string>::size_type res_erase = m_str.erase(5);
    cout << "num of erase:" << res_erase << endl;
    for(auto it : m_str){
        cout << "key:" << it.first << ", value:" << it.second << endl;
    }
    cout << "-------" << endl;
    //2、erase(it),删除迭代器it指向的元素
    m_str.erase(m_str.find(1));
    for(auto it : m_str){
        cout << "key:" << it.first << ", value:" << it.second << endl;
    }
    cout << "-------" << endl;

    //3、erase(it_f, it_e),删除一段范围内的元素
    m_str.erase(m_str.begin(), m_str.end());
    for(auto it : m_str){
        cout << "key:" << it.first << ", value:" << it.second << endl;
    }
    cout << "-------" << endl;


    map<Student, string, decltype(comp)*> m_stu(comp);
    m_stu.insert(pair<Student, string>(Student("yyy", 20), "yyy"));
    m_stu.insert(pair<Student, string>(Student("aaa", 20), "aaa"));
    m_stu.insert(pair<Student, string>(Student("yyy", 18), "yyy"));
    cout << "--- 排序 ---" << endl;
    for(auto it : m_stu){
        cout << "key-name:" << it.first.name_ << ", key-age:" << it.first.age_ << ", value:" << it.second << endl;
    }

    vector<pair<Student, string>> vec(m_stu.begin(), m_stu.end());
    sort(vec.begin(), vec.end(), cmp_value);
    for(auto it : vec){
        cout << "key-name:" << it.first.name_ << ", key-age:" << it.first.age_ << ", value:" << it.second << endl;
    }

}

void test_vect_learn(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    //三种遍历方式
    //1、下标
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << ", ";
    }
    cout << endl << "---------" << endl;
    //2、迭代器
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        cout << *it << ", ";
    }
    cout << endl << "---------" << endl;
    //3、for each
    for(int temp : vec){
        cout << temp << ", ";
    }

}

#include <sstream>

void test_string_learn(){
//    string str = "Hello, I am LiMing.";
//    const char* cstr = str.c_str();
//    cout << cstr << endl;
//    str = "Hello, I am Jenny";
//    cout << cstr << endl;

//    char *cstr = new char[25];
//    string str = "Hello, I am LiMing.";
//    strncpy(cstr, str.c_str(), str.size());
//    cout << cstr << ", " << str.size() << endl;
//    str = "Hello, I am Jenny";
//    cout << cstr << endl;
//    string str = "Hello, I am LiMing.";
//    size_t length;
//    char buf[8];
//    string str("Hello, I am LiMing.");
//    cout << str << endl;
//
//    length = str.copy(buf, 7, 3);
//    cout << "length:" << length << endl;
//    buf[length] = '\0';
//    cout << "str.copy(buf, 7, 5), buf contains:" << buf << endl;
//    cout << "buf len :" << strlen(buf) << endl;
//
//
//    length = str.copy(buf, str.size(), 3);
//    cout << "length:" << length << endl;
//    buf[length] = '\0';
//    cout << "str.copy(buf, str.size(), 5), buf contains:" << buf << endl;
//    cout << "buf len :" << strlen(buf) << endl;
    //int 转 string
    int a_1 = 99;
    string str_1;
    stringstream ss;
    ss << a_1;
    ss >> str_1;
    cout << "a_1:" << a_1 << endl;
    cout << "str_1:" << str_1 << endl;
    //string 转 int
    int a_2;
    string str_2 = "12345";
    ss.clear();//清除ss中的数据
    ss << str_2;
    ss >> a_2;
    cout << "str_2:" << str_2 << endl;
    cout << "a_2:" << a_2 << endl;

    //string 转 int
    string str_3 = "54321";
    int a_3 = stoi(str_3);
    cout << "str_3:" << str_3 << endl;
    cout << "a_3:" << a_3 << endl;

    //int 转 string
    int a_4 = 54321;
    string str_4 = to_string(a_4);
    cout << "a_4:" << a_4 << endl;
    cout << "str_3:" << str_3 << endl;

    double  res = 0;





}


struct TestListNode {
    int val;
    struct TestListNode *next;
    TestListNode(int x) :
            val(x), next(NULL) {
    }
};

TestListNode* reverse_node(TestListNode* pHead){
    if(pHead == NULL){
        return NULL;
    }
    auto pre = pHead;
    pHead = pHead->next;
    pre->next = NULL;
    while(pHead){
        auto temp = pHead;
        pHead = pHead->next;
        temp->next = pre;
        pre = temp;
    }
    return pre;

}

void test_reverse(){
    TestListNode* root = new TestListNode(0);
    TestListNode* n1 = new TestListNode(1);
    TestListNode* n2 = new TestListNode(2);
    TestListNode* n3 = new TestListNode(3);
    TestListNode* n4 = new TestListNode(4);
    TestListNode* n5 = new TestListNode(5);
    root->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    auto res = reverse_node(root);

    while(res){
        cout << res->val << "->";
        res = res->next;
    }
    cout << endl;



}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* newHead = new ListNode(0);
    auto last = newHead;
    while(pHead1 && pHead2){
        if(pHead1->val < pHead2->val){
            auto temp = pHead1;
            pHead1 = pHead1->next;
            last->next = temp;

        }else{
            auto temp = pHead2;
            pHead2 = pHead2->next;
            last->next = temp;
        }
        last = last->next;
        last->next = NULL;
    }

    while(pHead1){
        auto temp = pHead1;
        pHead1 = pHead1->next;
        last->next = temp;
        last = last->next;
        last->next = NULL;
    }
    while(pHead2){
        auto temp = pHead2;
        pHead2 = pHead2->next;
        last->next = temp;
        last = last->next;
        last->next = NULL;
    }
    return newHead->next;
}

void test_Merge(){
    ListNode* root1 = new ListNode(0);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(6);
    ListNode* n4 = new ListNode(8);
    ListNode* n5 = new ListNode(10);
    root1->next = n1;
    n1->next = n2;
    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
    n3->next = NULL;

    ListNode* root2 = new ListNode(1);
    ListNode* n12 = new ListNode(3);
    ListNode* n22 = new ListNode(5);
    ListNode* n32 = new ListNode(7);
    ListNode* n42 = new ListNode(9);
    ListNode* n52 = new ListNode(11);
    root2->next = n12;
    n12->next = n22;
//    n22->next = n32;
//    n32->next = n4;
//    n42->next = n5;
    n22->next = NULL;

    auto res = Merge(root2, NULL);

    while(res){
        cout << res->val << "->";
        res = res->next;
    }
    cout << endl;

}

#include "ThreadDemo/SingleThreadDemo.h"

void test_priority_queue(){
//    vector<Student> v;
//    v.push_back(Student("aaa", 22));
//    v.push_back(Student("abb", 22));
//    v.push_back(Student("aaa", 25));
//    v.push_back(Student("zzz", 22));
//
////    priority_queue<Student, vector<Student>, Comp> p;
//
//    priority_queue<Student> p;
//    p.push(Student("aaa", 22));
//    p.push(Student("abb", 26));
//    p.push(Student("aaa", 25));
//    p.push(Student("qwe", 22));
//
//    while(!p.empty()){
//        Student s = p.top();
//        p.pop();
//        cout << s.show() << endl;
//    }

    priority_queue<int> p;
    for(int i=1; i<8; i++){
        p.push(i);
    }

    while(!p.empty()){
        cout << p.top() << ",";
        p.pop();
    }
}




int FindGreatestSumOfSubArray(const vector<int> &array) {
    vector<int> df(array.size(),0);
    int num_max = array[0];
    df[0] = num_max;
    for(int i=1; i<array.size(); i++){
        if(array[i] > array[i] + df[i-1]){
            df[i] = array[i];
        }else{
            df[i] = df[i-1] + array[i];
        }
        if(num_max < df[i]){
            num_max = df[i];
        }
    }
    return num_max;
}

void test_FindGreatestSumOfSubArray(){
    vector<int> test = {1, -1, 3, 10, -4, 7, 2, -5};
    int res = FindGreatestSumOfSubArray(test);
    cout << "res: " << res << endl;
}

void FindNumsAppearOnce() {
    map<int, int> t_map;
    t_map[2] = 2;
    t_map[4] = 4;
    t_map[6] = 6;

    cout << "key=2, value=" << t_map.at(2) << endl;

    for(auto it : t_map){
        cout << "key:" << it.first << ",value:" << it.second << endl;
    }
    t_map.at(2) += 1;
    cout << "key=8, value=" << t_map[8] << endl;
    for(auto it : t_map){
        cout << "key:" << it.first << ",value:" << it.second << endl;
    }


}

string ReverseSentence() {
    string str = "student. a am I";
    string res = "", tmp = "";
    for(int i=0; i<str.size(); i++){
        if(str[i] != ' '){
            tmp += str[i];
        }else{
            res = " " + tmp + res;
            tmp = "";
        }
    }
    if(tmp.size())
        res = tmp + res;
    return res;
}

ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead == NULL){
        return pHead;
    }
    //删除表头的重复节点
    while(pHead->next != NULL && pHead->val == pHead->next->val){
        pHead = pHead->next->next;
    }
    ListNode* pre = pHead;
    ListNode* current = pHead->next;
    while(current != NULL && current->next != NULL){
        if(current->val == current->next->val){
            pre->next = current->next->next;
            current = pre->next;
        }else{
            pre = pre->next;
            current = current->next;
        }
    }
    return pHead;
}

void test_deleteDuplication(){
    ListNode* phead = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(5);
    phead->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    ListNode* res = deleteDuplication(phead);
    auto temp = res;
    while(temp != NULL){
        cout << temp->val << "->" ;
        temp = temp->next;
    }

}


void maxInWindows()
{
    vector<int> num = {1, 3, -1, -3, 5, 3, 6, 7};
    int size = 3;

    vector<int> res;
    deque<int> dq;
    for(int i = 0; i < num.size(); i++){
        while (!dq.empty() && num[i] > num[dq.back()]){
            dq.pop_back();
        }

        if (!dq.empty() && dq.front() <= i - size){
            dq.pop_front();
        }
        dq.push_back(i);
        if (i + 1 >= size) {
            int tmp = num[dq.front()];
            res.push_back(tmp);
        }
    }
    for(auto item : res){
        cout << item << "->";
    }
    cout << endl;

}

//判断（row， col）坐标是否小于等于K
bool isOK(int row, int col, int target){
    int row_sum = 0;
    while(row != 0){
        int tmp = row % 10;
        row = row / 10;
        row_sum += tmp;
    }
    int col_sum = 0;
    while(col != 0){
        int tmp = col % 10;
        col = col /10;
        col_sum += tmp;
    }
    return row_sum + col_sum <= target;
}

void test_isOK(){
    bool res = isOK(13, 2, 15);
    if(res){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}

int movingCount()
{
    int threshold = 10, rows = 1, cols = 100;
    int res = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
//            cout << "( " << i << ", " << j << " )" << endl;
            if(isOK(i, j, threshold)){
                res++;
                cout << "( " << i << ", " << j << " )" << endl;
            }
        }
    }
    cout << "res:" << res << endl;

    return res;
}
int dim = 2;
void test_ypp_dfs(vector<int> v1, vector<vector<int>> &res, vector<int> cur, vector<bool> visited){
    if(cur.size() == dim){
        res.emplace_back(cur);
        return;
    }else{
        for(int i=0; i<v1.size(); i++){
            if(visited[i] == false){
                visited[i] = true;
                cur.emplace_back(v1[i]);
                test_ypp_dfs(v1, res, cur, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
}
string vec_to_str(vector<int> v){
    string res = "{";
    for(int i=0; i<v.size(); i++){
        res += to_string(v[i]) + ",";
    }
    res = res.substr(0, res.size()-1);
    res += "}";
    return  res;
}
void testpailie(vector<int> v1, vector<int> v2) {
    vector<vector<int>> p1;
    vector<int> cur1;
    vector<bool> visited1(v1.size(),false);
    test_ypp_dfs(v1, p1, cur1, visited1);
    cout << "p1:" << endl;
    for(int i=0; i<p1.size(); i++){
        cout << vec_to_str(p1[i]);
    }
    cout << endl << "-------------p1 end" << endl;
    vector<vector<int>> p2;
    vector<int> cur2;
    vector<bool> visited2(v2.size(),false);
    test_ypp_dfs(v2, p2, cur2, visited2);

    cout << "p2:" << endl;
    for(int i=0; i<p2.size(); i++){
        cout << vec_to_str(p2[i]);
    }
    cout << endl << "-------------p2 end" << endl;

    vector<vector<vector<int>>> res;
    for(int i=0; i<p1.size(); i++){
        for(int j=0; j<p2.size(); j++){
            vector<int> tmp_11 = {p1[i][0], p2[j][0]};
            vector<int> tmp_12 = {p1[i][1], p2[j][1]};
            vector<vector<int>> tmp_1;
            tmp_1.emplace_back(tmp_11);
            tmp_1.emplace_back(tmp_12);
            res.emplace_back(tmp_1);

            vector<int> tmp_21 = {p1[i][0], p2[j][1]};
            vector<int> tmp_22 = {p1[i][1], p2[j][0]};
            vector<vector<int>> tmp_2;
            tmp_2.emplace_back(tmp_21);
            tmp_2.emplace_back(tmp_22);
            res.emplace_back(tmp_2);
        }
    }
    cout << "{";
    for(int i=0; i<res.size(); i++){
        cout << "   {";
        for(int j=0; j<res[0].size(); j++){
            cout << "       {";
            for(int k=0; k<res[0][0].size(); k++){
                cout << res[i][j][k] << ",";
            }
            cout << " }" << endl;
        }
        cout << "       }" << endl;
    }
    cout << "}" << endl;
}

void test_ypp_dfs(vector<int> v1, vector<vector<int>> &res, vector<int> cur, int start, vector<bool> visited){
    if(cur.size() == dim){
        res.emplace_back(cur);
        return;
    }else{
        for(int i=start; i<v1.size(); i++){
            if(visited[i] == false){
                visited[i] = true;
                cur.emplace_back(v1[i]);
                test_ypp_dfs(v1, res, cur, i+1, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
}

void test_yuanpp_2(vector<int> v1, vector<int> v2){

    vector<vector<int>> p1;
    vector<int> cur1;
    vector<bool> visited1(v1.size(),false);
    test_ypp_dfs(v1, p1, cur1, 0, visited1);
    cout << "p1:" << endl;
    for(int i=0; i<p1.size(); i++){
        cout << vec_to_str(p1[i]);
    }
    cout << endl << "-------------p1 end" << endl;

    vector<vector<int>> p2;
    vector<int> cur2;
    vector<bool> visited2(v2.size(),false);
    test_ypp_dfs(v2, p2, cur2, 0, visited2);

    cout << "p2:" << endl;
    for(int i=0; i<p2.size(); i++){
        cout << vec_to_str(p2[i]);
    }
    cout << endl << "-------------p2 end" << endl;

    vector<vector<vector<int>>> res;
    for(int i=0; i<p1.size(); i++){
        for(int j=0; j<p2.size(); j++){
            vector<int> tmp_11 = {p1[i][0], p2[j][0]};
            vector<int> tmp_12 = {p1[i][1], p2[j][1]};
            vector<vector<int>> tmp_1;
            tmp_1.emplace_back(tmp_11);
            tmp_1.emplace_back(tmp_12);
            res.emplace_back(tmp_1);

            vector<int> tmp_21 = {p1[i][0], p2[j][1]};
            vector<int> tmp_22 = {p1[i][1], p2[j][0]};
            vector<vector<int>> tmp_2;
            tmp_2.emplace_back(tmp_21);
            tmp_2.emplace_back(tmp_22);
            res.emplace_back(tmp_2);
        }
    }
    cout << "res : " << endl;
    cout << "{";
    for(int i=0; i<res.size(); i++){
        cout << "{";
        for(int j=0; j<res[0].size(); j++){
            cout << "{";
            for(int k=0; k<res[0][0].size(); k++){
                cout << res[i][j][k] << ",";
            }
            cout << "}" << endl;
        }
        cout << "}" << endl;
    }
    cout << "}" << endl;
}

void test_yuanpp(){
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5};
    test_yuanpp_2(v1, v2);
}

int get_num(){
    return 3;
}
/*
void change_data(char** str){
    str[0] = "wahaha";
    str[1] = "qwer";
}
*/
/*
void test_sec_pointer(){
    vector<string> vec_str = {"hello", "world"};
    cout << "data:" << vec_str[0] << endl;
    char* p[2];
    p[0] = const_cast<char *>(vec_str[0].data());
    p[1] = const_cast<char *>(vec_str[1].data());
    cout << "pointer:" << *p << endl;
    change_data(p);
    cout << "pointer:" << *p << endl;
    cout << "data:" << vec_str[0] << endl;
    cout <<"-------------"<<endl;
    string str = "yuhy";
    char* p_str = const_cast<char *>(str.data());
    cout << "before:" << p_str << endl;
    p_str = "qqqq";
    cout << "after:" << p_str << endl;
    cout << "str:" << str << endl;
}
*/
#include <thread>
#include <condition_variable>
class BlockQueue {
    //BlockQueue(int size): limit_size(size), is_empty(true), is_full(false){
public:
    BlockQueue(int size) : limit_size(size){
    }
    void push(int val) {
        srand(time(NULL));
        this_thread::sleep_for(chrono::milliseconds(1000));
        unique_lock<mutex> ulk(mtx);
        while (buffer.size() >= limit_size) {
            c_full.wait(ulk);
        }
        buffer.push(val);
//        ulk.unlock();
        c_empty.notify_one();
    }
    void pop(int &value) {
        srand(time(NULL));
        this_thread::sleep_for(chrono::milliseconds(1000));
        unique_lock<mutex> ulk(mtx);
        while (buffer.empty())
        {
            c_empty.wait(ulk);
        }
        value = buffer.front();
        buffer.pop();
//        ulk.unlock();
        c_full.notify_one();
    }
private:
    queue<int> buffer;
    const int limit_size;
    mutex mtx;
    //bool is_empty;
    //bool is_full;
    condition_variable c_empty;
    condition_variable c_full;
};
/*
void test_BlockQueue() {
    const int THREAD_NUM = 10;
    BlockQueue bq(3);
    thread t[THREAD_NUM];
    vector<int> final_ret(THREAD_NUM, -1);
    for (int i = 0; i < THREAD_NUM; i++) {
        if(i%2==0)
            t[i] = thread(std::bind(&BlockQueue::push , &bq,  i));
        else {
            t[i] = thread(std::bind(&BlockQueue::pop, &bq,  ref(final_ret[i])));
        }
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        t[i].join();
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        if (i % 2 == 1)
            cout << final_ret[i] << endl;
    }
}
*/
void changeStr(string &res){
    res = "hello";
}
class CBase{
public:
    virtual int test_vir(){return 10;}
    int test(){return 100;}
};

class CDerive : public CBase{
public:
    virtual int test_vir(){return 11;}
    int test(){return 111;}
    string abc(){return "hello";}
};
void static_cast_test(){
    CBase *p_base = new CDerive;
    CDerive *p_derive = dynamic_cast<CDerive *>(p_base);
    cout << "vir:" << p_derive->test_vir() << endl;
    cout << "test:" << p_derive->test() << endl;
    cout << "abc:" << p_derive->abc() << endl;

//    CBase i_base;
//    CBase &r_base = i_base;
//    CDerive &r_d = dynamic_cast<CDerive &>(r_base);
//    cout << r_d.test() << endl;

}
class A_C{

public:
    A_C(){
        num = 0;
    }

public:
    int num;
};
void const_cast_test(){
    const A_C *p = new A_C;
    A_C *p2 = const_cast<A_C *>(p);
    p2->num = 200;
    cout << p->num << ", " << p2->num << endl;

    const int ica = 100;
    int *ia = const_cast<int *>(&ica);
    *ia = 500;
    cout << ica << "," << *ia << endl;

}


//只用递归实现逆序栈的功能

#include <stack>
int getAndRemoveLast(stack<int> &tmp){
    int res = tmp.top();
    tmp.pop();
    if(tmp.empty()){
        return res;
    }else{
        int last = getAndRemoveLast(tmp);
        tmp.push(res);
        return last;
    }
}

void reverse(stack<int > &s){
    if(s.empty()){
        return;
    }
    int i = getAndRemoveLast(s);
    reverse(s);
    s.push(i);
}

void test_reverse_stack(){
    stack<int> tmp;
    tmp.push(1);
    tmp.push(2);
    tmp.push(3);
    tmp.push(4);
    tmp.push(5);
    cout << "------- before -------" << endl;
    reverse(tmp);
    while(!tmp.empty()){
        cout << tmp.top() << endl;
        tmp.pop();
    }
}

//只用递归实现逆序栈的功能---》完成

//猫狗入队
class Pet{
public:
    Pet() = default;
    Pet(string type):type(type){}
    string get_type(){ return type; }
public:
    string type;
};
class Dog : public Pet{
public:
    Dog(){ type = "dog"; }
};
class Cat : public Pet{
public:
    Cat(){ type =  "cat"; }
};
class PetQueue{
private:
    Pet pet;
    long count;//时间戳
public:
    PetQueue(Pet pet, long count):pet(pet), count(count){}
    Pet get_pet(){ return pet; }
    long get_count(){ return count; }
    string get_pet_type(){ return pet.type; }
};
class DogCatQueue{
public:
    queue<PetQueue> dogQ;
    queue<PetQueue> catQ;
    long count;
public:
    DogCatQueue(){ count = 0; }
    void add(Pet pet){
        if(pet.get_type() == "dog"){
            dogQ.push(PetQueue(Dog(),count++));
        }else if(pet.get_type() == "cat"){
            catQ.push(PetQueue(Cat(),count++));
        }else{
            cout << "error , not dog or cat" << endl;
        }
    }
    bool isEmpty(){ return isDogEmpty() || isCatEmpty(); }
    bool isDogEmpty(){return dogQ.empty(); }
    bool isCatEmpty(){ return catQ.empty(); }
    Pet pollAll(){
        if(!dogQ.empty() && !catQ.empty()){
            if(dogQ.front().get_count() < catQ.front().get_count()){
                auto res = dogQ.front().get_pet();
                dogQ.pop();
                return res;
            }else{
                auto res = catQ.front().get_pet();
                catQ.pop();
                return res;
            }
        }else if (!dogQ.empty()){
            auto res = dogQ.front().get_pet();
            dogQ.pop();
            return res;
        }else if(!catQ.empty()){
            auto res = catQ.front().get_pet();
            catQ.pop();
            return res;
        }else{
            throw runtime_error("error, empty queue");
        }
    }
    Dog pollDog(){
        if(!isDogEmpty()){
            //将pet转换成dog
            auto petP = dogQ.front().get_pet();
            dogQ.pop();
            Dog res;
            Pet *p = &res;
            *p = petP;
            return res;
        }else{
            throw runtime_error("error, dog empty queue");
        }
    }
    Cat pollCat(){
        if(!isCatEmpty()){
            //将pet转换成cat
            auto petP = catQ.front().get_pet();
            catQ.pop();
            Cat res;
            Pet *p = &res;
            *p = petP;
            return res;
        }else{
            throw runtime_error("error, cat empty queue");
        }
    }
};
void pet_enter_queue(){
    DogCatQueue cdq;
    if(cdq.isEmpty())
        cout<<"All queue is empty!"<<endl;
    cdq.add(Dog());
    if(!cdq.isDogEmpty())
        cout<<"Dog queue is not empty!"<<endl;
    if(!cdq.isCatEmpty())
        cout<<"Cat queue is not empty!"<<endl;
    for(int i=0;i<2;i++) {
        cdq.add(Cat());
        cdq.add(Dog());
    }
    cout<<"popAll:"<<cdq.pollAll().get_type()<<endl;
    cout<<"popDog:"<<cdq.pollDog().get_type()<<endl;
    cout<<"popCat:"<<cdq.pollCat().get_type()<<endl;
    cout<<"popAll:"<<cdq.pollAll().get_type()<<endl;
    cout<<"popAll:"<<cdq.pollAll().get_type()<<endl;
    if(cdq.isEmpty())
        cout<<"All queue is empty!"<<endl;
}
//猫狗入队---》完成

//用一个栈实现另一个栈的排序

void sort_stack_by_stack(stack<int> &s){
    stack<int> help;
    while(!s.empty()){
        int s_top = s.top();
        s.pop();
        while(!help.empty() && help.top() < s_top){
            s.push(help.top());
            help.pop();
        }
        help.push(s_top);
    }
    while(!help.empty()){
        s.push(help.top());
        help.pop();
    }
}
void test_sort_stack(){
    stack<int> s;
    s.push(4);
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(5);
    sort_stack_by_stack(s);
    cout << "after:";
    while(!s.empty()){
        cout << s.top() <<  "->";
        s.pop();
    }
    cout << endl;
}
//用一个栈实现另一个栈的排序---》完成

class B{
public:
    // 缺省参数和虚函数一起出现，是静态绑定！
    virtual void func(int i = 20){
        cout << "B func()......\n";
        cout << "i=" << i << endl;
    }
};
class C: public B{
public:
    virtual void func(int i=30){
        cout << "C func()......\n";
        cout << "i=" << i << endl;
    }
};
class D:public B{
public:
    virtual void func(int i=40){
        cout << "D func()......\n";
        cout << "i=" << i << endl;
    }
};
void test_param_method(){
    // 缺省参数和虚函数一起出现,是静态绑定！
    D *pD = new D();
    B* pB = pD;
    pD->func();
    pB->func();
}
bool isPrim(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int work(int n, int* a, int aLen) {
    // write code here
    int res = 1;
    for(int i=1; i<aLen; i++){
        int distance = a[i] - a[i-1];
        if(isPrim(distance)){
            res++;
        }else if(distance % 2 ==0 || isPrim(distance - 2)){
            res += 2;
        }else{
            res += 3;
        }
    }
    return res;
}

void test_isPrim(){
    int a[] = {0, 3, 10, 15, 16, 24, 28};
    cout <<"res:" << work(7, a, 7) << endl;
}

class Test_Len{
    char b;
    int a;
    short c;
};

void test_len(){
    cout << "double len :" << sizeof(double) << endl;
    cout << "len:" << sizeof(Test_Len) << endl;
 }
 //----------------------------------------------堆排序--------------------------------------------------------------
//向上调整堆
void shift_up(vector<int> &heap){
    int pos = heap.size() - 1;
    int parent = (pos - 1)/2;
    //当父节点存在时，且父节点的值大于该节点的值，进行调整
    while(parent >= 0 && heap[parent] > heap[pos]){
        swap(heap[parent], heap[pos]);
        pos = parent;
        parent = (pos - 1)/2;
    }
}
//插入堆元素
void push_data(vector<int> &heap, int val){
    heap.push_back(val);
    shift_up(heap);
}
//向下调整堆
void shift_down(vector<int> &heap, int pos) {
    //int pos = 0;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    //当左节点存在且当前元素大于左右子节点中最小元素
    while (left < (int)heap.size()) {
        int min = left;
        //右子树存在
        if (right < (int)heap.size())
            min = heap[left] < heap[right] ? left : right;
        //进行调整
        if (heap[pos] > heap[min]) {
            swap(heap[pos], heap[min]);
            pos = min;
            left = 2 * pos + 1;
            right = 2 * pos + 2;
        }
        else
            break;
    }
}
//删除堆元素
void pop_heap(vector<int> &heap) {
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    shift_down(heap, 0);
}
//建堆
vector<int> make_heap(vector<int> element) {
    //从上向下建堆（插入建堆），其时间复杂度为O(n*logn)
    vector<int> heap;
    /*for (int i = 0; i < element.size(); i++)
           push_heap(heap, element[i]);*/
    //从下向上建堆，从后向前依次调整所有非叶子节点的元素O(n)
    heap = element;
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        shift_down(heap, i);
    }
    return heap;
}
//堆排序
vector<int> heap_sort(vector<int> heap) {
    vector<int> sort_ret;
    while (!heap.empty()) {
        sort_ret.push_back(heap[0]);
        pop_heap(heap);
    }
    return sort_ret;
}

//----------------------------------------------堆排序 end--------------------------------------------------------------



#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef unsigned char     uint8;
typedef unsigned long    uint32;

static uint8 alphabet_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static uint8 reverse_map[] =
        {
                255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 62, 255, 255, 255, 63,
                52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 255, 255, 255, 255, 255, 255,
                255,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
                15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 255, 255, 255, 255, 255,
                255, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 255, 255, 255, 255, 255
        };

uint32 base64_encode(const uint8 *text, uint32 text_len, uint8 *encode)
{
    uint32 i, j;
    for (i = 0, j = 0; i+3 <= text_len; i+=3)
    {
        encode[j++] = alphabet_map[text[i]>>2];                             //取出第一个字符的前6位并找出对应的结果字符
        encode[j++] = alphabet_map[((text[i]<<4)&0x30)|(text[i+1]>>4)];     //将第一个字符的后2位与第二个字符的前4位进行组合并找到对应的结果字符
        encode[j++] = alphabet_map[((text[i+1]<<2)&0x3c)|(text[i+2]>>6)];   //将第二个字符的后4位与第三个字符的前2位组合并找出对应的结果字符
        encode[j++] = alphabet_map[text[i+2]&0x3f];                         //取出第三个字符的后6位并找出结果字符
    }

    if (i < text_len)
    {
        uint32 tail = text_len - i;
        if (tail == 1)
        {
            encode[j++] = alphabet_map[text[i]>>2];
            encode[j++] = alphabet_map[(text[i]<<4)&0x30];
            encode[j++] = '=';
            encode[j++] = '=';
        }
        else //tail==2
        {
            encode[j++] = alphabet_map[text[i]>>2];
            encode[j++] = alphabet_map[((text[i]<<4)&0x30)|(text[i+1]>>4)];
            encode[j++] = alphabet_map[(text[i+1]<<2)&0x3c];
            encode[j++] = '=';
        }
    }
    return j;
}

uint32 base64_decode(const uint8 *code, uint32 code_len, uint8 *plain)
{
    assert((code_len&0x03) == 0);  //如果它的条件返回错误，则终止程序执行。4的倍数。

    uint32 i, j = 0;
    uint8 quad[4];
    for (i = 0; i < code_len; i+=4)
    {
        for (uint32 k = 0; k < 4; k++)
        {
            quad[k] = reverse_map[code[i+k]];//分组，每组四个分别依次转换为base64表内的十进制数
        }

        assert(quad[0]<64 && quad[1]<64);

        plain[j++] = (quad[0]<<2)|(quad[1]>>4); //取出第一个字符对应base64表的十进制数的前6位与第二个字符对应base64表的十进制数的前2位进行组合

        if (quad[2] >= 64)
            break;
        else if (quad[3] >= 64)
        {
            plain[j++] = (quad[1]<<4)|(quad[2]>>2); //取出第二个字符对应base64表的十进制数的后4位与第三个字符对应base64表的十进制数的前4位进行组合
            break;
        }
        else
        {
            plain[j++] = (quad[1]<<4)|(quad[2]>>2);
            plain[j++] = (quad[2]<<6)|quad[3];//取出第三个字符对应base64表的十进制数的后2位与第4个字符进行组合
        }
    }
    return j;
}

//base64 编解码函数声明
std::string b64encodestring(const std::string &strString);      //对 ASCII 字符串进行 base64 编码
std::string b64decodestring(const std::string &strString);      //对 base64 编码后的字符串进行解码

//base64 编解码函数实现
/**
* @brief 对 ASCII 字符串进行 base64 编码
*
* @param strString 待编码的字符串
*
* @return srs::string 返回编码后的字符串
*
* @note 对于字符串中含有非 ASCII 字符串型的字符, 代码将抛出 std::string 型异常, 请捕获
*/
std::string b64encodestring(const std::string &strString)
{
    int nByteSrc = strString.length();
    std::string pszSource = strString;

    int i = 0;
    for(i; i < nByteSrc; i++)
        if( pszSource[i] < 0 || pszSource[i] > 127 )
            throw "can not encode Non-ASCII characters";

    const char *enkey = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string pszEncode(nByteSrc*4/3 + 4, '\0');
    int nLoop = nByteSrc %3 == 0 ? nByteSrc : nByteSrc - 3;
    int n = 0;
    for(i=0; i < nLoop; i+=3 )
    {
        pszEncode[n] = enkey[pszSource[i]>>2];
        pszEncode[n+1] = enkey[((pszSource[i]&3)<<4) | ((pszSource[i+1] & 0xF0)>>4)];
        pszEncode[n+2] = enkey[((pszSource[i+1] & 0x0f)<<2) | ((pszSource[i+2] & 0xc0 )>>6)];
        pszEncode[n+3] = enkey[pszSource[i+2] & 0x3F];
        n += 4;
    }

    switch(nByteSrc%3)
    {
        case 0:
            pszEncode[n] = '\0';
            break;

        case 1:
            pszEncode[n] = enkey[pszSource[i]>>2];
            pszEncode[n+1] = enkey[((pszSource[i]&3)<<4) | ((0&0xf0)>>4)];
            pszEncode[n+2] = '=';
            pszEncode[n+3] = '=';
            pszEncode[n+4] = '\0';
            break;

        case 2:
            pszEncode[n] = enkey[pszSource[i]>>2];
            pszEncode[n+1] = enkey[((pszSource[i]&3)<<4) | ((pszSource[i+1]&0xf0)>>4)];
            pszEncode[n+2] = enkey[(( pszSource[i+1]&0xf)<<2 ) | ((0&0xc0)>>6)];
            pszEncode[n+3] = '=';
            pszEncode[n+4] = '\0';
            break;
    }

    return pszEncode.c_str();
}
/**
* @brief 对 base64 编码后的字符串进行解码
*
* @param strString 待解码的字符串
*
* @return std::string 返回解码后的字符串
*
* @note 对于非base64编码的字符串或已损坏的base64字符串进行解码会抛出 std::string 型异常, 请捕获
*/
std::string b64decodestring(const std::string &strString)
{
    int nByteSrc = strString.length();
    std::string pszSource = strString;

    const int dekey[] = {
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            62, // '+'
            -1, -1, -1,
            63, // '/'
            52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
            -1, -1, -1, -1, -1, -1, -1,
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
            13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
            -1, -1, -1, -1, -1, -1,
            26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
            39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
    };

    if(nByteSrc%4 != 0)
        throw "bad base64 string";

    std::string pszDecode(nByteSrc*3/4+4, '\0');
    int nLoop = pszSource[nByteSrc-1]  == '=' ? nByteSrc - 4 : nByteSrc;
    int b[4];
    int i = 0, n = 0;
    for(i = 0; i < nLoop; i += 4 )
    {
        b[0] = dekey[pszSource[i]];        b[1] = dekey[pszSource[i+1]];
        b[2] = dekey[pszSource[i+2]];    b[3] = dekey[pszSource[i+3]];
        if(b[0] == -1 || b[1] == -1 || b[2] == -1 || b[3] == -1)
            throw "bad base64 string";

        pszDecode[n] = (b[0] << 2) | ((b[1] & 0x30) >> 4);
        pszDecode[n+1] = ((b[1] & 0xf) << 4) | ((b[2] & 0x3c) >> 2);
        pszDecode[n+2] =  ((b[2] & 0x3) << 6) | b[3];

        n+=3;
    }

    if( pszSource[nByteSrc-1] == '=' && pszSource[nByteSrc-2] == '=' )
    {
        b[0] = dekey[pszSource[i]];        b[1] = dekey[pszSource[i+1]];
        if(b[0] == -1 || b[1] == -1)
            throw "bad base64 string";

        pszDecode[n] = (b[0] << 2) | ((b[1] & 0x30) >> 4);
        pszDecode[n+1] = '\0';
    }

    if( pszSource[nByteSrc-1] == '=' && pszSource[nByteSrc-2] != '=' )
    {
        b[0] = dekey[pszSource[i]];        b[1] = dekey[pszSource[i+1]];
        b[2] = dekey[pszSource[i+2]];
        if(b[0] == -1 || b[1] == -1 || b[2] == -1)
            throw "bad base64 string";

        pszDecode[n] = (b[0] << 2) | ((b[1] & 0x30) >> 4);
        pszDecode[n+1] = ((b[1] & 0xf) << 4) | ((b[2] & 0x3c) >> 2);
        pszDecode[n+2] = '\0';
    }

    if( pszSource[nByteSrc-1] != '=' && pszSource[nByteSrc-2] != '=' )
        pszDecode[n] = '\0';

    return pszDecode;
}

void tes_base64(){
    ///编码测试
    std::string str1 = "Hello, world!";
    std::cout << "对Hello, world!进行base64编码: " << b64encodestring(str1) << std::endl;

    ///解码测试
    std::string str2 = "SGVsbG8sIHdvcmxkIQ==";
    std::cout << "对SGVsbG8sIHdvcmxkIQ==进行base64解码: " << b64decodestring(str2) << std::endl;
}

int main(int argc, char *argv[]) {


//    test_isOK();
//    test_len();




    return 0;
}