class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0

        dp = [0] * (len(s) + 1)
        dp[0] = dp[1] = 1

        for i in range(2, len(s) + 1):
            if s[i-1] != '0':
                dp[i] += dp[i-1]
            if '10' <= s[i-2:i] <= '26':
                dp[i] += dp[i-2]

        return dp[-1]
    
sol = Solution()
print(sol.numDecodings("12"))  # Expected output: 2
print(sol.numDecodings("226"))  # Expected output: 3
print(sol.numDecodings("06"))  # Expected output: 0