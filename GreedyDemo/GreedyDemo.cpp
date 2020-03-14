//
// Created by Mac on 2020/3/8.
//

#include "GreedyDemo.h"


using namespace std;

/**
 * problem 55 跳跃游戏
 *  给定一个非负整数数组，你最初位于数组的第一个位置。
 *  数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *  判断你是否能够到达最后一个位置。
 *
 *      输入: [2,3,1,1,4]
        输出:  true
        解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

 * @param nums
 * @return
 */
bool canJump(std::vector<int>& nums){
    if(nums.size() == 0){
        return false;
    }

    int step = nums[0];
    for(int i = 1; i < nums.size(); i++){
        step--;
        if(step < 0){
            return false;
        }
        if(step < nums[i]){
            step = nums[i];
        }
    }
    return true;
}

/**
 * problem 56 跳跃游戏2
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 *
 *      输入: [2,3,1,1,4]
        输出: 2
        解释: 跳到最后一个位置的最小跳跃数是 2。
             从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。


       维护两个变量，当前能到达的最远点p，以及下一次能到达最远点q
       在p的范围内迭代计算q，然后更新步数并将最大的q设置成p。


 * @param nums
 * @return
 */
int jump(std::vector<int>& nums){
    int step = 0;
    int cur = 0;
    int next = 0;

    int i = 0;
    int len = nums.size();
    while(i < len){
        if(cur >= len - 1){
            break;
        }

        while(i <= cur){
            //更新最远到达点
            next = max(next, nums[i] + i);
            i++;
        }
        step++;
        cur = next;
    }

    return step;
}



/**
 * problem 134 加油站
 *
 *  在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 *  你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
 *  你从其中的一个加油站出发，开始时油箱为空。如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

    说明: 
        如果题目有解，该答案即为唯一答案。
        输入数组均为非空数组，且长度相同。
        输入数组中的元素均为非负数。
    输入:
        gas  = [1,2,3,4,5]
        cost = [3,4,5,1,2]

    输出: 3

    解释:
        从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
        开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
        开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
        开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
        开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
        开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
        因此，3 可为起始索引。

 * @param gas
 * @param cost
 * @return
 */
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost){

    int cur = 0;
    int step = 0;

    for(int i=0; i<gas.size(); i++){
        int temp_i = i;
        while(step < gas.size()-1){
            cur = cur + gas[temp_i] - cost[temp_i];
            if(cur < 0){
                cur = 0;
                break;
            }
            step++;
            temp_i = (temp_i + 1)%gas.size();
            if(step >= gas.size() && cur >= 0){
                return i;
            }
        }

    }
    return -1;
}


/**
 * problem 135 糖果
 *  老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 *  你需要按照以下要求，帮助老师给这些孩子分发糖果：
 *  每个孩子至少分配到 1 个糖果。
 *  相邻的孩子中，评分高的孩子必须获得更多的糖果。
 *  那么这样下来，老师至少需要准备多少颗糖果呢？
 *
 *  输入: [1,0,2]
    输出: 5
    解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 *
 * @param ratings
 * @return
 */
int candy(std::vector<int>& ratings){
    vector<int> candy(ratings.size(),1);

    for(int i = 1; i < ratings.size(); i++){
        if(ratings[i] > ratings[i-1]){
            candy[i] = candy[i-1] + 1;
        }
    }

    for(int i = ratings.size()-2; i >= 0; i--){
        if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]){
            candy[i] = candy[i+1] + 1;
        }
    }

    int res = 0;
    for(int i = 0; i < candy.size(); i++){
        res += candy[i];
    }
    return res;
}






