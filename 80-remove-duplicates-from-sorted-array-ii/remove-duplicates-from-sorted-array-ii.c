int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }

    int left = 2;

    for (int right = 2; right < numsSize; right++) {
        if (nums[right] != nums[left - 2]) {
            nums[left] = nums[right];
            left++;
        }
    }

    return left;
}