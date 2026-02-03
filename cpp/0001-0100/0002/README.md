# 1. Add Two Numbers

[Problem Link](https://leetcode.com/problems/add-two-numbers/description/)

### 💡 Approach & Retrospective

- **Core Challenge (Memory Management)**: This problem was a wake-up call to revisit Dynamic Memory Management.
  - I initially thought I had a solid grasp of it, but practical application revealed my skills were rustier than expected, leading to severe memory leaks.
  - Although strict memory management isn't always mandatory in coding tests, I spent extra time fixing these leaks to maintain disciplined coding habits.

- **Debugging (Logic Error)**: I encountered a submission failure due to a logical error in the execution sequence.
  - I confused the order of operations when processing the nodes.
  - Fix: I re-evaluated the flow and corrected the sequence to handle the carry and node connection properly.

- **Future Improvement (Refactoring)**: The current solution works, but it lacks elegance and readability.
  - Since debugging took longer than planned, I prioritized correctness over style. 
  - Goal: In the future, I plan to refactor the code to be cleaner and more intuitive (e.g., removing the std::deque dependency).