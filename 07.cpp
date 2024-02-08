class Solution {
public:
    int reverse(int x) {
        // Initialize reversed_num to hold the reversed number
        long long reversed_num = 0;

        // Define the maximum and minimum possible values for an int
        int INT_MAX, INT_MIN;
        int max_int = INT_MAX;
        int min_int = INT_MIN;

        // Loop until x becomes 0
        while (x) {
            // Check if reversing the next digit causes overflow
            if (reversed_num > max_int / 10 || (reversed_num == max_int / 10 && x % 10 > 7)) {
                return 0;
            }
            // Check if reversing the next digit causes underflow
            if (reversed_num < min_int / 10 || (reversed_num == min_int / 10 && x % 10 < -8)) {
                return 0;
            }
            // Add the last digit of x to reversed_num after shifting its digits one place to the left
            reversed_num = reversed_num * 10 + x % 10;

            // Remove the last digit from x
            x /= 10;
        }

        // Return the reversed number
        return reversed_num;
    }
};
