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
https://leetcode.com/problems/add-two-numbers/

TIME: O(max(m,n))
SPACE: O(1) not including list creation space.
*/

class Solution {
private:
    ListNode* sumptr=nullptr;
    int carry=0;
    
    ListNode* reverse(ListNode* l){
        ListNode* temp=nullptr;
        while(l != nullptr){
            ListNode* tempnode = l; 
            l = l->next;
            tempnode->next = temp;
            temp = tempnode;
        }
        return temp;
    }
    ListNode* addrest(ListNode* l){
        while (l != nullptr){
            int sum = l->val + carry;
            ListNode* tempnode = new ListNode(sum%10, sumptr);
            sumptr = tempnode;
            carry = sum/10;
            l = l->next;
        }
        if (carry != 0){
            ListNode* tempnode = new ListNode(carry, sumptr);
            sumptr = tempnode;
        }
        return reverse(sumptr);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1==nullptr && l2==nullptr) {
            if (carry != 0){
            ListNode* tempnode = new ListNode(carry, sumptr);
            sumptr = tempnode;
            }
            return reverse(sumptr);
        }
        if (l1==nullptr && l2!=nullptr) return addrest(l2);
        if (l1!=nullptr && l2==nullptr) return addrest(l1);
        int nodesum = l1->val + l2->val + carry;
        ListNode* tempnode = new ListNode(nodesum%10, sumptr);
        sumptr = tempnode;
        carry = nodesum/10;
        return addTwoNumbers(l1->next, l2->next);
    }
};
