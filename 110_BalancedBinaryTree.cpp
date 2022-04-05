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
* Idea here is to traverse tree all the way down and will backtracking,
* gather information of height of tree and is tree balance.
* This can be thought of dynamic programming approach where bottom up solution,
* is created. we keep variable to record whether tree is balanced or not.
* TIME: O(n) as every node is visited once.
* SPACE: O(h) where h is height of tree and size of recursion on stack.
*/
class Solution {
public:
    int isBalanceHelper(TreeNode* node, bool& isbalance){
        // tree with null node has zero height.
        if (node == nullptr) return 0;
        // Lets assume like inductive case we have height and isbalance result available 
        // at level n-1.
        int leftheight = isBalanceHelper(node->left, isbalance);
        int rightheight = isBalanceHelper(node->right, isbalance);
        // from inductive case build the result for level n.
        int diff = std::abs(leftheight-rightheight);
        if (diff <= 1) 
          isbalance &= true;
        else 
          isbalance &= false;
        return 1 + std::max(leftheight, rightheight);
    }
    bool isBalanced(TreeNode* root) {
        bool isbalance=true;
        isBalanceHelper(root, isbalance);
        return isbalance;
    }
};

/*
* Idea is to find that if tree rooted at each node is balance or note.
* The recursive definition is translate to code below; find the diff of 
* height at given node and if it is balanced, it will check whether subtrees
* are balanced or not. otherwise it will return false.
* TIME: O(n^2) as we find height at each node.
* SPACE: O(h) h is max height of recursion stack which is logN.
*/
class Solution_brute {
public:
    int height(TreeNode* root){
        if (root==nullptr) return 0;
        return 1 + std::max(height(root->left),
                            height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left = height(root->left);
        int right = height(root->right);
        int diff = std::abs(left-right);
        if (diff <=1){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else {
            return false;
        }
    }
};
