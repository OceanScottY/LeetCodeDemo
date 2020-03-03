//
// Created by Mac on 2020/2/27.
//

#ifndef LEETCODEDEMO_DYNAMICPROGRAMING_H
#define LEETCODEDEMO_DYNAMICPROGRAMING_H

#include <iostream>

using namespace std;



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
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

#endif //LEETCODEDEMO_DYNAMICPROGRAMING_H
