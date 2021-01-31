// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 思路一：暴力法，双指针迭代
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* current;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current = l1;
                l1 = l1->next;
            } else {
                current = l2;
                l2 = l2->next;
            }
            if (!head) {
                head = current;
            } else {
                tail->next = current;
            }
            current->next = nullptr;
            tail = current;
        }
        if (l1) {
            if (!head) {
                head = l1;
            } else {
                tail->next = l1;
            }
        }
        if (l2) {
            if (!head) {
                head = l2;
            } else {
                tail->next = l2;
            }
        }
        return head;
    }
};

// 思路二：加入虚拟节点优化边界检查
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 == nullptr) ? l2 : l1;
        ListNode* temp = head;
        head = head->next;
        delete temp; // 需要将加入的虚拟节点删除，避免内存泄漏
        return head;
    }
};

// 思路三：使用递归，简化代码逻辑
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};