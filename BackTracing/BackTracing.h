//
// Created by Mac on 2020/3/6.
//

#ifndef LEETCODEDEMO_BACKTRACING_H
#define LEETCODEDEMO_BACKTRACING_H

#include <iostream>
#include <vector>
//DFS + BackTracing

/***************************** 2020-03-06 start ******************************/
/**
 * problem 77 组合
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 例：
 *  输入: n = 4, k = 2
    输出:
    [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
    ]
 * @param n
 * @param k
 * @return
 */
std::vector<std::vector<int>> combine(int n, int k);


/**
 * problem 39 组合总和
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，
 * 找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的数字可以无限制重复被选取。
 *  说明：
        所有数字（包括 target）都是正整数。
        解集不能包含重复的组合。

   例：
       输入: candidates = [2,3,6,7], target = 7,
       所求解集为:
        [
          [7],
          [2,2,3]
        ]
 *
 * @param candidates
 * @param target
 * @return
 */
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);

/***************************** 2020-03-07 start ******************************/

/**
 *
 * problem 40 组合2
 * 给定一个数组 candidates 和一个目标数 target ，
 * 找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用一次。
 *
 *
 *
 * @param candidates
 * @param target
 * @return
 */
std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);



/**
 * problem 17 电话号码的字母组合
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 * @param digits
 * @return
 */
std::vector<std::string> letterCombinations(std::string digits);

/**
 * problem 78 子集
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 *
 *  输入: nums = [1,2,3]
    输出:
    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]
 *
 *
 * @param nums
 * @return
 */
std::vector<std::vector<int>> subsets(std::vector<int>& nums);


/**
 * problem 90 子集2
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 说明：解集不能包含重复的子集。
 *
 *      输入: [1,2,2]
        输出:
        [
          [2],
          [1],
          [1,2,2],
          [2,2],
          [1,2],
          []
        ]
 * @param nums
 * @return
 */
std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums);


/************************************  2020-03-08 start ************************************/

/**
 * problem 46 全排列
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 *      输入: [1,2,3]
        输出:
        [
          [1,2,3],
          [1,3,2],
          [2,1,3],
          [2,3,1],
          [3,1,2],
          [3,2,1]
        ]
 * @param nums
 * @return
 */
std::vector<std::vector<int>> permute(std::vector<int>& nums);

/**
 * problem 47 全排列2
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 *      输入: [1,1,2]
        输出:
        [
          [1,1,2],
          [1,2,1],
          [2,1,1]
        ]
 * @param nums
 * @return
 */
std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums);

#endif //LEETCODEDEMO_BACKTRACING_H
