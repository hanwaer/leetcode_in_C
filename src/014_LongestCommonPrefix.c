/*
 * Write a function to find the longest common prefix string amongst an 
 * array of strings.
 */

char* longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0)
        return "";

    int i, j, max_len = strlen(strs[0]), len;
    char *res = strdup(strs[0]);
    for (i = 0; i < max_len; i++) {
        for (j = 1; j < strsSize; j++) {
            if (strs[j - 1][i] != strs[j][i])
                break;
        }
        if (j != strsSize) {
            res[i] = 0;
            return res;
        }
    }
    return res;
}
