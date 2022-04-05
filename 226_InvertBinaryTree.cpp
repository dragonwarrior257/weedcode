/*
* Idea is as follows:
* single node is already inverted, nothing to do.
* Then we swap the left and right node, which will swap(invert) 
* the whole left and right subtree.
* then we can recursively call the invert on left and right subtree.
* TIME: O(n) n= number of nodes in tree, as we touch each node to swap.
* SPACE: O(h) h = height of the tree on stack space in recursion.
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) 
          return nullptr;
        //swap will invert the whole left and right subtree.
        std::swap(root->left, root->right);
        // recursively call invert on left and right subtree.
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};
