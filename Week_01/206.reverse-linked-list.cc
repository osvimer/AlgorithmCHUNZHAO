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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr; //新链表头
        ListNode* current; //当前要处理的节点
        while (head) {
            current = head; //存储旧链表头节点
            head = head->next; //更新旧链表头，移除当前处理节点
            current->next = new_head; //当前节点作为新链表表头
            new_head = current; //更新新链表头指针
        }
        return new_head;
    }
};