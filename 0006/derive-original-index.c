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
