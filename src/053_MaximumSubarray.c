/*
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

int maxSubArray(int *nums, int numsSize) {
    int max, tmp_max, i;

    if (!nums)
        return -1-0x7fffffff;

    max = nums[0];
    tmp_max = nums[0];
    for (i = 1; i < numsSize; i++) {
        tmp_max = (tmp_max + nums[i]) > nums[i] ? (tmp_max + nums[i]) : nums[i];
        max = max > tmp_max ? max : tmp_max;
    }

    return max;
}
