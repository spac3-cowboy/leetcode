class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = set()
        negative_nums, positive_nums, zeros = [], [], []
        for num in nums:
            if num > 0:
                positive_nums.append(num)
            elif num < 0: 
                negative_nums.append(num)
            else:
                zeros.append(num)
        NegativeSet, PositiveSet = set(negative_nums), set(positive_nums)

        if zeros:
            for num in PositiveSet:
                if -1*num in NegativeSet:
                    result.add((-1*num, 0, num))

        if len(zeros) >= 3:
            result.add((0,0,0))

        for i in range(len(negative_nums)):
            for j in range(i+1,len(negative_nums)):
                target = -1*(negative_nums[i]+negative_nums[j])
                if target in PositiveSet:
                    result.add(tuple(sorted([negative_nums[i],negative_nums[j],target])))
                    
        for i in range(len(positive_nums)):
            for j in range(i+1,len(positive_nums)):
                target = -1*(positive_nums[i]+positive_nums[j])
                if target in NegativeSet:
                    result.add(tuple(sorted([positive_nums[i],positive_nums[j],target])))

        return result