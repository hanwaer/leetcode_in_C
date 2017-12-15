/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

int titleToNumber(char* s) {
    int sum = 0;
    while (*s != '\0') {
        sum = sum*26 + *s - 'A' + 1;
        s++;
    }

    return sum;
}
