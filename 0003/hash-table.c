struct Entry {
    char key;
    int value;
    UT_hash_handle hh;
};

int lengthOfLongestSubstring(char* s) {
    int len_max = 0;
    int start = 0;

    struct Entry* map = NULL;

    for (int i = 0; s[i] != '\0'; ++i) {
        struct Entry* entry;

        // Find the current character.
        HASH_FIND(hh, map, &s[i], 1, entry);

        if (entry == NULL) {
            // Not found.
            entry = malloc(sizeof(struct Entry));
            entry->key = s[i];
            entry->value = i;
            HASH_ADD(hh, map, key, 1, entry);
        }
        else if (entry->value >= start) {
            // The character is inside the substring.
            start = entry->value + 1;
            entry->value = i;
        }
        else {
            // The character is outside the substring.
            entry->value = i;
        }

        if (len_max < i - start + 1) {
            len_max = i - start + 1;
        }
    }

    struct Entry* entry;
    struct Entry* tmp;

    HASH_ITER(hh, map, entry, tmp) {
        HASH_DEL(map, entry);
        free(entry);
    }

    return len_max;
}
