/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode *root) {
    if (!root) return NULL;

    struct TreeNode *tmp = root->left;

    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}
