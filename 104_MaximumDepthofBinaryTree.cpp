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
* The idea is root is at level or depth 1.
* then recursively calculate the depth of subtrees and find max of it 
* and 1 to it. 
* Base case: root node is null, then return depth 0;
* TIME: O(n) as we will be visiting all node once;
* SPACE: O(h) , h is height of tree is max stack used in recursion.
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) 
          return 0;
        return 1 + std::max(maxDepth(root->left),
                            maxDepth(root->right));
    }
};
