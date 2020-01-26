//
// Created by Scott on 2019/11/5.
//

#ifndef LEETCODEDEMO_ARRAYDEMO_H
#define LEETCODEDEMO_ARRAYDEMO_H

void test_array();

#include<vector>

//2019-11-05

//NO.27
//! easy
int removeElement(std::vector<int>& nums, int val);
//原来的题目是
int removeElement(int A[], int n, int elem);

//NO.26
//! easy
int removeDuplicates1(std::vector<int>& nums);

//NO.80
//! midium
int removeDuplicates2(std::vector<int>& nums);

//2019-11-06
//NO.66 plus one
//! easy
std::vector<int> plusOne(std::vector<int>& digits);

//NO.118 杨辉三角 Pascal's Triangle
//! easy
std::vector<std::vector<int>> generate(int numRows);

//NO.119 杨辉三角2  Pascal's Triangle II
//! easy
std::vector<int> getRow(int rowIndex);


//NO.88 合并两个有序数组
//! easy
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);

//2019-11-07

//NO.1  两数之和
//! easy
std::vector<int> twoSum(std::vector<int>& nums, int target);

//NO.15 三数之和
//! midium
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

//NO.16 最接近的三数之和
//! midium
int threeSumClosest(std::vector<int>& nums, int target);


//2019-11-08  leetcode-solution  18页
//NO.18 4Sum
//! midium
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);

//NO.153 Find Minimum in Rotated Sorted Array  寻找旋转排序数组中的最小值
//! midium
int findMin(std::vector<int>& nums);

//2019-11-09 leetcode-solution  25页
//NO.154 Find Minimum in Rotated Sorted Array2  寻找旋转排序数组中的最小值
//! hard
int findMin2(std::vector<int>& nums);


//2019-11-12 leetcode-solution  27页
//NO.84  Largest Rectangle in Histogram
//! hard
int largestRectangleArea(std::vector<int>& heights);


//NO.85 Maximal Rectangle 最大矩形
int maximalRectangle(std::vector<std::vector<char>>& matrix);
//! 可以使用动态规划，但是此处未做
int maximalRectangle2(std::vector<std::vector<char>>& matrix);

//2019-11-18 leetcode-solution  29页
// NO.9 Palindrome Number 回文数
bool isPalindrome(int x);

//NO.74 searchMatrix
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);

//Search for a Range
std::vector<int> searchRange(int A[], int n, int target);

//2019-12-3 leetcode-solution  35页
//NO.35 Search Insert Position
int findPeakElement(std::vector<int>& nums);


//2019-12-26 37页
//268 missing number
int missingNumber(std::vector<int>& nums);


//231  给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
bool isPowerOfTwo(int n);

#include <stdio.h>
//typedef unsigned __int32 uint32_t;
//191  位1的个数
//int hammingWeight(uint32_t n);

#endif //LEETCODEDEMO_ARRAYDEMO_H
