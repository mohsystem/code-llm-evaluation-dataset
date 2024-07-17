class Solution:
    def persistence(self, n):
        if n < 10:
            return 0
        count = 0
        while n >= 10:
            temp = 1
            for digit in str(n):
                temp *= int(digit)
            n = temp
            count += 1
        return count