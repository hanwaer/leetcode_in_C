/*
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

int lengthOfLongestSubstring(char *s) {
    char *l, *r;
    int max = 0;
    char *map[256] = {0};

    for (l=r=s; *r; r++) {
        if (map[*r] != NULL) {
            l = l>map[*r]?l:map[*r]+1;
        }
        max = max>(r-l+1)?max:(r-l+1);
        map[*r] = r;
    }

    return max;
}
