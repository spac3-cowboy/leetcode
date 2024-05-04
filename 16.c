#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) 
{
    qsort(nums, numsSize, sizeof(int), compare);

    int closestSum = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < numsSize - 2; i++) {
        int start = i + 1, end = numsSize - 1;
        
        while (start < end) {
            int currentSum = nums[i] + nums[start] + nums[end];
            
            if (currentSum == target) {
                return currentSum;
            }
            
            if (abs(target - currentSum) < abs(target - closestSum)) {
                closestSum = currentSum;
            }
            
            if (currentSum > target) {
                end--;
            } 
            
            else {
                start++;
            }
        }
    }
    return closestSum;
}