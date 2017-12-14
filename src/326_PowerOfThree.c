/*
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
 */

bool isPowerOfThree(int n) {
    if (n == 3 || n == 1)
        return true;
    else if (n <= 2)
        return false;
    else if (n % 3)
        return false;
    else
        return isPowerOfThree(n/3);
}
