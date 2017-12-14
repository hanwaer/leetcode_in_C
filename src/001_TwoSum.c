/*
 * Given an array of integers, return indices of the two numbers such that
 * they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */


#include "int_hash.h"

int* twoSum(int* nums, int numsSize, int target) {
    int *res = calloc(2, sizeof(int));
    hinit();

    int i;
    int value;
    for (i = 0; i < numsSize; i++) {
        if (hget(nums[i], &value) == 0) {
            res[0] = value;
            res[1] = i;
            return res;
        } else {
            hset(target-nums[i], i);
        }
    }
    return res;
}
