/*
 * Implement pow(x, n).
 *
 *
 * Example 1:
 *
 * Input: 2.00000, 10
 * Output: 1024.00000
 * Example 2:
 *
 * Input: 2.10000, 3
 * Output: 9.26100
 */

double myPow(double x, int n) {
    if (n == 0) 
        return 1;

    double d = myPow(x, n / 2);
    if (n % 2)
        return (n % 2 < 0) ? (1 / x * d * d) : (x * d * d);
    return d * d;
}
