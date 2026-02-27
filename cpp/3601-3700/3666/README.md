# 3666. Minimum Operations to Equalize Binary String

[Problem Link](https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/description/)

### Review

Initially, I expected a simple mathematical approach to work.
But as the `if` clause piled up, and the code became overly complex, I realized I needed a different strategy.
I tried implementing `BFS`, but I ran into a `TLE` issue.
After optimizing the process using a `set` to handle lookups faster, I was able to solve the problem.