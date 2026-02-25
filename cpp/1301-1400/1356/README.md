# 1356. Sort Integers by The Number of 1 Bits

[Problem Link](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/)

### Review

While solving this problem, I learned about Brian Kernighan's Algorithm `n & (n - 1)`.
In addition, I decided to use the built-in function `__builtin_popcount` to make the code cleaner.