/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1,
 * otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to
 * separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three",
 * it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 */

int compareVersion(char *version1, char *version2) {
    int ret = 0, c1, c2, i, max;
    int *r1, *r2;
    char *n1 = NULL, *n2 = NULL, *p1 = version1, *p2 = version2;

    c1 = c2 = 1;
    while (n1 = strchr(p1, '.')) {c1++; p1 = n1 + 1;}
    while (n2 = strchr(p2, '.')) {c2++; p2 = n2 + 1;}

    max = c1 > c2 ? c1 : c2;
    r1 = calloc(max, sizeof(int));
    r2 = calloc(max, sizeof(int));

    c1 = c2 = 0;
    p1 = version1;
    p2 = version2;

    for (n1 = strsep(&p1, "."); n1; n1 = strsep(&p1, ".")) {
        r1[c1++] = atoi(n1);
    }


    for (n2 = strsep(&p2, "."); n2; n2 = strsep(&p2, ".")) {
        r2[c2++] = atoi(n2);
    }

    for (i = 0; i < c1 || i < c2; i++) {
        if (r1[i] > r2[i]) {
            ret = 1;
            break;
        } else if (r1[i] < r2[i]) {
            ret = -1;
            break;
        }
    }

    free(r1);
    free(r2);
    return ret;
}
