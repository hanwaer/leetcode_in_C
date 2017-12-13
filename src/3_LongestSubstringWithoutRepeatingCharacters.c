int lengthOfLongestSubstring(char* s) {
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
