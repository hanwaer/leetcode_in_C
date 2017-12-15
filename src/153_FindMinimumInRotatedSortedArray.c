/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */


int findMin(int* nums, int numsSize) {
    int i;
    int min = nums[0];

    for (i = 1; i < numsSize; i++) {
        if (min > nums[i])
            return nums[i];
    }

    return min;
}
