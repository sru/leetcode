int romanToInt(char* s) {
    int result = 0;

    while (*s == 'M') {
        result += 1000;
        ++s;
    }

    #define ROMAN_TO_DIGIT(place, one, five, ten) do { \
        register bool saw_one = false; \
        register bool saw_other = false; \
        while (!saw_other) { \
            switch (*s) { \
                case one: \
                    saw_one = true; \
                    result += place; \
                    ++s; \
                    break; \
                case five: \
                    result += (saw_one ? 3 : 5) * place; \
                    ++s; \
                    break; \
                case ten: \
                    result += (saw_one ? 8 : 0) * place; \
                    ++s; \
                    break; \
                default: \
                    saw_other = true; \
                    break; \
            } \
        } \
    } while (0)

    ROMAN_TO_DIGIT(100, 'C', 'D', 'M');
    ROMAN_TO_DIGIT(10,  'X', 'L', 'C');
    ROMAN_TO_DIGIT(1,   'I', 'V', 'X');

    #undef ROMAN_TO_DIGIT

    return result;
}
