/**
 * # Problem
 *
 * Given a string, find the length of the __longest substring__ without
 * repeating characters.
 *
 * # Solution
 *
 * The solution uses hash table to store the previously known character index.
 * Since I am finding the longest substring, I can go through each index, store
 * the character's index and the number of unique characters. If I encounter a
 * previously encountered character, I check if that character is inside the
 * substring and move the start of the substring to 1 after that character to
 * exclude the character. Then, I just need to keep track of the maximum length
 * of the substring.
 *
 * ## Time Complexity
 *
 * The time complexity of this solution is O(N^2) in the worst case and O(N) in
 * the average case, assuming hash table performs in O(N) in the worst case and
 * O(1) in the average case, where N is the number of characters inside the
 * string. It is because the solution goes through each character exactly once.
 *
 * ## Space Complexity
 *
 * Since I may store in hash table up to N values, where N is the number of
 * characters inside the string, this solution has space complexity of O(N).
 *
 * # Custom Test Cases
 *
 * ```
 * "pwwkew"
 * "asdf"
 * "asddsab"
 * "bbbbb"
 * "abcabcbb"
 * "a"
 * ""
 * ```
 */

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
