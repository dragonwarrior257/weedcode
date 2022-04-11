/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Idea here is to find cycle without using extra space.
first check for cycle.
second get cycle length.
third start two pointer with cycle length apart.
TIME: O(n)
SPACE: O(1)
*/
class Solution {
public:
    ListNode* detect(ListNode* node){
        ListNode* slow = node;
        ListNode* fast = node;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return slow;
        }
        return NULL;
    }
    int cyclelength(ListNode* node){
        ListNode* curr=node;
        int count=0;
        do{
            count++;
            curr = curr->next;
        }while(curr!=node);
        return count;
    }
    ListNode* findstart(ListNode* node, int len){
        ListNode* first = node;
        ListNode* second = node;
        while (len){
            second = second->next;
            len--;
        }
        while (first != second){
            first = first->next;
            second = second->next;
        }
        return first;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* node = detect(head);
        if (node != NULL){
            int len = cyclelength(node);
            cout << len << endl;
            return findstart(head, len);
        }
        else {
            return NULL;
        }
    }
};
/*
Idea here is to store the node addresses in a hashtable.
and check if node is already seen or not.
TIME: O(n)
SPACE: O(n)
*/
class SolutionHash {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        ListNode* curr=head;
        while (curr){
            if (hash.find(curr) != hash.end()){
                return curr;
            }
            hash.insert(curr);
            curr = curr->next;
        }
        return NULL;
    }
};
