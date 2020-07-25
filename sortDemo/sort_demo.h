//
// Created by Mac on 2020/6/23.
//

#ifndef LEETCODEDEMO_SORT_DEMO_H
#define LEETCODEDEMO_SORT_DEMO_H

#include <vector>
//插入排序
void insert_sort(std::vector<int> &arr);
//简单选择排序
void simple_select_sort(std::vector<int> &arr);
//冒泡排序
void bubble_sort(std::vector<int> &arr);

//快速排序
void quick_sort(std::vector<int> &arr, int left, int right);

//归并排序
void merge_sort(std::vector<int> &arr, int left, int right);

//堆排序
std::vector<int> heap_sort(std::vector<int> &heap);

#endif //LEETCODEDEMO_SORT_DEMO_H
