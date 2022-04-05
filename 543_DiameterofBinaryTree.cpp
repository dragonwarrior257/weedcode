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
* Idea here is to avoid computation of depth of tree again and again for 
* all nodes. This is like dynamic programming,bottom up approach.
* So, we will return the max depth of the tree at node and use
* maxdia variable to store the maxdia seen so far.
* Thus, null node is at level -1.
* any node above it will add 1 to it. like single node is at level 0.
* we calculate the diamenter from bottom up manner and return the depth also.
* TIME: O(n) as all node are visited only once.
* SPACE: O(h) as h is height of recursion stack equal to logn.
*/
class Solution {
public:
    int helper(TreeNode* node, int& maxdia){
        if (node == nullptr) return -1;
        // helper will return depth of the tree.
        int leftdepth = helper(node->left, maxdia);
        int rightdepth = helper(node->right, maxdia);
        // At present node, diameter is 2+leftdepth+rightdepth,
        // and we will update maxdia using this.
        maxdia = std::max(maxdia, 2+leftdepth+rightdepth);
        // Now we will return max depth reachable from this node.
        return 1+std::max(leftdepth, rightdepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia=0;
        helper(root, maxdia);
        return maxdia;
    }
};

/*
* This is brute force solution. Idea is to calculate the diameter
* passing through each node of the tree and find maximum diameter of it.
* so, at each node we find depth of left subtree and right subtree.
* then diameter is 2+depth left + depth right, and if it is larger then
* already seen maximum, update the maximum variable.
* TIME: O(n^2) as we vist each node twice.
* SPACE: O(h) h = height of tree with n nodes equal to logn.
*/
class Solution_Brute {
public:
    int depth(TreeNode* root){
        //null node are at level -1, 
        // single node at level 0, and so on ...
        if (root == nullptr) return -1;
        return 1 + std::max(depth(root->left), depth(root->right));
    }
    void helper(TreeNode* root, int& maxdia){
        if (root == nullptr) return;
        int left = depth(root->left);
        int right = depth(root->right);
        maxdia = std::max(maxdia, 2+left+right);
        // once done at root, recursively find diameter for all sub nodes.
        helper(root->left, maxdia);
        helper(root->right, maxdia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia=0;
        helper(root, maxdia);
        return maxdia;
    }
};
