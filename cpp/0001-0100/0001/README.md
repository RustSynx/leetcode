# 1. Two Sum

[Problem Link](https://leetcode.com/problems/two-sum/description/)

### 💡 Approach & Retrospective

- **Initial Thought (Brute Force):**
  I started with a naive nested loop approach ($O(n^2)$) to ensure correctness. While it passed, I wanted to optimize it further based on the follow-up challenge.

- **Alternative Idea (Sorting):**
  I considered sorting the array to use a **Two-Pointer** method. However, I discarded this idea because preserving the **original indices** becomes cumbersome after sorting, and the trade-off wasn't worth the added complexity.

- **Optimization (Hash Map):**
  I realized that for every number `num`, we simply need to check if `target - num` (the complement) exists.
    - While a linear scan takes $O(n)$, using an **Unordered Map** reduces this lookup to **$O(1)$**.
    - **Result:** This shift in perspective allowed me to achieve a linear time complexity of **$O(n)$** with a single pass.