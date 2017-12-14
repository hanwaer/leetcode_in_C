/*
 * Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function,
 * nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */


void moveZeroes(int *nums, int numsSize) {
    int x, y, i;
    
    for (i = 0; i < numsSize - 1; i++) {
        x = i;
        y = i + 1;
        if (nums[x] == 0) {
            while (y < numsSize) {
                if (nums[y] == 0) {
                    y++;
                } else {
                    nums[x] = nums[y];
                    nums[y] = 0;
                    break;
                }
            }
        }
    }
}
