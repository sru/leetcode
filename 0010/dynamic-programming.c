bool isMatch(char* str, char* pattern) {
    size_t len_str = strlen(str);
    size_t len_pattern = strlen(pattern);

    // Allocate len_str * let_pattern matrix.
    bool (*match)[len_pattern + 1] = malloc((len_str + 1) * sizeof(*match));

    // Fill when the given string is empty.
    match[0][0] = true;
    for (size_t i = 1; i < len_pattern + 1; ++i) {
        if (patten[i - 1] == '*') {
            match[0][i] = match[0][i - 2];
        }
        else {
            match[0][i] = false;
        }
    }

    for (size_t i = 1; i < len_str + 1; ++i) {
        match[i][0] = false;

        for (size_t j = 1; j < len_pattern + 1; ++j) {
            if (pattern[j - 1] == '*') {
                match[i][j] =
                    // Zero of previous character.
                    match[i][j - 2] ||
                    // Previous character has matched the star.
                    match[i - 1][j] &&
                    // Check if the current character matches.
                    (pattern[j - 2] == '.' || pattern[j - 2] == str[i - 1]);
            }
            else {
                match[i][j] =
                    match[i - 1][j - 1] &&
                    (pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1]);
            }
        }
    }

    bool matched = match[len_str][len_pattern];
    free(match);
    return matched;
}
