#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    
    *returnSize = numsSize;

    // Find the first non-negative element
    int split = 0;

    while (split < numsSize && nums[split] < 0) {
        split++;
    }

    // Number of negative and non-negative elements
    int negativeCount = split;
    int positiveCount = numsSize - split;

    // Create arrays for negative and non-negative parts
    int* negative = (int*)malloc(negativeCount * sizeof(int));
    int* positive = (int*)malloc(positiveCount * sizeof(int));

    // Square negative elements
    for (int i = 0; i < negativeCount; i++) {
        negative[i] = nums[i] * nums[i];
    }

    // Square non-negative elements
    for (int i = 0; i < positiveCount; i++) {
        positive[i] = nums[split + i] * nums[split + i];
    }

    // Reverse negative squared array
    int left = 0;
    int right = negativeCount - 1;

    while (left < right) {
        int temp = negative[left];
        negative[left] = negative[right];
        negative[right] = temp;

        left++;
        right--;
    }

    // Merge the two sorted arrays
    int* result = (int*)malloc(numsSize * sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < negativeCount && j < positiveCount) {

        if (negative[i] <= positive[j]) {
            result[k] = negative[i];
            i++;
        }
        else {
            result[k] = positive[j];
            j++;
        }

        k++;
    }

    // Copy remaining negative elements
    while (i < negativeCount) {
        result[k] = negative[i];
        i++;
        k++;
    }

    // Copy remaining positive elements
    while (j < positiveCount) {
        result[k] = positive[j];
        j++;
        k++;
    }

    free(negative);
    free(positive);

    return result;
}