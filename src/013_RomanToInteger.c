/*
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

int romanToInt(char* s) {
    if (!s)
        return 0;

    int sum = 0;
    int m[26] = {[2]=100,[3]=500,[8]=1,[11]=50,[12]=1000,[21]=5,[23]=10};
    int len = strlen(s);

    sum = m[s[len-1]-'A'];
    for (int i = len-2; i>=0; i--) {
        sum += (m[s[i]-'A'] >= m[s[i+1]-'A'])?m[s[i]-'A']:-m[s[i]-'A'];
    } 

    return sum;
}
