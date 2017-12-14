/*
 * You are given coins of different denominations and a total amount of
 * money amount. Write a function to compute the fewest number of coins
 * that you need to make up that amount. If that amount of money cannot
 * be made up by any combination of the coins, return -1.
 *
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 */

#define MIN(a,b) (a) < (b) ? (a) : (b)
int coinChange(int *coins, int coinsSize, int amount) {
    int *minCoins = malloc((amount + 1) * sizeof(int));
    int i, j;

    minCoins[0] = 0;
    for (i = 1; i <= amount; i++) {
        minCoins[i] = 0x7fffffff;
        for (j = 0; j < coinsSize; j++) {
            if ((coins[j] <= i) && (minCoins[i - coins[j]] != 0x7fffffff)) {
                minCoins[i] = MIN(minCoins[i - coins[j]] + 1, minCoins[i]);
            }
        }
    }
    return minCoins[amount] == 0x7fffffff ? -1 : minCoins[amount];
}
