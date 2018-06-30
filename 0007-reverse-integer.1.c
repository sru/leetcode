/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Note: Assume we are dealing with an environment which could only store
 * integers within the 32-bit signed integer range: [-2^31, 2^31 - 1]. For the
 * purpose of this problem, assume that your function returns 0 when the
 * reversed integer overflows.
 *
 * # Test cases
 *
 * - 123
 * - -123
 * - 120
 *
 * # Solution
 *
 * The solution goes through every digit started from the least significant one,
 * and append them to the result using gcc's builtin overflow checking
 * operations.
 *
 * ## Time Complexity
 *
 * The time complexity of this solution is O(log10(x)), where x is the input.
 *
 * ## Space Complexity
 *
 * The solution uses only constant extra space, so this solution has space
 * complexity of O(1).
 */

int reverse(int x) {
    int rev = 0;
    if (x == INT_MIN) {
        return 0;
    }

    int sign = x < 0;
    x = abs(x);

    while (x) {
        if (__builtin_smul_overflow(rev, 10, &rev)) {
            return 0;
        }
        if (__builtin_sadd_overflow(rev, x % 10, &rev)) {
            return 0;
        }
        x /= 10;
    }

    return sign ? -rev : rev;
}
