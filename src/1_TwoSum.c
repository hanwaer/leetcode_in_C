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
