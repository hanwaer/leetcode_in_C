/*
 * Given a string S and a string T, find the minimum window in S which
 * will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return
 * the empty string "".
 *
 * If there are multiple such windows, you are guaranteed that there will
 * always be only one unique minimum window in S.
 */

#define MIN(a,b) a < b ? a : b
char* minWindow(char *s, char *t) {
    int map[128];
    int i, j, min = 0x7fffffff, tmp_min = 0x7fffffff, total;
    char *begin, *end, *head;

    for (i = 0; i < 128; i++) {
        map[i] = 0;
    }

    total = strlen(t);
    for (i = 0; i < total; i++) {
        map[t[i]]++;
    }

    begin = end = s;
    while(*end) {
        if (map[*end++]-- > 0)
            total--;
        while (total == 0) {
            if ((tmp_min = end - begin) < min) {
                head = begin;
                min = tmp_min;    
            };

            if (map[*begin++]++ == 0)
                total++;
        }
    }

    if (min != 0x7fffffff)
        return strndup(head, min);
    return "";
}
