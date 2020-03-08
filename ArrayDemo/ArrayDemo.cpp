//
// Created by Scott on 2019/11/5.
//

#include "ArrayDemo.h"
#include <iostream>

using namespace std;

void test_array(){
    cout << "This is a test!" << endl;
}

#include <algorithm>
using namespace std;
/*
	NO.27  简单
	给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
	不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
	元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/
int removeElement(vector<int>& nums, int val) {
    return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
}
/*
	使用两个游标i，j，遍历数组，j记录位置，同时递增i，直到下一个非val出现
*/
int removeElement(int A[], int n, int elem) {
    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        if (A[i] == elem)
            continue;
        A[j] = A[i];
        j++;
    }
    return j;
}

/*
	NO.26  简单
	给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
	不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/
int removeDuplicates2(std::vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    else if (nums.size() == 1) {
        return 1;
    }
    else {
        int real = 0;
        for (auto index = nums.begin() + 1; index != nums.end(); index++) {
            if (*index != nums[real]) {
                real++;
                nums[real] = *index;
            }
            else {
                continue;
            }
        }
        return real + 1;
    }

}

/*
	NO.80  中等
	给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
	不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/
int removeDuplicates3(std::vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    else {
        int j = 0;
        int num = 0;
        for (auto index = nums.begin() + 1; index != nums.end(); index++) {
            if (*index == nums[j]) {
                num++;
                if (num < 2) {
                    j++;
                    nums[j] = *index;
                }
            }
            else {
                j++;
                nums[j] = *index;
                num = 0;
            }
        }
        return j + 1;
    }
}


/*
	NO.66   简单  plus one
	给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
	最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
	你可以假设除了整数 0 之外，这个整数不会以零开头。
*/
std::vector<int> plusOne(std::vector<int>& digits) {
    //法一
    /*vector<int> res(digits.size(), 0);
    int carrage = 1;
    for (int index = digits.size() - 1; index >= 0; index--) {
        int sum = carrage + digits[index];
        res[index] = sum % 10;
        carrage = sum / 10;
    }
    if (carrage > 0) {
        res.insert(res.begin(), carrage);
    }
    return res;*/

    for (int index = digits.size() - 1; index >= 0; index--) {
        if (digits[index] == 9) {
            digits[index] = 0;
        }
        else {
            digits[index]++;
            break;
        }
    }
    if (digits[0] == 0) {
        digits.push_back(0);
        digits[0] = 1;
    }
    return digits;
}


/*
	NO.118 杨辉三角 Pascal's Triangle
	在杨辉三角中，每个数是它左上方和右上方的数的和。
*/
std::vector<std::vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int row = 0; row < numRows; row++) {
        vector<int> temp(row + 1, 1);
        for (int i = 1; i < row; i++) {
            temp[i] = res[row - 1][i - 1] + res[row - 1][i];
        }
        res.push_back(temp);
    }
    return res;
}

/*
 * NO.119 杨辉三角2  Pascal's Triangle II
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 */
//std::vector<int> getRow(int rowIndex){
////    vector<int> first(rowIndex + 1, 1);
////    vector<int> second(rowIndex + 1, 1);
////
////    for(int i = 1; i <= rowIndex; i++){
////        for(int j = 1; j < i; j++){
////            first[j] = second[j-1] + second[j];
////        }
////        second = first;
////    }
////
////    return second;
////
////}
std::vector<int> getRow(int rowIndex){
    vector<int> res(rowIndex + 1, 1);
    for(int i = 1; i <= rowIndex; i++){
        //因为只有一个数组，所以只能从后往前计算
        for(int j = i - 1; j >= 1; j--){
            res[j] = res[j] + res[j - 1];
        }
    }
    return res;
}
/*
 * NO.88 合并两个有序数组
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 *
 * 说明:
 *   初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 *   你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    for(int index = m + n - 1; index >= 0; index--){
        if(m == 0){
            for(int j = 0; j < n; j++){
                nums1[j] = nums2[j];
            }
            break;
        }
        if(n == 0){
            break;
        }
        if(nums1[m - 1] > nums2[n - 1]){
            nums1[index] = nums1[m - 1];
            m--;
        }else{
            nums1[index] = nums2[n - 1];
            n--;
        }

    }
}

/*
 * NO.1 两数之和
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 *
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 *
 */
#include <map>
std::vector<int> twoSum(std::vector<int>& nums, int target){
    vector<int> res;
    map<int, int > test_map;
    for(int i = 0; i < nums.size(); i++){
        int other = target - nums[i];
        if(test_map.find(other) != test_map.end()){
//            int index = test_map[other];
//            if(index == i)
//                continue;
            res.push_back(i);
            res.push_back(test_map[other]);
        }else{
            test_map.insert(pair<int, int>(nums[i], i));
        }
    }
    return res;
}

/*
 * NO.15 三数之和
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
 * 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 *
 */
#include <algorithm>
std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
    vector<vector<int>> res;
    if(nums.size() <= 2)
        return res;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size() - 2; i++){
        int target = 0 - nums[i];
        int first = i + 1;
        int last = nums.size() - 1;
        while(first <last){
            int two_sum = nums[first] + nums[last];
            if(two_sum < target){
                first++;
            }else if(two_sum > target){
                last--;
            }else{
                res.push_back(vector<int>{nums[i], nums[first], nums[last]});
                first++;
                last--;
                //是为了跳过重复的结果
                while(first < last && nums[first - 1] == nums[first])
                    first++;
                while(first < last && nums[last + 1] == nums[last])
                    last--;
            }
        }
        //也是为了跳过重复的结果
        while(i < nums.size() - 1&& nums[i] == nums[i + 1])
            i++;
    }
    return res;
}

/*
 *  NO.16 最接近的三数之和
 *  给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
 *  使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 */
#include <math.h>
#include <limits.h>
int threeSumClosest(std::vector<int>& nums, int target){
    int res = 0;
    int distance = INT_MAX;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size() - 2; i++){
        int first = i + 1;
        int last = nums.size() - 1;
        while(first < last){
            int temp_val = nums[i] + nums[first] + nums[last];
            int temp_distance;
            if(temp_val < target){
                temp_distance = fabs(temp_val - target);
                if(temp_distance < distance){
                    distance = temp_distance;
                    res = temp_val;
                }
                first++;
            }else if(temp_val > target){
                temp_distance = fabs(temp_val - target);
                if(temp_distance < distance){
                    distance = temp_distance;
                    res = temp_val;
                }
                last--;
            }else{
                res = temp_val;
                return res;
            }
        }
    }
    return res;
}


/*
 * NO.18 4Sum
 *  给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
 *  使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 */
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target){
    vector<vector<int>> res;
    if(nums.size() < 4)
        return res;
    sort(nums.begin(), nums.end());
    int first = 0;
    while(first < nums.size()-3){
        int second = first + 1;
        while(second < nums.size()-2){
            int rest = target - nums[first] - nums[second];
            int three = second + 1;
            int four = nums.size() - 1;

            while(three < four) {
                if (nums[three] + nums[four] < rest) {
                    three++;
                } else if (nums[three] + nums[four] > rest) {
                    four--;
                } else {
                    res.push_back(vector<int>{nums[first], nums[second], nums[three], nums[four]});
                    three++;
                    four--;
                    //跳过重复步骤
                    while (three < four && nums[three] == nums[three - 1])
                        three++;
                    while (three < four && nums[four] == nums[four + 1])
                        four--;
                }
            }
            second++;
            while(second < nums.size()-2 && nums[second] == nums[second - 1])
                second++;
        }
        first++;
        while(first < nums.size()-3 && nums[first] == nums[first - 1])
            first++;
    }
    return res;
}


/*
 * NO.153 Find Minimum in Rotated Sorted Array  寻找旋转排序数组中的最小值
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 请找出其中最小的元素。你可以假设数组中不存在重复元素。
 *
 */
int findMin(std::vector<int>& nums){

    int length = nums.size();
    if(length == 0)
        return 0;
    else if (length == 1)
        return nums[0];
    else if (length == 2)
        return min(nums[0], nums[1]);
    int left = 0;
    int right = length - 1;
    while(left < right){
        int mid = (left + right)/2;
        if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
            return nums[mid];
        if (nums[mid] > nums[left])
            left = mid;
        else
            right = mid;
    }
    return min(nums[0], nums[length - 1]);
}


/*
 * NO.154 Find Minimum in Rotated Sorted Array2  寻找旋转排序数组中的最小值
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 请找出其中最小的元素。注意数组中可能存在重复的元素。
 */
int findMin2(std::vector<int>& nums){
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while(left < right){
        mid = (left + right)/2;
        if(nums[mid] > nums[right])
            left = mid + 1;
        else if(nums[mid] < nums[right])
            right = mid;
        else
            right = right - 1;
    }
    return nums[left];
}

/*
 * NO.84  Largest Rectangle in Histogram
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 * 思路：
 *      遍历高度，求出每个以bar为高度的最大矩形面积，需要向左右遍历，
 *      找出可以向左右扩展的最大宽度，向左右扩展的时间复杂度为O(n)，
 *      为了降低复杂度，通过使用递增单调栈，这样，这样以栈顶元素的bar为高度的左边界就是本身，
 *      而右边界为第一个小于栈顶的元素。
 *
 */
#include <algorithm>
#include <math.h>
#include <stack>
int largestRectangleArea(std::vector<int>& heights){
    int res = 0;
    stack<int> st ;
    heights.push_back(0);
    int size = heights.size();

    for(int i = 0; i < size; i++ ){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            int h = st.top();
            st.pop();
            res = max(res, heights[h] * (st.empty() ? i : (i - st.top() - 1)));
        }
        st.push(i);
    }
    return res;
}

int largestRectangleArea_byself(std::vector<int>& heights){
    int area = 0;
    heights.push_back(0);
    int length = heights.size();
    for(int i = 0; i < length; i++){
        int left = i, right = i;
        int h = heights[i];
        while(heights[left] >= h && left > 1)
            left--;
        while(heights[right] >= h && right < length - 1)
            right++;
        area = max(area, h * (right - left - 1));
    }
    return area;
}

/*
 * NO.85 Maximal Rectangle 最大矩形
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 */
int maximalRectangle(std::vector<std::vector<char>>& matrix){
    if(matrix.empty() || matrix[0].empty())
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int >> heights(m, vector<int >(n, 0));
    //构造直方图
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == '0')
                heights[i][j] = 0;
            else{
                if(i == 0)
                    heights[i][j] = matrix[i][j];
                else{
                    heights[i][j] = heights[i - 1][j] + 1;
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < m; i++){
        res = max(res, largestRectangleArea(heights[i]));
    }
    return res;
}
//! 动态规划未完成
int maximalRectangle2(std::vector<std::vector<char>>& matrix){
    int res;


    return res;
}


// NO.9 Palindrome Number 回文数
/*
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 */
bool isPalindrome(int x){

    string src = to_string(x);
    int len = src.length();

    for(int i = 0; i < len/2; i++){
        if(src[i] != src[len - 1 - i])
            return false;
    }

    return true;
}

//NO.74 searchMatrix
/*
 *  编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 *  每行中的整数从左到右按升序排列。每行的第一个整数大于前一行的最后一个整数。
 */
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
    if(matrix.empty() || matrix[0].empty())
        return false;
    int m = matrix.size();
    int n = matrix[0].size();
    if(target < matrix[0][0] || target > matrix[m-1][n-1])
        return false;
    int across_left = 0, across_right = m - 1;
    int vertical_left = 0, vertical_right = n - 1;
    int across_mid;
    //首先确定在哪一行上
    while(across_left <= across_right){
        across_mid = (across_left + across_right)/2;
        if(matrix[across_mid][0] > target){
            across_right = across_mid - 1;
        }else if(matrix[across_mid][n-1] < target){
            across_left = across_mid + 1;
        } else{
            break;
        }
    }
    //在该行上进行二叉搜索
    while(vertical_left <= vertical_right){
        int vertical_mid = (vertical_left + vertical_right)/2;
        if(matrix[across_mid][vertical_mid] < target){
            vertical_left = vertical_mid + 1;
        }else if(matrix[across_mid][vertical_mid] > target){
            vertical_right = vertical_mid - 1;
        } else{
            return true;
        }
    }
    return false;
    /*for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            if(target == matrix[m][n])
                return true;

        }

    }*/

}
/*
 * 这题要求在一个排好序可能有重复元素的数组里面找到包含某个值的区间范围。要求使用O(log n)的时间，
 * 所以我们采用两次二分查找。首先二分找到第一个该值出现的位置，譬如m，然后在[m, n)区间内第二次二
 * 分找到最后一个该值出现的位置
 */
//!  leetcode上没有与之对应的题目
//std::vector<int> searchRange(int A[], int n, int target){
//}

/*
 * NO.35 搜索插入位置
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，
 * 返回它将会被按顺序插入的位置。
 * 你可以假设数组中无重复元素。
 */
int searchInsert(std::vector<int>& nums, int target){
    if(nums.empty())
        return 0;
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right)/2;
        if(target > nums[mid]){
            left = mid + 1;
        }else if(target < nums[mid]){
            right = mid - 1;
        }else{
            return mid;
        }
    }
    return left;
}


/**
 * NO.162 寻找峰值
 * 峰值元素是指其值大于左右相邻值的元素。
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 你可以假设 nums[-1] = nums[n] = -∞。
 * @param nums
 * @return
 */
int findPeakElement(std::vector<int>& nums){
    int length = nums.size();
    int left = 0, right = length - 1;
    int mid = 0;
    while(left <= right){
        mid = (left + right)/2;
        if((mid == 0 || nums[mid + 1] < nums[mid]) && (mid == length - 1 || nums[mid] > nums[mid - 1])){
            return mid;
        }else if(mid > 0 && nums[mid - 1] > nums[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return mid;
}


//2019-12-26 37页
//268 missing number
/**
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 示例 1:
 * 输入: [3,0,1]
 * 输出: 2
 *  思路：采用异或的思想，正常情况（不缺失数字的时候），索引和数值应该一一对应，但是少了一个数值。
 * @param nums
 * @return
 */

int missingNumber(std::vector<int>& nums){
    int res = nums.size();
    for(int i = 0;i<nums.size();i++){
        res^=nums[i];
        res^=i;
    }
    return res;
}


bool isPowerOfTwo(int n){
    if (n<=0)
        return false;
    if((n & (n-1)) == 0)
        return true;
    else
        return false;
}


//191  位1的个数
/*
 * 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
 */
int hammingWeight(uint32_t n){
    int num = 0;
    while(true){
        num += n & 1;
        n = n / 2;
        if(n == 0)
            break;
    }
    return num;
}