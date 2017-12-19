/*
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

int cmp(void *a, void *b) {
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}


/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval *intervals, int intervalsSize, int *returnSize) {
    qsort(intervals, intervalsSize, sizeof(struct Interval), cmp);
    int i, j, k, min_start, max_end;
    struct Interval* result = calloc(intervalsSize, sizeof(struct Interval));

    k = 0;
    for (i = 0; i < intervalsSize; ) {
        min_start = intervals[i].start;
        max_end = intervals[i].end;
        for (j = i + 1; j < intervalsSize; j++) {
            if (max_end >= intervals[j].start)
                max_end = max_end > intervals[j].end ? max_end : intervals[j].end;
            else
                break;
        }

        i = j;
        result[k].start = min_start;
        result[k].end = max_end;
        k++;
    }

    *returnSize = k;
    return result;
}
