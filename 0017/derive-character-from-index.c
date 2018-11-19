// Number of possible characters, starting from digit '2'.
static size_t POSSIBLE_CHARACTERS[] = { 3, 3, 3, 3, 3, 4, 3, 4 };

char** letterCombinations(char* digits, int* returnSize) {
    size_t digits_len = strlen(digits);

    if (digits_len == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Find the number of possible combinations.
    // Store the intermediate result to derive character from index.
    size_t* possible_combinations = malloc(sizeof(size_t) * digits_len);
    size_t possible_so_far = 1;
    for (size_t i = 0; i < digits_len; ++i) {
        possible_combinations[i] = possible_so_far;
        possible_so_far *= POSSIBLE_CHARACTERS[digits[i] - '2'];
    }

    char** combinations = malloc(sizeof(char*) * possible_so_far);
    for (size_t i = 0; i < possible_so_far; ++i) {
        combinations[i] = malloc(sizeof(char) * (digits_len + 1));
        for (size_t j = 0; j < digits_len; ++j) {
            combinations[i][j] =
                // Alphabet starts with 'a'.
                'a' +
                // Find the first alphabet of the digit.
                (digits[j] - '2') * 3 +
                // Since 7 has 4 characters, everything above needs extra 1.
                (digits[j] > '7' ? 1 : 0) +
                // The possible combination offset.
                (i / possible_combinations[j]) % POSSIBLE_CHARACTERS[digits[j] - '2'];
        }
        combinations[i][digits_len] = '\0';
    }

    free(possible_combinations);
    *returnSize = possible_so_far;
    return combinations;
}
