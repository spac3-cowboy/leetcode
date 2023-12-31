from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def dfs(start, path):
            res.append(list(path))
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i - 1]:
                    continue
                path.append(nums[i])
                dfs(i + 1, path)
                path.pop()

        nums.sort()
        res = []
        dfs(0, [])
        return res


sol = Solution()
print(
    sol.subsetsWithDup([1, 2, 2])
)  # Expected output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
print(sol.subsetsWithDup([0]))  # Expected output: [[],[0]]