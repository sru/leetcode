char* intToRoman(int num) {
    // Longest Roman numeral has 15 characters: MMMDCCCLXXXVIII
    char* roman = malloc(16 * sizeof(char));
    char* ptr = roman;

    for (int i = 0; i < num / 1000; ++i) {
        *ptr++ = 'M';
    }

    #define DIGIT_TO_ROMAN(ptr, digit_expr, one, five, ten) do { \
        register int digit = (digit_expr); \
        if (digit >= 5 && digit != 9) { \
            *ptr++ = five; \
        } \
        switch (digit % 5) { \
            case 4: \
                *ptr++ = one; \
                *ptr++ = (digit >= 5) ? ten : five; \
                break; \
            case 3: \
                *ptr++ = one; \
            case 2: \
                *ptr++ = one; \
            case 1: \
                *ptr++ = one; \
            case 0: \
                break; \
        } \
    } while (0)

    DIGIT_TO_ROMAN(ptr, (num % 1000) / 100, 'C', 'D', 'M');
    DIGIT_TO_ROMAN(ptr, (num % 100) / 10,   'X', 'L', 'C');
    DIGIT_TO_ROMAN(ptr, (num % 10),         'I', 'V', 'X');

    #undef DIGIT_TO_ROMAN

    *ptr = '\0';

    return roman;
}
