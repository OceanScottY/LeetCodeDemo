//
// Created by Mac on 2020/3/6.
//

#include "BackTracing.h"

using namespace std;
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

void DFS(vector<vector<int>> &res, vector<int> cur, int n, int k, int level){
    if(cur.size() == k){
        res.push_back(cur);
        return;
    }

    if(cur.size() > k){
        return;
    }

    for(int i = level; i <= n; i++){
        cur.push_back(i);
        DFS(res, cur, n, k, i+1);
        cur.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k){

    vector<vector<int>> res;

    if(k > n || n <= 0)
        return res;
    vector<int> cur;
    DFS(res, cur, n, k, 1);
    return res;

}


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
#include <algorithm>

void DFS_sum(std::vector<int> candidates, vector<vector<int>> &res, vector<int> cur, int target, int level){
    if(target == 0){
        res.push_back(cur);
        return;
    }else if(target < 0){
        return;
    }else{
        for(int i = level; i < candidates.size(); i++){
            if(target < candidates[i])
                break;
            cur.push_back(candidates[i]);

            DFS_sum(candidates, res, cur, target - candidates[i], i);

            cur.pop_back();
        }
    }

}
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target){
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());

    vector<int> cur;
    DFS_sum(candidates, res, cur, target, 0);
    return res;
}



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

void DFS_com2(vector<int>& candidates,vector<vector<int>> &res, vector<int> cur, int target, int start){
    if(target == 0){
        res.push_back(cur);
        return;

    }else if(target < 0){
        return;
    }else{
        for(int i = start; i < candidates.size(); i++){
            cur.push_back(candidates[i]);
            DFS_com2(candidates, res, cur, target - candidates[i], i + 1);
            cur.pop_back();
            //******去重*******
            while(i < candidates.size() - 1 && candidates[i] == candidates[i+1])
                ++i;
        }
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target){
    vector<vector<int>> res;

    if(candidates.size() == 0)
        return res;
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    DFS_com2(candidates, res, cur, target, 0);
    return res;
}




/**
 * problem 17 电话号码的字母组合
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 * @param digits
 * @return
 */

void combination_phone(vector<string> &res, string tmp, string digits, vector<string> dic, int level){
    if(level == digits.size()){
        res.push_back(tmp);
        return;
    }
    int index = digits[level] - '0';
    for(int i =0; i < dic[index].size(); i++){
        tmp.push_back(dic[index][i]);
        combination_phone(res, tmp, digits, dic, level+1);
        tmp.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits){
    vector<string> res;
    vector<string> dic;
    dic.push_back(" ");
    dic.push_back(" ");
    dic.push_back("abc");
    dic.push_back("def");
    dic.push_back("ghi");
    dic.push_back("jkl");
    dic.push_back("mno");
    dic.push_back("pqrs");
    dic.push_back("tuv");
    dic.push_back("wxyz");
    string tmp;
    combination_phone(res, tmp, digits, dic, 0);
    return res;

}


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

void subset_of_nums(vector<int> nums, vector<vector<int>> &res, vector<int> cur, int start){


    for(int i = start; i < nums.size(); i++){
        cur.push_back(nums[i]);
        res.push_back(cur);
        subset_of_nums(nums, res, cur, i+1);
        cur.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums){
    vector<vector<int>> res;
    if(nums.size() == 0){
        return res;
    }

    vector<int> cur;
    res.push_back(cur);
    subset_of_nums(nums, res, cur, 0);
}




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
void subsets_with_dup(vector<int> nums, vector<vector<int>> &res, vector<int> cur, int start){
    if(start >= nums.size()){
        return;
    }
    for(int i=start; i<nums.size(); i++){
        cur.push_back(nums[i]);
        res.push_back(cur);
        subsets_with_dup(nums, res, cur, i+1);
        cur.pop_back();
        while(i < nums.size()-1 && nums[i] == nums[i+1])
            ++i;
    }
}
std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums){
    vector<vector<int>> res;
    if(nums.size() == 0){
        return res;
    }
    vector<int> cur;
    res.push_back(cur);
    sort(nums.begin(), nums.end());
    subsets_with_dup(nums, res, cur, 0);
    return res;
}



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

void dfs_permute(vector<int> nums, vector<vector<int>> &res, vector<int> cur, vector<bool> visited){
    if(cur.size() == nums.size()){
        res.push_back(cur);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(visited[i] == false){
            cur.push_back(nums[i]);
            visited[i] = true;
            dfs_permute(nums, res, cur, visited);
            visited[i] = false;
            cur.pop_back();
        }
    }

}
std::vector<std::vector<int>> permute(std::vector<int>& nums){
    vector<vector<int>> res;
    if(nums.size() == 0)
        return res;

    vector<int> cur;
    vector<bool> visited(nums.size(), false);
    dfs_permute(nums, res, cur, visited);
    return res;
}


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
void dfsPermuteUnique(vector<int> nums, vector<vector<int>> &res, vector<int> cur, vector<bool> visited){
    if(nums.size() == cur.size()){
        res.push_back(cur);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(!visited[i]){
            cur.push_back(nums[i]);
            visited[i] = true;
            dfsPermuteUnique(nums, res, cur, visited);
            visited[i] = false;
            cur.pop_back();
            while(i < nums.size() - 1 && nums[i] == nums[i+1]){
                ++i;
            }
        }
    }
}
std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums){
    vector<vector<int>> res;
    if(nums.size() == 0){
        return res;
    }
    sort(nums.begin(), nums.end());
    vector<int> cur;
    vector<bool> visited(nums.size(), false);
    dfsPermuteUnique(nums, res, cur, visited);
    return res;

}



