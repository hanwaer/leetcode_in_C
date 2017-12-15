/*
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting
 * with any positive integer, replace the number by the sum of the squares
 * of its digits, and repeat the process until the number equals 1 (where
 * it will stay), or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 */

bool isHappy(int n) {
    int cal(int n) {
        int x = 0, y = n;
        while (y) {
            x += (y % 10) * (y % 10);
            y = y/10;
        }
        return x;
    }

    int slow = cal(n);
    int fast = cal(slow);
    while (fast != slow) {
        slow = cal(slow);
        fast = cal(fast);
        fast = cal(fast);
    }

    return slow==1; 
}
