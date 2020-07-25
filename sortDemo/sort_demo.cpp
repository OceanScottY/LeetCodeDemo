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

void quick_sort(std::vector<int> &arr, int left, int right){
    if(left >= right){
        return;
    }
    int i = left, j = right;
    int flag = arr[left];
    while(i < j){
        //为了防止越界，必须有i<j的判断
        while(i<j && arr[j] >= flag){
            j--;
        }
        arr[i] = arr[j];
        while(i<j && arr[i] <= flag){
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = flag;
    quick_sort(arr, left, i-1);
    quick_sort(arr, i+1, right);
}

//归并排序

void merge(std::vector<int> &arr, int left, int mid, int right){
    vector<int> res;
    int pre_right = mid, vin_left = mid+1;
    int pre_left = left, vin_right = right;
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

//-----------------------------堆排序 start---------------------------
//向上调整堆 将最后一个元素调整到合适的位置
void  shift_up(vector<int> &heap){
    int pos = heap.size()-1, parent = (pos - 1)/2;
    while(parent >= 0 && heap[pos] < heap[parent]){
        swap(heap[pos], heap[parent]);
        pos = parent, parent = (pos - 1)/2;
    }
};
//插入元素
void push_heap(vector<int> &heap, int val){
    heap.push_back(val);
    shift_up(heap);
}

//向下调整堆
void shift_down(vector<int> &heap, int pos){
    int left = 2 * pos + 1;
    int right = 2 * pos +2;
    while(left < (int)heap.size()-1){
        int min = left;
        if(right < (int)heap.size()){
            min = heap[left] < heap[right] ? left : right;
        }
        //进行调整
        if(heap[pos] > heap[min]){
            swap(heap[pos], heap[min]);
            pos = min, left = 2*pos+1, right = 2*pos + 2;
        }else{
            break;
        }
    }
}

void pop_heap(vector<int> &heap){
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    shift_down(heap, 0);
}

vector<int> make_heap(vector<int> ele){
    //从上向下建堆，其时间复杂度O(logn)
    vector<int> heap;
    /*for(int i=0; i<ele.size()-1; i++){
        push_heap(heap, ele[i]);
    }*/
    //从下向上建堆从后面向前一次遍历所有非野子节点的元素，O(n)
    heap = ele;
    for(int i=heap.size()/2-1; i>=0; i--){
        shift_down(heap, i);
    }
    return heap;
}

std::vector<int> heap_sort(std::vector<int> &heap){
    vector<int> res;
    while(!heap.empty()){
        res.push_back(heap[0]);
        pop_heap(heap);
    }
    return res;
}