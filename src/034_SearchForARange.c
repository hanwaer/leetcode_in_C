/*
 * Given an array of integers sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int *nums, int numsSize, int target, int *returnSize) {
    int *ret = calloc(2, sizeof(int));
    ret[0] = -1, ret[1] = -1;
    *returnSize = 2;

    int l, r, m;
    // left
    l = 0, r = numsSize - 1;
    while (l < r) {
        m = (l + r) / 2;
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (nums[l] == target)
        ret[0] = l;
    else
        return ret;

    // right
    r = numsSize - 1;
    while (l < r) {
        m = (l + r) / 2 + 1;
        if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    ret[1] = r;
    return ret;
}
