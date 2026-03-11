# 2026-03-11 每日练习笔记

今天主要练习了 **栈 (Stack)**、**单调栈 (Monotonic Stack)** 和 **动态规划 (DP)** 相关的经典题目。

| 题目 | 链接 | 思路简述 |
| :--- | :--- | :--- |
| 5. Longest Palindromic Substring | [LeetCode 5](https://leetcode.com/problems/longest-palindromic-substring/) | **动态规划**：使用二维布尔数组 `dp[i][j]` 表示从 `i` 到 `j` 的子串是否为回文。状态转移方程：`s[i] == s[j] && dp[i+1][j-1]`。 |
| 20. Valid Parentheses | [LeetCode 20](https://leetcode.com/problems/valid-parentheses/) | **栈**：遇到左括号入栈，遇到右括号则检查栈顶元素是否匹配并弹出。最后检查栈是否为空。 |
| 155. Min Stack | [LeetCode 155](https://leetcode.com/problems/min-stack/) | **辅助栈/集合**：在普通栈的基础上，使用辅助栈或有序集合（如 `std::multiset`）同步维护当前的最小值。 |
| 84. Largest Rectangle in Histogram | [LeetCode 84](https://leetcode.com/problems/largest-rectangle-in-histogram/) | **单调栈**：维护一个高度递增的下标栈。当遇到比栈顶高度小的柱子时，开始结算栈内高度能组成的矩形面积。 |
| 150. Evaluate Reverse Polish Notation | [LeetCode 150](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | **栈**：逆波兰表达式求值。遇到数字入栈，遇到运算符从栈中弹出两个操作数进行运算，并将结果压回栈中。 |
| 232. Implement Queue using Stacks | [LeetCode 232](https://leetcode.com/problems/implement-queue-using-stacks/) | **双栈**：使用 `in_stk` 处理输入，`out_stk` 处理输出。当 `out_stk` 为空时，将 `in_stk` 的元素全部倒入。 |
| 239. Sliding Window Maximum | [LeetCode 239](https://leetcode.com/problems/sliding-window-maximum/) | **单调队列**：使用双端队列 `deque` 维护窗口内可能成为最大值的下标，保持队列下标对应的元素值单调递减。 |

---
*注：`0055_Min_Stack.cpp` 对应的代码实现为 LeetCode 155. Min Stack。*
