class Solution {
public:
    int distinctSequences(int n) {
        // Define the modulo constant
        static const int MOD = 1e9 + 7;

        // Base case: if n is 1, there are 6 distinct sequences
        if (n == 1) {
            return 6;
        }

        // Initialize the dynamic programming table
        vector<vector<int>> dp(6, vector<int>(6));

        // Fill the dynamic programming table
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                // If i and j are coprime, set dp[i][j] to 1
                if (i != j && gcd(i + 1, j + 1) == 1) {
                    dp[i][j] = 1;
                }
            }
        }

        // Iterate over the remaining elements
        for (int _ = 0; _ < n - 2; ++_) {
            // Initialize a new dynamic programming table for the next iteration
            vector<vector<int>> new_dp(6, vector<int>(6));

            // Update the new dynamic programming table
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    // If dp[i][j] is 0, skip this iteration
                    if (!dp[i][j]) {
                        continue;
                    }
                    for (int k = 0; k < 6; ++k) {
                        // If dp[j][k] is 0, skip this iteration
                        if (!dp[j][k]) {
                            continue;
                        }
                        // If k is not equal to i, update new_dp[i][j]
                        if (k != i) {
                            new_dp[i][j] = (new_dp[i][j] + dp[j][k]) % MOD;
                        }
                    }
                }
            }

            // Move the new dynamic programming table to dp for the next iteration
            dp = move(new_dp);
        }

        // Return the sum of all elements in dp modulo MOD
        return accumulate(cbegin(dp), cend(dp), 0,
                          [&](int total, const auto& x) {
                              return (total + accumulate(cbegin(x), cend(x), 0,
                                                         [&](int total, int x) {
                                                             return (total + x) % MOD;
                                                         })) % MOD;
                          });
    }
};class Solution {
public:
    int distinctSequences(int n) {
        // Define the modulo constant
        static const int MOD = 1e9 + 7;

        // Base case: if n is 1, there are 6 distinct sequences
        if (n == 1) {
            return 6;
        }

        // Initialize the dynamic programming table
        vector<vector<int>> dp(6, vector<int>(6));

        // Fill the dynamic programming table
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                // If i and j are coprime, set dp[i][j] to 1
                if (i != j && gcd(i + 1, j + 1) == 1) {
                    dp[i][j] = 1;
                }
            }
        }

        // Iterate over the remaining elements
        for (int _ = 0; _ < n - 2; ++_) {
            // Initialize a new dynamic programming table for the next iteration
            vector<vector<int>> new_dp(6, vector<int>(6));

            // Update the new dynamic programming table
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    // If dp[i][j] is 0, skip this iteration
                    if (!dp[i][j]) {
                        continue;
                    }
                    for (int k = 0; k < 6; ++k) {
                        // If dp[j][k] is 0, skip this iteration
                        if (!dp[j][k]) {
                            continue;
                        }
                        // If k is not equal to i, update new_dp[i][j]
                        if (k != i) {
                            new_dp[i][j] = (new_dp[i][j] + dp[j][k]) % MOD;
                        }
                    }
                }
            }

            // Move the new dynamic programming table to dp for the next iteration
            dp = move(new_dp);
        }

        // Return the sum of all elements in dp modulo MOD
        return accumulate(cbegin(dp), cend(dp), 0,
                          [&](int total, const auto& x) {
                              return (total + accumulate(cbegin(x), cend(x), 0,
                                                         [&](int total, int x) {
                                                             return (total + x) % MOD;
                                                         })) % MOD;
                          });
    }
};