#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


// 572. Subtree of Another Tree
bool isSame(TreeNode *t1, TreeNode *t2){
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;

    return (t1->val == t2->val) &&
        isSame(t1->left, t2->left) &&
        isSame(t1->right, t2->right);
}
bool isSubtree(TreeNode *root, TreeNode *subRoot){
    if (!subRoot) return true;
    if (!root) return false;
    return isSame(root, subRoot) ||
        isSubtree(root->left, subRoot) ||
        isSubtree(root->right, subRoot);
}

// 543. Diameter of Binary Tree
int diameter;
int longestPath(TreeNode* node){
    if(!node) return -1;

    int leftPath = longestPath(node->left);
    int rightPath = longestPath(node->right);

    diameter = std::max(diameter, leftPath + rightPath + 2);

    return std::max(leftPath, rightPath) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    diameter = 0;
    longestPath(root);
    return diameter;
}