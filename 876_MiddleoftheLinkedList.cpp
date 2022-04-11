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
Idea here is to use the slow and fast pointer.
when fast reach end in steps of 2, slow reach middle.
TIME: O(n)
SPACE: O(1)
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
/*
Idea here is to count the total nodes.
find the count till middle node.
then travel from head to middle in count steps.
TIME: O(n)
SPACE: O(1)
*/
class SolutionCount {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head;
        int count=0;
        while (first != nullptr){
            count++;
            first = first->next;
        }
        count = count/2 + 1;
        first = head;
        while (--count){
            first = first->next;
        }
        return first;
    }
};
