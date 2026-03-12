# 2026-03-12 刷题总结

今天主要练习了**回溯算法 (Backtracking)** 和 **贪心算法 (Greedy)**。

| 题目 | 链接 | 思路 |
| :--- | :--- | :--- |
| 45. Jump Game II | [Link](https://leetcode.com/problems/jump-game-ii/) | **贪心**：采用反向查找策略，寻找能到达当前位置的最远（最左）起点。 |
| 46. Permutations | [Link](https://leetcode.com/problems/permutations/) | **回溯**：使用 `used` 数组记录已使用的元素，生成全排列。 |
| 51. N-Queens | [Link](https://leetcode.com/problems/n-queens/) | **回溯**：经典 N 皇后问题，逐行放置并校验冲突。 |
| 77. Combinations | [Link](https://leetcode.com/problems/combinations/) | **回溯**：从 `1..n` 中选取 `k` 个数的组合。 |
| 78. Subsets | [Link](https://leetcode.com/problems/subsets/) | **回溯**：求幂集，每个节点都是一个有效的子集。 |
| 79. Word Search | [Link](https://leetcode.com/problems/word-search/) | **DFS + 回溯**：在二维网格中搜索字符串，搜索过程中标记已访问路径。 |
