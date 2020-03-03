//
// Created by Mac on 2020/2/27.
//

#include "DynamicPrograming.h"

#include <vector>
#include <math.h>

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
int maxProfit(std::vector<int>& prices){

    if(prices.size() <= 1){
        return 0;
    }
    int min_price = prices[0];
    int max_profit = prices[1] - min_price;

    for(int i = 2; i < prices.size(); i++){
        min_price = min(prices[i - 1], min_price);
        max_profit = max((prices[i] - min_price), max_profit);
    }

    if(max_profit < 0){
        return 0;
    }

    return max_profit;
}


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
int maxProfit2(std::vector<int>& prices){
    if(prices.size() <= 1){
        return 0;
    }

    int sum = 0;
    for(int i = 1; i < prices.size(); i++){
        if(prices[i] > prices[i - 1]){
            sum += (prices[i] - prices[i - 1]);
        }
    }
    if(sum < 0){
        return 0;
    }
    return sum;
}



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
int maxProfit3(std::vector<int>& prices){
    cout << "prices:";
    for(auto it = prices.begin(); it != prices.end(); it++){
        cout << *it << "," ;
    }
    cout << endl;

    if(prices.size() <= 1){
        return 0;
    }
    //[0 ..... i] prices[i] - min
    vector<int > profit;
    profit.resize(prices.size());
    int min_price = prices[0];
    for(int i = 1; i < prices.size(); i++){
        min_price = min(min_price, prices[i - 1]);
        profit[i] = max(profit[i - 1], (prices[i] - min_price));
    }

    cout << "profit1:";
    for(auto it = profit.begin(); it != profit.end(); it++){
        cout << *it << "," ;
    }
    cout << endl;

    //[i + 1 ....... n] max - prices[j]
    int max_pri_2 = prices[prices.size() - 1];
    int sum = 0;
    for(int j = prices.size() - 2; j >= 0; j--){
        max_pri_2 = max(max_pri_2, prices[j + 1]);
        sum = max(sum, (max_pri_2 - prices[j]));

        if(sum > 0 ){
            profit[j] += sum;
        }
    }
    cout << "profit2:";
    for(auto it = profit.begin(); it != profit.end(); it++){
        cout << *it << "," ;
    }
    cout << endl;
    int res = 0;
    for(int i = 0; i < prices.size(); i++){
        res = max(res, profit[i]);
    }
    return res;

}

/**
 * problem 62
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
    问总共有多少条不同的路径？

 * @param m
 * @param n
 * @return
 */
int uniquePaths(int m, int n){
    int path[m][n];
    for(int i = 0; i < m; i++){
        path[i][0] = 1;
    }
    for(int i = 0; i < n; i++){
        path[0][i] = 1;
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }
    return path[m-1][n-1];

}


/**
 * problem 63
 *  与62一样，只不过obstacleGrid表示由障碍物
 *  1表示有障碍物，0表示无障碍物
 * @param obstacleGrid
 * @return
 */
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int path[m][n];
    path[0][0] = 1;
    for(int i = 1; i < m; i++){
        if(obstacleGrid[i][0] == 0){
            path[i][0] = path[i-1][0];
        }else{
            path[i][0] = 0;
        }

    }
    for(int i = 1; i < n; i++){
        if(obstacleGrid[0][i] == 0){
            path[0][i] = path[0][i-1];
        }else{
            path[0][i] = 0;
        }

    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 1){
                path[i][j] = 0;
            }else{
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }

        }
    }

    return path[m-1][n-1];
}
