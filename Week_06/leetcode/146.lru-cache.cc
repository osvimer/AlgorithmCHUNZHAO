// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
// 实现 LRUCache 类：
//    1. LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
//    2. int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
//    3. void put(int key, int value) 如果关键字已经存在，则变更其数据值；
//       如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，
//       它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
// https://leetcode-cn.com/problems/lru-cache

// 思路：双向链表 + 哈希表
class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity) {}

    int get(int key) {
        if (0 == hash_.count(key)) {
            return -1;
        }
        auto it = hash_[key];
        int value = it->second;
        list_.erase(it);
        list_.emplace_front(key, value);
        hash_[key] = list_.begin();
        return value;
    }

    void put(int key, int value) {
        if (0 != hash_.count(key)) {
            list_.erase(hash_[key]);
        } else if (cap_ == list_.size()) {
            hash_.erase(list_.rbegin()->first);
            list_.pop_back();
        }
        list_.emplace_front(key, value);
        hash_[key] = list_.begin();
    }
private:
    int cap_;
    list<pair<int, int>> list_;
    unordered_map<int, list<pair<int, int>>::iterator> hash_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
