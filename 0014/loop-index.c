char* longestCommonPrefix(char** strs, int strsSize) {
    size_t cap = 1024;
    size_t len = 0;
    char* prefix = malloc(cap * sizeof(char));

    if (strsSize <= 0) {
        prefix[len] = '\0';
        return prefix;
    }

    for (;;) {
        for (size_t i = 0; i < strsSize; ++i) {
            if (strs[i][len] == '\0' || strs[i][len] != strs[0][len]) {
                prefix[len] = '\0';
                return prefix;
            }
        }
        prefix[len] = strs[0][len];
        ++len;
        if (len == cap) {
            cap *= 2;
            prefix = realloc(prefix, cap * sizeof(char));
        }
    }
}
