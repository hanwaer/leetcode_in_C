/*
 * Given a string s, find the longest palindromic substring in s. 
 * You may assume that the maximum length of s is 1000.
 *
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example:
 * Input: "cbbd"
 * Output: "bb"
 */

inline bool isPalindrome(char *s, int begin, int end)
{
    if (begin < 0)
        return false;

    while (begin<end) {
        if (s[begin++] != s[end--])
            return false;
    }
    return true;
}

char *longestPalindrome(char *s)
{
    int i, longest = 0, len = strlen(s);
    char *res;

    for (i = 0; i < len; i++) {
        if (isPalindrome(s, i - longest - 1, i)) {
            res = s + (i - longest - 1);
            longest += 2;
        } else if (isPalindrome(s, i - longest, i)) {
            res = s + (i - longest);
            longest += 1;
        }
    }

    if (res && longest > 0)
        res[longest] = 0;
    return res;
}
