struct Entry {
    int key;
    int value;
    UT_hash_handle hh;
};

int* twoSum(int* nums, int numsSize, int target) {

    // Contrived case.
    if (numsSize < 2 || nums == NULL) {
        return NULL;
    }

    struct Entry* map = NULL;
    // Call malloc once rather than having to malloc in a loop.
    struct Entry* entries = malloc(sizeof(struct Entry) * numsSize);
    int entries_count = 0;

    int* ret = NULL;

    for (int i = 0; i < numsSize; ++i) {
        struct Entry* entry;
        int target_sub = target - nums[i];

        // Find the other.
        HASH_FIND_INT(map, &target_sub, entry);
        if (entry != NULL) {
            ret = malloc(sizeof(int) * 2);
            ret[0] = entry->value;
            ret[1] = i;
            break;
        }

        // Add current.
        HASH_FIND_INT(map, &nums[i], entry);
        if (entry == NULL) {
            entries[entries_count].key = nums[i];
            entries[entries_count].value = i;
            HASH_ADD_INT(map, key, &entries[entries_count]);
            ++entries_count;
        }
    }

    HASH_CLEAR(hh, map);
    free(entries);

    return ret;
}
