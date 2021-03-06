// 设计实现双端队列。
// 你的实现需要支持以下操作：
// 
// MyCircularDeque(k)：构造函数,双端队列的大小为k。
// insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
// insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
// deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
// deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
// getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
// getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
// isEmpty()：检查双端队列是否为空。
// isFull()：检查双端队列是否满了。

// 思路一：使用数组实现，为了区分队列有一个元素和队列为空的情况，需要额外占用一单位空间
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity_ = k + 1;
        vec_.resize(capacity_);
        head_ = 0;
        tail_ = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            vec_[head_] = value;
            tail_++;
        } else {
            head_ = (capacity_ + head_ - 1) % capacity_;
            vec_[head_] = value; 
        }
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        vec_[tail_] = value;
        tail_ = (tail_ + 1) % capacity_;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        head_ = (head_ + 1) % capacity_;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        tail_ = (capacity_ + tail_ - 1) % capacity_;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return vec_[head_];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return vec_[(capacity_ + tail_ - 1) % capacity_];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return head_ == tail_;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (tail_ + 1) % capacity_ == head_;
    }
private:
    vector<int> vec_;
    int head_;
    int tail_;
    int capacity_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */