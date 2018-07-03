/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when
 * it reads the same backward as forward.
 *
 * # Test Cases
 *
 * ```
 * 121
 * -121
 * 10
 * ```
 *
 * # Solution
 *
 * The solution "reverses" half of the digits of x, and compare the result.
 * Since `x` and `i` are integers and I am only adding up half of the digits, it
 * will never overflow.
 *
 * ## Time Complexity
 *
 * The solution traverses through half of the digits, so it has time complexity
 * of O(log10(x)).
 *
 * ## Space Complexity
 *
 * The solution does not have any space that depends on input size, so it has
 * space complexity of O(1).
 */

bool isPalindrome(int x) {

    // Sanity check. If x is negative, there is the dash at the front, so it is
    // never palindrome. If the first digit is 0 and x is double digit, there is
    // the 0 at the end, so it is never palindrome.
    if (x < 0 || (x >= 10 && x % 10 == 0)) {
        return false;
    }

    int i = 0;

    while (i < x) {
        i *= 10;
        i += x % 10;
        x /= 10;
    }

    return i == x || i / 10 == x;
}
