/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

int majorityElement(int* nums, int numsSize) {
    int m, n, i;
    m = nums[0];
    n = 0;
    for (i = 0; i < numsSize; i++){
        if (n == 0)
            m = nums[i];
        if (m == nums[i])
            n++;
        else
            n--;
    }

    return m;
}
