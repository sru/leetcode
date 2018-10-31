int myAtoi(char* str) {

    int value = 0;

    // Sanity check.
    if (str == NULL) { return 0; }

    // Skip spaces.
    while (*str == ' ') { ++str; }

    // Check sign.
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        ++str;
    }
    else if (*str == '+') {
        ++str;
    }

    // Parse digits.
    while (isdigit(*str)) {
        if (__builtin_smul_overflow(value, 10, &value)) {
            return sign < 0 ? INT_MIN : INT_MAX;
        }
        if (__builtin_sadd_overflow(value, sign * (*str - '0'), &value)) {
            return sign < 0 ? INT_MIN : INT_MAX;
        }
        ++str;
    }

    return value;
}
