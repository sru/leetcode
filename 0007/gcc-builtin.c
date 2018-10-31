int reverse(int x) {
    int rev = 0;
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
