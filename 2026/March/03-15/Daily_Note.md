# LeetCode 刷题记录 - 2026-03-15

## 今日主题：堆 / 优先队列

---

## 215. Kth Largest Element in an Array

**题目链接**: https://leetcode.com/problems/kth-largest-element-in-an-array/

**思路**:
- 方法一：小顶堆，维护 k 个元素，堆顶即为第 k 大
- 方法二：快速选择算法，平均 O(n) 时间复杂度

**关键点**:
- 快速选择基于快排的 partition 思想
- 找第 k 大等价于找第 (n-k) 小
- 时间复杂度：堆 O(n log k)，快选平均 O(n)

---

## 347. Top K Frequent Elements

**题目链接**: https://leetcode.com/problems/top-k-frequent-elements/

**思路**:
- 先用哈希表统计每个元素出现频率
- 再用小顶堆维护前 k 高频元素
- 堆按频率排序，大小超过 k 时弹出最小频率

**关键点**:
- 自定义比较器：`decltype(comp)` 获取 lambda 类型
- 时间复杂度：O(n log k)
- 空间复杂度：O(n)

---

## 373. Find K Pairs with Smallest Sums

**题目链接**: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

**思路**:
- 多路归并思想：固定 nums1 的下标，扩展 nums2 的下标
- 初始时将 nums1 前 min(k, n) 个元素与 nums2[0] 配对入堆
- 每次取出最小和的配对，然后将该 nums1 元素与 nums2 下一个元素配对入堆

**关键点**:
- 堆中存储下标而非实际值，避免重复计算
- 时间复杂度：O(k log k)
- 空间复杂度：O(k)

---

## 295. Find Median from Data Stream

**题目链接**: https://leetcode.com/problems/find-median-from-data-stream/

**思路**:
- 双堆法：大顶堆存较小的一半，小顶堆存较大的一半
- 大顶堆 `queMin_` 存 <= 中位数的数
- 小顶堆 `queMax_` 存 > 中位数的数
- 保持 `queMin_.size() >= queMax_.size()` 且差值不超过 1

**关键点**:
- 大顶堆用 `less<int>`（默认），小顶堆用 `greater<int>`
- 新元素根据与 `queMin_.top()` 的比较决定入哪个堆
- 入堆后需平衡两个堆的大小
- addNum: O(log n)，findMedian: O(1)

---

## 703. Kth Largest Element in a Stream

**题目链接**: https://leetcode.com/problems/kth-largest-element-in-a-stream/

**思路**:
- 使用小顶堆维护前 k 大的元素
- 堆大小保持为 k，堆顶就是第 k 大的元素
- 每次 add 后弹出多余的元素，返回堆顶

**关键点**:
- 时间复杂度：初始化 O(n log k)，add O(log k)
- 空间复杂度：O(k)

---

## 总结

今日 5 题均为**堆/优先队列**经典题目：

| 题目 | 核心技巧 | 复杂度 |
|------|----------|--------|
| 215 | 小顶堆 / 快速选择 | O(n) ~ O(n log k) |
| 347 | 哈希表 + 小顶堆 | O(n log k) |
| 373 | 多路归并 + 堆 | O(k log k) |
| 295 | 双堆法 | add O(log n) |
| 703 | 小顶堆 | add O(log k) |

**核心思想**：堆适合维护「前 k 个」或「动态中位数」问题，小顶堆维护前 k 大，大顶堆维护前 k 小。