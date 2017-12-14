/*
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 * Example 1:
 * Input: [3,0,1]
 * Output: 2
 *
 * Example 2:
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you
 * implement it using only constant extra space complexity?
 */

int missingNumber(int *nums, int numsSize) {
    int i, tmp, max, missing = -1;

    for (i = 0; i < numsSize; i++) {
        while (nums[i] != i) {
            tmp = nums[i];
            if (nums[i] >= numsSize) {
                max = nums[i];
                missing = i;
                break;
            } else if (missing == nums[i]) {
                nums[missing] = missing;
                missing = i;
                break;
            } else {
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
    }

    if (missing == -1)
        return numsSize;
    return missing;
}
