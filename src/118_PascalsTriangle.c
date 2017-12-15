/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

int** generate(int numRows, int** columnSizes) {
    int i, j;
    int **rr = calloc(numRows, sizeof(int*));
    int *s = calloc(numRows, sizeof(int));

    for (i = 0; i < numRows; i++) {
        s[i] = i+1;
        rr[i] = calloc(i+1, sizeof(int));
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                rr[i][j] = 1;
            else
                rr[i][j] = rr[i-1][j-1] + rr[i-1][j];
        }    
    }

    *columnSizes = s;
    return rr;
}
