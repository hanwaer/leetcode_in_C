/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

int maxDepth(struct TreeNode* root) {
    int left, right;

    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    left = right = 1;
    if (root->left) 
        left += maxDepth(root->left);

    if (root->right)
        right += maxDepth(root->right);

    return left>right?left:right;
}
