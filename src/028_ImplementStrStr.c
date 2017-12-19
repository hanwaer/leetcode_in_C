/*
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 */

int strStr(char *haystack, char *needle) {
    int i, j;
    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);
    if (len_needle == 0)
        return 0;

    for (i = 0; i <= len_haystack - len_needle; i++) {
        for (j = 0; j < len_needle; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == len_needle)
            return i;
    }
    return -1;
}
