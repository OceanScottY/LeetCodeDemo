//
// Created by Mac on 2020/3/30.
//

#include "SingleThreadDemo.h"

#include <thread>
//用于时间延时  获取时间
#include <chrono>

#include <iostream>

using namespace std;

#include <string>

void test_create(string str){

    for(int i=0; i<10; i++){
        //让本线程休眠100毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "sleep for : 100ms, string:" << str << endl;

    }

}


void createThread(){
    thread t1(test_create, "yuhy");
    //阻塞线程，直到t1执行完成
    t1.join();
    cout << " t1 is end" << endl;
}

#include <atomic>
atomic_int a_num(0);

#include <mutex>
int num = 0;
mutex t_lock;


void test_mutex_1(){
    for(int i=0; i<100; i++){
        //此方式需要自行加锁解锁
        t_lock.lock();
        num++;
        t_lock.unlock();

    }
}

void test_mutex_2(){
    for(int i=0; i<100; i++){
        t_lock.lock();
        num++;
        t_lock.unlock();
    }
}
void test_mutex(){
    cout << "before num:" << num << endl;
    //多线程共同访问一块临界区，需要用到互斥量
    thread t1(test_mutex_1);
    thread t2(test_mutex_2);

    t1.join();
    t2.join();

    cout << "after num:" << num << endl;

}
//c++11提供了lock_guard类，利用RAII机制可以保证安全的释放mutex
//在std::lock_guard对象构造时，传入的mutex对象(即它所管理的mutex对象)会被当前线程锁住。
// 在lock_guard对象被析构时，它所管理的mutex对象会自动解锁，
// 不需要程序员手动调用lock和unlock对mutex进行上锁和解锁操作。
// lock_guard对象并不负责管理mutex对象的生命周期，lock_guard对象只是简化了mutex对象的
// 上锁和解锁操作，方便线程对互斥量上锁，即在某个lock_guard对象的生命周期内，
// 它所管理的锁对象会一直保持上锁状态；而lock_guard的生命周期结束之后，
// 它所管理的锁对象会被解锁。程序员可以非常方便地使用lock_guard，而不用担心异常安全问题。
void test_lock_guard_1(){

    lock_guard<mutex> lg(t_lock);
    for(int i=0; i<100; i++){
        num++;
    }
}
void test_lock_guard_2(){
    lock_guard<mutex> lg(t_lock);
    for(int i=0; i<100; i++){
        num++;
    }
}

void test_lock_guard(){
    cout << "before num:" << num << endl;
    //多线程共同访问一块临界区，需要用到互斥量
    thread t1(test_lock_guard_1);
    thread t2(test_lock_guard_2);

    t1.join();
    t2.join();

    cout << "after num:" << num << endl;
}

/**
 * 类 unique_lock 是通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用。
 * unique_lock比lock_guard使用更加灵活，功能更加强大。
 * 使用unique_lock需要付出更多的时间、性能成本。
 *
 */

//!error !todo

std::once_flag flag;
void print_block (int n, char c) {
    //unique_lock有多组构造函数, 这里std::defer_lock不设置锁状态
    std::unique_lock<std::mutex> my_lock (t_lock, std::defer_lock);
    //尝试加锁, 如果加锁成功则执行
    //(适合定时执行一个job的场景, 一个线程执行就可以, 可以用更新时间戳辅助)
    if(my_lock.try_lock()){
        for (int i=0; i<n; ++i)
            std::cout << c;
        std::cout << '\n';
    }
}

void run_one(int &n){
    std::call_once(flag, [&n]{n=n+1;}); //只执行一次, 适合延迟加载; 多线程static变量情况
}

#include <vector>
void test_unique_guard(){
    std::vector<std::thread> ver;
    int num = 0;
    for (auto i = 0; i < 10; ++i){
        //emplace_back比push_back更好 是c++11增加的
        ver.emplace_back(print_block,10,'*');
        ver.emplace_back(run_one, std::ref(num));
    }

    for (auto &t : ver){
        t.join();
    }
    std::cout << num << std::endl;
//    return 0;
}


//条件变量

#include <condition_variable>

/**
 * std::condition_variable 是为了解决死锁而生的。当互斥操作不够用而引入的。
 * 比如，线程可能需要等待某个条件为真才能继续执行，而一个忙等待循环中可能会导致所有其他线程都无法进入
 * 临界区使得条件为真时，就会发生死锁。
 * 所以，condition_variable实例被创建出现主要就是用于唤醒等待线程从而避免死锁。
 * std::condition_variable的 notify_one()用于唤醒一个线程；notify_all() 则是通知所有线程。
 *
 * C++11中的std::condition_variable就像Linux下使用pthread_cond_wait和pthread_cond_signal一样，
 * 可以让线程休眠，直到别唤醒，现在在从新执行。线程等待在多线程编程中使用非常频繁，
 * 经常需要等待一些异步执行的条件的返回结果。
 *
 */

mutex con_mutex;
condition_variable con_cv;
bool g_ready = false;

void dispaly_id(int id)
{
    std::unique_lock<std::mutex> lck(con_mutex);
//    con_cv.wait(lck, []() {return g_ready; });   //线程阻塞，直到第二个参数返回值为真

    con_cv.wait(lck);

    std::cout << "id:" << id << std::endl;
}

void ready()
{
    std::unique_lock<std::mutex> lck(con_mutex);
//    g_ready = true;
    con_cv.notify_all();    //唤醒所有的等待线程
}


void test_condition(){

    std::thread t[8];
    for (int i = 0; i < 8; i++)
    {
        t[i] = std::thread(dispaly_id, i);
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "all thread lock......" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    ready();
    for (auto & th : t) th.join();

//    system("pause");

}



//3、原子变量的使用


atomic_int atomic_num(0);

void atomic_thread(){
    for(int i=0; i<100; i++){
        atomic_num++;
    }
}


void test_atomic(){
    cout << "befor, num:" << atomic_num << endl;

    thread t1(atomic_thread);
    thread t2(atomic_thread);


    t1.join();
    t2.join();

    cout << "befor, num:" << atomic_num << endl;

}

#include <functional>

#include <future>

void test_pro(promise<string> &p){
    this_thread::sleep_for(chrono::milliseconds(2000));
    //传值
    p.set_value("hello, this is my value");
}
void test_future(){

    promise<string> pro;

    thread t1(test_pro, ref(pro));
    cout << "thread1 is running;" << endl;
    //promise和future进行绑定
    future<string> f = pro.get_future();
    //从future中获取值，在p.set_value()之后就可以获取值了
    auto res = f.get();

    cout << "res : " << res << endl;
}

int addOne(int x){
    return x + 1;
}

void test_package_task(){
    packaged_task<int(int)> pt1(addOne);
    future<int> fu1 = pt1.get_future();

    //声明一个变量
    int c = 0;

    //创建一个线程t1，将pt1及对应的参数放到线程里面执行
    std::thread t1(std::move(pt1), c);

    //阻塞至线程t1结束(函数addOne返回结果)
    int iResult = fu1.get();

    std::cout << "执行结果：" << iResult << std::endl;	//执行结果：1
    std::cout << "c：" << c << std::endl;	//c：0
}



void test_async(){
    //策略1
    std::future<int> fut = std::async(std::launch::async, []() {
        cout<<" 开始执行async" << endl;
        return 1;
    });

    //策略2
    std::future<int> fut2 = std::async(std::launch::deferred, []() {
        cout<<" 开始执行deferred" << endl;

        return 2;
    });

    std::cout << "result:" << fut.get() << std::endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    std::cout << "result:" << fut2.get() << std::endl;
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

void dfs(TreeNode* node,vector<vector<int>> &res, vector<int> cur, int num){
    if(node->left == NULL && node->right == NULL){
        if(num == node->val){
            res.emplace_back(cur);
        }
        return;
    }else{
        num -= node->val;
        cur.emplace_back(node->val);
        if(node->left != NULL)
            dfs(node->left, res, cur, num);
        if(node->right != NULL)
            dfs(node->right, res, cur, num);
    }

}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }
    vector<int> current;
    dfs(root, res, current, expectNumber);
    return res;
}

void test_findPath(){
    TreeNode* root = new TreeNode(10);
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(12);
    TreeNode* n3 = new TreeNode(4);
    TreeNode* n4 = new TreeNode(7);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    auto res = FindPath(root, 22);
    for(auto v1 : res){
        cout << "{";
        for(auto v2 : v1){
            cout << v2 << ",";
        }
        cout << "}" << endl;
    }
}

void test_wait_for(){
    std::future<int> future = std::async(std::launch::async, [](){
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return 6;
    });

    std::cout << "waiting...\n";
    std::future_status status;
    do {
        cout << "check status." << endl;
        status = future.wait_for(std::chrono::seconds(1));
        switch (status){
            case std::future_status::deferred :
                std::cout << "deferred\n";
                break;
            case std::future_status::timeout:
                std::cout << "timeout\n";
                break;
            case std::future_status::ready:
                std::cout << "ready!\n";
                break;
        }
    } while (status != std::future_status::ready);

    std::cout << "result is " << future.get() << '\n';
}
