/**
 * Implement `atoi` which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of this
 * function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty or
 * it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 * - Only the space character ' ' is considered as whitespace character.
 * - Assume we are dealing with an environment which could only store integers
 *   within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the
 *   numerical value is out of the range of representable values, INT_MAX (2^31
 *   − 1) or INT_MIN (−2^31) is returned.
 *
 * # Test Cases
 *
 * - "42"
 * - "-42"
 * - "4193 with words"
 * - "words and 987"
 * - "-91283472332"
 * - "+1"
 *
 * # Solution
 *
 * The solution is straightforward. The solution uses gcc's builtin extension
 * for detecting overflow on operations.
 *
 * ## Time Complexity
 *
 * Since the solution goes through each character once, the solution has time
 * complexity of O(N), where N is the number of characters in the string.
 *
 * ## Space Complexity
 *
 * The solution has space complexity of O(1) because it does not use extra
 * spaces that depend on input size.
 */

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
