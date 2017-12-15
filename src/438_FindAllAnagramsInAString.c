/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


int isAnagrams(char *s, int *map, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        map[s[i]]--;
        if (map[s[i]] < 0)
            return 0;
    }
    return 1;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    size_t s_len = strlen(s);
    size_t p_len = strlen(p);
    int len_diff = s_len - p_len;
    int *ret = calloc(s_len + 1, sizeof(int));
    int map[128] = {0}, tmp[128] = {0};
    int i, j = 0;

    for (i = 0; i < p_len; i++) {
        map[p[i]]++;
    }

    
    for (i = 0; i <= len_diff; i++) {
        memcpy(tmp, map, 128*sizeof(int));
        if (isAnagrams(&s[i], &tmp, p_len)) {
            ret[j++] = i;
        }
    }
    *returnSize = j;
    return ret;
}
