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

/*
* Idea is to extract the node from current list and 
* insert in front of new list. Then new list is in reverse order,
* return its head.
*TIME: O(n)
*SPACE:O(1)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newhead=nullptr;
        while (head != nullptr){
            ListNode *temp = head;
            head = head->next;
            temp->next = newhead;
            newhead = temp;
        }
        return newhead;
        
    }
};
