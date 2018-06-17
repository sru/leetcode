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
 * This is a straightforward solution with nested loop. The outer loop finds the
 * first index and the inner loop finds the second index.
 *
 * ## Time Complexity
 *
 * Since there are `N choose 2`, `N * (N - 1) / 2`, such combinations of inputs,
 * the time complexity is O(N^2), where `N` is the number of elements.
 *
 * ## Space Complexity
 *
 * There is no additional space required besides the indices, so the space
 * complexity is O(1).
 */
int* twoSum(int* nums, int numsSize, int target) {

    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }

    return NULL;
}
