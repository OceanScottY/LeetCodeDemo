//
// Created by Mac on 2020/2/27.
//

#ifndef LEETCODEDEMO_DYNAMICPROGRAMING_H
#define LEETCODEDEMO_DYNAMICPROGRAMING_H

#include "../TreeDemo/TreeDemo.h"
#include <iostream>
#include <vector>
using namespace std;

extern int global_int;
void test_extern();
//int global_int = 24;
/**
 * problem 121 买卖股票的最佳时机
 *
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 * 注意你不能在买入股票前卖出股票。
 *
 *          输入: [7,1,5,3,6,4]
 *          输出: 5
 *          解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 *          注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 *
 * @param prices
 * @return
 */
int maxProfit(std::vector<int>& prices);

/**
 * problem 122 买卖股票的最佳时机2
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *      输入: [7,1,5,3,6,4]
 *      输出: 7
 *      解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出,
 *                      这笔交易所能获得利润 = 5-1 = 4 。
 *          随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出,
 *                      这笔交易所能获得利润 = 6-3 = 3 。
 *
 * @param prices
 * @return
 */
int maxProfit2(std::vector<int>& prices);



/**
 * problem 123 买卖股票的最佳时机3
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *      输入: [3,3,5,0,0,3,1,4]
        输出: 6
        解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
             随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

 * @param prices
 * @return
 */
int maxProfit3(std::vector<int>& prices);


/*********************************** 2020-03-03 start ****************************************/

/**
 * problem 62
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
    问总共有多少条不同的路径？



 * @param m
 * @param n
 * @return
 */
int uniquePaths(int m, int n);

/**
 * problem 63
 *  与62一样，只不过obstacleGrid表示由障碍物
 *  1表示有障碍物，0表示无障碍物
 * @param obstacleGrid
 * @return
 */
int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);

/**
 * problem 64 最小路径和
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，
 * 使得路径上的数字总和为最小。说明：每次只能向下或者向右移动一步。
 *
 *
 * @param grid
 * @return
 */
int minPathSum(std::vector<std::vector<int>>& grid);



/**
 * problem 53 最大子序和
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * @param nums
 * @return
 */
int maxSubArray(std::vector<int>& nums);

/**
 * problem 153 乘积最大子序列和
 * 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 * @param nums
 * @return
 */
int maxProduct(std::vector<int>& nums);

/**
 * problem 70 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * @param n
 * @return
 */
int climbStairs(int n);

/**
 * problem 120 三角形最小路径和
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * @param triangle
 * @return
 */
int minimumTotal(std::vector<std::vector<int>>& triangle);

/**
 * problem 96 不同的二叉搜索树
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * @param n
 * @return
 */
int numTrees(int n);
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

/**
 * problem 95
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * @param n
 * @return
 */
vector<TreeNode*> generateTrees(int n);

/**
 * problem 279
 * 给出一个正整数n，求至少需要多少个完全平方数相加得到n，
 * 例如： 给出n=12，返回3，因为12 = 4 + 4 + 4
 * @return
 */
int numSquars(int n);

/*********************************** 2020-03-03 end ****************************************/



#endif //LEETCODEDEMO_DYNAMICPROGRAMING_H
