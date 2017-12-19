/*
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have
 * security system connected and it will automatically contact the police
 * if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money
 * of each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 */

#define max(a,b) (a) > (b) ? (a) : (b)
int rob(int *nums, int numsSize) {
    int i, a = 0, b = 0;

    for (i = 0; i < numsSize; i++) {
        if (i % 2 == 0)
            a = max(a + nums[i], b);
        else
            b = max(a, b + nums[i]);
    }

    return max(a,b);
}
