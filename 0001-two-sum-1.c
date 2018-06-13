/**
 * # Problem
 *
 * Given an array of integers, return __indices__ of the two numbers such that
 * they add up to a specific target.
 *
 * You may assume that each input would have ___exactly___ one solution, and you
 * may not use the _same_ element twice.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * # Explanation
 *
 * This solution uses hash table, from uthash, which is already included in
 * LeetCode. `Entry` is defined to make the hash table mimic a hash map. The map
 * stores the number as key and the index as value. If I can find `target -
 * nums[i]` in the hash table, the number has already been seen, so I can just
 * return the number's index and the current index.
 *
 * ## Time Complexity
 *
 * Let `N` denote the number of elements.
 *
 * The solution goes through the elements once. Since finding an element in and
 * adding an element to hash table is normally constant-time operations, the
 * solution has the average time complexity of O(N). The worst time complexity
 * depends on the hash table implementation. Assuming the hash table operations
 * are worst-case O(N), the solution has the worst time complexity of O(N^2).
 *
 * ## Memory Complexity
 *
 * This solution allocates `N` entries for the map upfront. I could allocate on
 * the fly, but it would complicate keeping track of the entries to free. Also,
 * I think allocating huge chunk of entries is better for cache locality. The
 * map will have at most `N` entries. The solution has the memory complexity of
 * O(N).
 */

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
