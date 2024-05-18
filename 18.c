#include <stdlib.h>

int compare(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    *returnSize = 0;
    int** result = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));
    for (int i = 0; i < numsSize - 3; i++) 
    {
        if (i > 0 && nums[i] == nums[i - 1]) 
        {
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++) 
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) 
            {
                continue;
            }
            int start = j + 1, end = numsSize - 1;
            while (start < end) 
            {
                int sum = nums[i] + nums[j] + nums[start] + nums[end];
                if (sum == target) 
                {
                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    (*returnColumnSizes)[*returnSize] = 4;
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[start];
                    result[*returnSize][3] = nums[end];
                    (*returnSize)++;
                    while (start < end && nums[start] == nums[start + 1]) 
                    {
                        start++;
                    }
                    while (start < end && nums[end] == nums[end - 1]) 
                    {
                        end--;
                    }
                    start++;
                    end--;
                } 
                else if (sum < target) 
                {
                    start++;
                } else 
                {
                    end--;
                }
            }
        }
    }
    return result;
}