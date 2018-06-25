/**
 * # Problem
 *
 * The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given
 * number of rows like this:
 *
 * ```
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * ```
 *
 * And then read line by line: `"PAHNAPLSIIGYIR"`
 *
 * Write code that will take a string and make this conversion given a number of
 * rows:
 *
 * ```
 * string convert(string s, int numRows);
 * ```
 *
 * # Solution
 *
 * This solution calculates the index on the original string depending on the
 * position in the row. The zigzag pattern makes "N" reversed shape. The same
 * position in the reversed "N" is always `2 * (numRows - 1)` apart from each
 * other. Besides the first and the last row, each row has exactly 1 middle
 * position to fill, which is row number subtracted from the index of the
 * beginning of the reversed "N".
 *
 * ## Time Complexity
 *
 * The solution goes through each character once. O(N) where `N` is the number
 * of characters in the string.
 *
 * ## Space Complexity
 *
 * Since this solution is not in-place replacement, the space complexity is O(N)
 * where `N` is the number of characters in the string.
 */

char* convert(char* s, int numRows) {

    if (s == NULL || s[0] == '\0' || numRows <= 1) {
        return s;
    }

    int cap = strlen(s);
    char* s_prime = malloc(sizeof(char) * (cap + 1));
    s_prime[cap] = '\0';

    int len = 0;
    int step = 2 * (numRows - 1);

    for (int row = 0; row < numRows; ++row) {
        if (row == 0 || row == numRows - 1) {
            for (int i = row; i < cap; i += step) {
                s_prime[len++] = s[i];
            }
        }
        else {
            for (int i = row; i < cap; i += step) {
                s_prime[len++] = s[i];
                if (i + step - row * 2 < cap) {
                    s_prime[len++] = s[i + step - row * 2];
                }
            }
        }
    }

    return s_prime;
}
