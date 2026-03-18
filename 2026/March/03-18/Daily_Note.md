# LeetCode 每日练习笔记 (2026-03-18)

## 题目概览

| 题号 | 题目名称 | 难度 | 核心技巧 | 状态 |
| :--- | :--- | :--- | :--- | :--- |
| 74 | [搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix/) | 🟢 简单 | 矩阵展开 / 映射技巧 | [ ] |
| 240 | [搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/) | 🟡 中等 | Z 字形查找 / 二分进阶 | [ ] |
| 153 | [寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/) | 🟡 中等 | 边界收缩逻辑 | [ ] |
| 4 | [寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/) | 🔴 困难 | 第 K 小元素 / 二分切分 | [ ] |
| 410 | [分割数组的最大值](https://leetcode.cn/problems/split-array-largest-sum/) | 🔴 困难 | 二分答案 (最小化最大值) | [ ] |

---

## 详细分析

### 1. [74. 搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix/)
*   **解题思路**：由于矩阵每行已排序且下一行首元素大于上一行末元素，可将 2D 矩阵逻辑上视为一个 1D 有序数组。
*   **关键公式**：`matrix[index / n][index % n]`，其中 `n` 为列数。
*   **关注重点**：直接进行标准二分查找即可。注意空矩阵或单元素边界。

### 2. [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)
*   **解题思路**：矩阵每行每列虽有序但整体不满足单调性。从右上角 (0, n-1) 或左下角 (m-1, 0) 开始查找。
*   **关键逻辑**：若当前值 > target，则列左移；若当前值 < target，则行下移。
*   **关注重点**：为什么从右上/左下出发？因为这两个点可以将移动方向唯一确定（一个是变大/变小，另一个也是）。

### 3. [153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/)
*   **解题思路**：旋转数组分为两个递增段。二分的目的是找到那个“断层”点。
*   **关键比较**：比较 `nums[mid]` 与 `nums[right]`。
    *   `nums[mid] > nums[right]`：最小值在右半段（不含 mid）。
    *   `nums[mid] < nums[right]`：最小值在左半段（含 mid）。
*   **关注重点**：循环条件 `left < right` 和收缩逻辑 `right = mid`。

### 4. [4. 寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)
*   **解题思路**：通过二分切分两个数组，使得左侧元素总数等于右侧元素总数（或多 1），且满足左侧最大值 <= 右侧最小值。
*   **关键技巧**：在较短的数组上进行二分以优化效率 O(log(min(m, n)))。
*   **关注重点**：边界值（INT_MIN/INT_MAX）的处理以及偶数/奇数总和的情况。

### 5. [410. 分割数组的最大值](https://leetcode.cn/problems/split-array-largest-sum/)
*   **解题思路**：典型的“二分答案”题目。答案的范围在 `[max(nums), sum(nums)]` 之间。
*   **关键逻辑**：判断一个给定的“最大和” `limit` 是否能通过将数组分为不超过 `k` 段来实现。
*   **关注重点**：贪心检查函数的实现。

---

## 今日总结 & 反思
*   **核心主题**：**二分查找的变体应用**。
*   从简单的 1D 二分，进化到 2D 坐标转换，再到非典型单调性的 Z 字形搜索，最后到“二分答案”这一重要的高级技巧。
*   **待突破点**：第 4 题的切分逻辑极其容易出错，建议手动模拟切分过程。
