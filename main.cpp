#include <iostream>
#include <vector>
#include "ArrayDemo/ArrayDemo.h"

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
void test_gcc(){
    cout << "this is a test." << endl;
}
int main() {


    test_gcc();

    return 0;
}