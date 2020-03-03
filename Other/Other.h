//
// Created by Mac on 2020/2/24.
//

#ifndef LEETCODEDEMO_OTHER_H
#define LEETCODEDEMO_OTHER_H

#include <string>

/**
 * problem 3
 *  给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *      如：
 *          输入: "abcabcbb"
 *          输出: 3
 *          解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * @param s
 * @return
 */
int lengthOfLongestSubstring(std::string s);

#include <vector>
/**
 * problem 4
 *  给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 *  请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 *  你可以假设 nums1 和 nums2 不会同时为空。
 *
 *      如：
 *          nums1 = [1, 3]
 *          nums2 = [2]
 *          则中位数是 2.0
 *
 * @param nums1
 * @param nums2
 * @return
 */
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);



#endif //LEETCODEDEMO_OTHER_H
