//
// Created by Scott on 2020/7/7.
//

#ifndef LEETCODEDEMO_LRUCACHE_H
#define LEETCODEDEMO_LRUCACHE_H

#include <list>
#include <unordered_map>
template<typename K, typename T>
struct LRUNode{
    K key;
    T value;
    LRUNode(K k, T v):key(k),value(v){}
};
template<typename K, typename T>
class LRUCache{
public:
    LRUCache(int c) : capacity_(c){}
    T get(K k){
        //将k移动到第一个，并更新cache_map_
        cache_list_.splice(cache_list_.begin(), cache_list_, cache_map_[k]);
        cache_map_[k] = cache_list_.begin();
        return cache_map_[k]->value;
    }
    void set(K k, T v){
        if(cache_map_.find(k) == cache_map_.end()){
            if(cache_list_.size() == capacity_){
                //淘汰最后一个，然后将其加到第一个
                cache_map_.erase(cache_list_.back().key);
                cache_list_.pop_back();
            }
            cache_list_.push_front(LRUNode<K,T>(k, v));
            cache_map_[k] = cache_list_.begin();
        }else{
            //更新节点的值
            cache_map_[k]->value = v;
            cache_list_.splice(cache_list_.begin(), cache_list_, cache_map_[k]);
            cache_map_[k] = cache_list_.begin();
        }
    }
    void print_LRUCache(){
        std::cout << "LRU list :" << std::endl;
        for(auto tmp : cache_list_){
            std::cout << "key : " << tmp.key << ", value : " << tmp.value << std::endl;
        }
    }
private:
    int capacity_;
    std::list<LRUNode<K, T>> cache_list_;
    std::unordered_map<K, typename std::list<LRUNode<K, T>>::iterator> cache_map_;
};




#endif //LEETCODEDEMO_LRUCACHE_H
