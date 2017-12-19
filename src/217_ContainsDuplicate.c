/*
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in
 * the array, and it should return false if every element is distinct.
 */

bool containsDuplicate(int *nums, int numsSize) {
    int i,j;

    for (i = 0; i < numsSize - 1; i++) {
        for (j = i+1; j<numsSize; j++) {
            if (nums[i] == nums[j])
                return true;
        }
    }

    return false;
}
