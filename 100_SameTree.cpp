/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
* Idea here is to check recursively if tree rooted at node is 
* same or not. 
* Base condition is given by first 3 clause.
* Then we inductively verify the current, given we know that left and right
* subtree are same.
* TIME: O(n) as all nodes are checked for sameness.
* SPACE: O(h) h is height of the tree size recursive stack.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 3 base conditions.
        if (p == nullptr && q == nullptr) return true;
        if (p != nullptr && q == nullptr) return false;
        if (p == nullptr && q != nullptr) return false;
        // Given inductive case for n-1 level tree, we verify nth level.
        if (p->val == q->val){
            return (isSameTree(p->left, q->left) && 
                   isSameTree(p->right, q->right));
        }
        else {
            return false;
        }
    }
};
