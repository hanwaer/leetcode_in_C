/*
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from
 * the root node down to the nearest leaf node.
 */

int minDepth(struct TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int a = minDepth(root->left);
    int b = minDepth(root->right);

    if (a==0) return 1+b;
    else if (b==0) return 1+a;
    else return 1+(a>b?b:a);
}
