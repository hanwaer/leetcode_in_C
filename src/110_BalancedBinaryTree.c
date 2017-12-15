/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int maxDepth(struct TreeNode *node) {
    if (!node)
        return 0;
    return (MAX(maxDepth(node->left), maxDepth(node->right)) + 1);
}

bool isBalanced(struct TreeNode* root) {
    if (!root)
        return true;

    return  isBalanced(root->left) && isBalanced(root->right) && (abs(maxDepth(root->left)-maxDepth(root->right)) <= 1);
}
