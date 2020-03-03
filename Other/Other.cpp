//
// Created by Mac on 2020/2/24.
//

#include "Other.h"

#include <map>
#include <iostream>

using namespace std;


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
/*
 * //自己写的 测试样例通过
int lengthOfLongestSubstring(string s){

    int max_len = 0;
    map<char , int> window;
    window.insert(pair<char , int>(s[0], 0));
//    window.insert(pair<string, int>(s[0], 0));

//    for(auto itr = window.begin(); itr != window.end(); itr++){
//        cout << "(" << itr->first << ", " << itr->second << ")" << endl;
//    }

    for(int left = 0, right = 1; left < s.size(), right < s.size(); ){
        //
        while(window.find(s[right]) == window.end() && right<s.size()){
            window.insert(pair<char,int>(s[right], right));
            right++;
            if(max_len < window.size()){
                max_len = window.size();
            }
        }
        while(window.find(s[right]) != window.end() && left<=right){
            window.erase(s[left]);
            left++;
        }
    }
    return max_len;
}
*/
#include <unordered_set>
int lengthOfLongestSubstring(string s) {

    if(s.size() == 0)
        return 0;

    unordered_set<char> window;
    int max_str = 0;
    int left = 0;

    for(int i = 0; i < s.size(); i++){
        while (window.find(s[i]) != window.end()){
            window.erase(s[left]);
            left ++;
        }
        max_str = max(max_str,i-left+1);
        window.insert(s[i]);
    }

    return max_str;

}


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
 *          nums1 = [1, 2]
 *          nums2 = [3, 4]
 *          则中位数是 (2 + 3)/2 = 2.5
 *
 * @param nums1
 * @param nums2
 * @return
 */
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2){
    //nums1.size < nums2.size
    int n = nums1.size();
    int m = nums2.size();
    if(n > m)
        return findMedianSortedArrays(nums2, nums1);

    int l_max_1, l_max_2, r_min_1, r_min_2;
    int c_1, c_2, low = 0, high = 2 * n;

    while(low <= high){

        c_1 = (low + high) / 2;
        c_2 = n + m - c_1;

        l_max_1 = (c_1 == 0) ? INT_MIN : nums1[(c_1 - 1) / 2];
        r_min_1 = (c_1 == 2*n) ? INT_MAX : nums1[c_1 / 2];
        l_max_2 = (c_2 == 0) ? INT_MIN : nums2[(c_2 - 1) / 2];
        r_min_2 = (c_2 == 2*m) ? INT_MAX : nums2[c_2 / 2];

        if(l_max_1 > r_min_2) {
            high = c_1 - 1;
        }else if(l_max_2 > r_min_1){
            low = c_1 + 1;
        }else{
            break;
        }
    }
    return (max(l_max_1, l_max_2) + min(r_min_1, r_min_2)) / 2.0;


}