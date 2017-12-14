/*
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.
 *
 * Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 *
 */

int countNumbersWithUniqueDigits(int n) {
    int i, total = 10, last = 9, availnums = 9;
    if (n == 0)
        return 1;
    if (n == 1)
        return 10;

    for (i = 2; i <= n && i <= 10; i++) {
        last *= availnums;
        total += last;
        availnums--;
    }
    return total;
}


