/*
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character
 * while preserving the order of characters. No two characters may map to
 * the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */

bool isIsomorphic(char* s, char* t) {
    char dict[127] = {0};
    char dict_t[127] = {0};
    while (*s && *t) {
        if (dict[*s]==0 && dict_t[*t]==0) {
            dict[*s] = *t;
            dict_t[*t] = *s;
        } else if (dict[*s] != *t) {
            return false;
        }

        s++;
        t++;
    }
    return true;
}
