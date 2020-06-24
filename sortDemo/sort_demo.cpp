//
// Created by Mac on 2020/6/23.
//

#include "sort_demo.h"


using namespace std;
//插入排序 时间复杂度是O（n^2）,稳定
void insert_sort(std::vector<int> &arr){
    for(int i=1; i<arr.size(); i++){
        int flag = arr[i];
        for(int j=i-1; j>=0; j--){
            if(arr[j] > flag){
                arr[j + 1] = arr[j];
                if(j == 0){
                    arr[j] = flag;
                }
            }else{
                arr[j+1] = flag;
                break;
            }
        }
    }
}
//简单选择排序 时间复杂度O(n^2) 不稳定
void simple_select_sort(std::vector<int> &arr){

    int idx_min = 0;
    for(int i=1; i<arr.size(); i++){
        for(int j = i; j< arr.size(); j++){
            if(arr[j] < arr[idx_min]){
                idx_min = j;
            }
        }
        swap(arr[i-1], arr[idx_min]);
    }

}
//冒泡排序
void bubble_sort(std::vector<int> &arr){
    for(int i=0; i<arr.size() - 1; i++){
        for(int j=0; j<arr.size() - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//快速排序
void quick_sort(std::vector<int> &arr);

//归并排序

void merge(std::vector<int> &arr, int left, int mid, int right){
    vector<int> res;
    int pre_right = mid, vin_left = mid+1, pre_left = left, vin_right = right;
    while(pre_left <= pre_right && vin_left <= vin_right){
        if(arr[pre_left] < arr[vin_left]){
            res.emplace_back(arr[pre_left]);
            pre_left++;
        }else{
            res.emplace_back(arr[vin_left]);
            vin_left++;
        }
    }
    while(pre_left <= pre_right){
        res.emplace_back(arr[pre_left]);
        pre_left++;
    }
    while(vin_left <= vin_right){
        res.emplace_back(arr[vin_left]);
        vin_left++;
    }
    for(int i=left, j=0; i<=right; i++,j++){
        arr[i] = res[j];
    }
}

void merge_sort(std::vector<int> &arr, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right)/2;
    //左排序
    merge_sort(arr,left,mid);
    //右排序
    merge_sort(arr,mid + 1, right);
    merge(arr, left, mid, right);
}

//堆排序
void heap_sort(std::vector<int> &arr);