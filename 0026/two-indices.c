int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2) {
        return numsSize;
    }

    int len = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[len - 1] != nums[i]) {
            nums[len++] = nums[i];
        }
    }

    return len;
}
