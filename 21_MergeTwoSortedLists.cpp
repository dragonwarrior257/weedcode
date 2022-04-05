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
* list1 empty and list2 empty return empty
* list1 empty and list2 valid return list2
* list1 valid and list2 empty return list1
* take first of list1 and first of list2 and compare and insert into
* new list and recursively call the merge on the rest of list.
* TIME: O(n+m) n=length of list1 and m=length of list2
* SPACE: O(n+m)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == nullptr){
            return list2;
        }
        else if(list1 != nullptr && list2 == nullptr){
            return list1;
        }
        else if (list1->val < list2->val){
            ListNode* ret = mergeTwoLists(list1->next, list2);
            list1->next = ret;
            return list1;
        }
        else{
            ListNode* ret = mergeTwoLists(list1, list2->next);
            list2->next = ret;
            return list2;
        }
    }
};
