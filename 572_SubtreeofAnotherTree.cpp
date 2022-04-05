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
 * Idea here is to check tree rooted at each node against target tree.
 * It is done recursively using isSameTree function.
 * TIME: O(sizeof(root) * sizeof(subRoot))
 * SPACE: O(heightof(root)+heightof(subRoot))
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // empty set is subset of empty set.
        if (root==nullptr && subRoot==nullptr) return true;
        // Nonempty set cannot be subset of empty set.
        if (root==nullptr && subRoot != nullptr) return false;
        // empty set is always subset of Nonempty set.
        if (root!=nullptr && subRoot == nullptr) return true;
        
        return isSameTree(root, subRoot) ||
               isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
