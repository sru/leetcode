bool isPalindrome(int x) {

    // Sanity check.
    // If x is negative, there is the dash at the front,
    // so it is never palindrome.
    // If the first digit is 0 and x is double digit,
    // there is the 0 at the end, so it is never palindrome.
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
