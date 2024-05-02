class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.lstrip()  # Remove leading whitespaces
        if not str: return 0  # Return 0 if string is empty

        sign = -1 if str[0] == '-' else 1
        if str[0] in ['-', '+']: str = str[1:]  # Remove the sign character

        value = 0
        for ch in str:
            if not ch.isdigit(): break  # Stop when a non-digit character is encountered
            value = value * 10 + int(ch)
            if value > 2**31 - 1: return 2**31 - 1 if sign == 1 else -2**31  # Check for overflow/underflow

        return sign * value