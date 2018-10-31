int lengthOfLongestSubstring(char* s) {
    int indices[256];
    int len_max = 0;
    int start = 0;

    for (int i = 0; i < 256; ++i) {
        indices[i] = -1;
    }

    for (int i = 0; s[i] != '\0'; ++i) {

        if (indices[s[i]] >= start) {
            start = indices[s[i]] + 1;
        }

        indices[s[i]] = i;

        if (len_max < i - start + 1) {
            len_max = i - start + 1;
        }
    }

    return len_max;
}
