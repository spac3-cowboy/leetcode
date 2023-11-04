class Solution:
    def distinctSequences(self, n: int) -> int:
        import math

        MOD = 10**9 + 7

        dp = [[[0]*7 for _ in range(7)] for _ in range(n+1)]
        
        for i in range(1, 7):
            dp[1][0][i] = 1
        for i in range(2, n+1):
            for j in range(7):
                for k in range(1, 7):
                    for l in range(1, 7):
                        if math.gcd(k, l) == 1 and j != l:
                            dp[i][k][l] = (dp[i][k][l] + dp[i-1][j][k]) % MOD
        
        return sum(sum(dp[n][j]) for j in range(7)) % MOD