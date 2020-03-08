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


/*********************************** 2020-03-03 start ***********************************/

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
    long long path[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            path[i][j] = 0;
        }
    }
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


/**
 * problem 64 最小路径和
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，
 * 使得路径上的数字总和为最小。说明：每次只能向下或者向右移动一步。
 *
 *
 * @param grid
 * @return
 */
int minPathSum(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    for(int i=1; i<m; i++){
        grid[i][0] = grid[i-1][0] + grid[i][0];
    }
    for(int i=1; i<n; i++){
        grid[0][i] = grid[0][i-1] + grid[0][i];
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
        }
    }
    return grid[m-1][n-1];
}

/**
 * problem 53 最大子序和
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * @param nums
 * @return
 */
int maxSubArray(vector<int>& nums){

    int res = nums[0];
    int dp = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(dp > 0){
            dp += nums[i];
        }else{
            dp = nums[i];
        }
        res = max(dp,res);
    }
    return res;
}

/**
 * problem 153 乘积最大子序列和
 * 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 * @param nums
 * @return
 */
int maxProduct(vector<int>& nums){
    int res = nums[0];
    int dp_max = nums[0];
    int dp_min = nums[0];

    for(int i=1; i<nums.size(); i++){
        if(nums[i] < 0){
            int temp = dp_max;
            dp_max = dp_min;
            dp_min = temp;
        }
        dp_min = min(nums[i], dp_min * nums[i]);
        dp_max = max(nums[i],dp_max * nums[i]);

        res = max(res, dp_max);
    }
    return res;
}


/**
 * problem 70 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * @param n
 * @return
 */
int climbStairs(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    int current = 0;
    int pre_pre = 1;
    int pre = 2;
    for(int i=2; i<n; i++){
        current = pre + pre_pre;
        pre_pre = pre;
        pre = current;
    }
    return current;
}

/**
 * problem 120 三角形最小路径和
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * @param triangle
 * @return
 */
int minimumTotal(std::vector<std::vector<int>>& triangle){
    int m = triangle.size();
    int dp[triangle[m-1].size()];
    for(int i=0; i< triangle[m-1].size(); i++){
        dp[i] = triangle[m-1][i];
    }

    for(int i = triangle.size()-2; i >= 0; i--){
        int n = triangle[i].size();
        for(int j =0; j <n; j++){
            dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
        }
    }
    return dp[0];


}


/**
 * problem 96 不同的二叉搜索树
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * @param n
 * @return
 */
int numTrees(int n){
    vector<int> dp(n,0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i - j -1];
        }
    }

    return dp[n];
}



vector<TreeNode*> generate(int start, int stop){

    vector<TreeNode*> vs;
    if(start > stop){
        vs.push_back(NULL);
        return vs;
    }

    for(int i=start; i<=stop; i++){

        auto left = generate(start, i-1);
        auto right = generate(i+1, stop);

        for(int j=0; j<left.size(); j++){
            for(int k=0; k<right.size(); k++){

                TreeNode *temp = new TreeNode(i);
                temp->left = left[j];
                temp->right = right[k];
                vs.push_back(temp);
            }
        }
    }
    return vs;

}
/**
 * problem 95
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * @param n
 * @return
 */
vector<TreeNode*> generateTrees(int n){
    return generate(1,n);
}


/**
 * problem 279
 * 给出一个正整数n，求至少需要多少个完全平方数相加得到n，
 * 例如： 给出n=12，返回3，因为12 = 4 + 4 + 4
 * @return
 */
int numSquars(int n){
    vector<int> dp(13,INT_MAX);
    dp[0] = 0;
    for(int i=0; i<= n; i++){
        for(int j=1; i + j*j <n; j++){
            dp[i + j*j] = min(dp[i + j*j], dp[i]+1);
        }
    }
    return dp[n];
}

int global_int = 24;
void test_extern(){
    cout << "test extern" << endl;
}
/*********************************** 2020-03-03 end ************************************/


