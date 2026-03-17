# 2026-03-17 二分查找专题

## 1. [704. 二分查找](https://leetcode.cn/problems/binary-search/)

**难度**: 🟢 简单

**思路**: 标准二分查找模板

**解题要点**:
- `left <= right` 的循环条件
- `mid = left + (right - left) / 2` 防止溢出
- 找到返回下标，否则返回 -1

---

## 2. [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)

**难度**: 🟡 中等

**思路**: 分别用二分查找左边界和右边界

**解题要点**:
- `find_left`: `nums[mid] >= target` 时收缩右边界，最终 `left` 为第一个 `>= target` 的位置
- `find_right`: `nums[mid] <= target` 时收缩左边界，最终 `right` 为最后一个 `<= target` 的位置
- 边界检查：如果 `left` 越界或 `nums[left] != target`，说明元素不存在

---

## 3. [33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/)

**难度**: 🟡 中等

**思路**: 旋转后数组分成两段有序区间，先判断 mid 落在哪段，再判断 target 是否在该段内

**解题要点**:
- 通过 `nums[left] <= nums[mid]` 判断左半边是否有序
- 若左半边有序：判断 target 是否在 `[left, mid)` 范围内，决定收缩方向
- 若右半边有序：判断 target 是否在 `(mid, right]` 范围内，决定收缩方向
- 时间复杂度 O(log n)

---

## 4. [162. 寻找峰值](https://leetcode.cn/problems/find-peak-element/)

**难度**: 🟡 中等

**思路**: 隐式二分，根据相邻元素关系判断峰值在哪一侧

**解题要点**:
- 数组两端可视为 `-∞`，所以一定存在峰值
- 若 `nums[mid] > nums[mid+1]`，说明峰值在左半边（包括 mid），`right = mid`
- 否则峰值在右半边，`left = mid + 1`
- 循环条件 `left < right`，最终 `left == right` 即为峰值

---

## 5. [875. 爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas/)

**难度**: 🟡 中等

**思路**: 二分答案（最小速度 k），配合 check 函数判断是否能在 h 小时内吃完

**解题要点**:
- 速度范围：`left = 1`, `right = max(piles)`
- check 函数：计算以速度 k 吃完所有香蕉需要的时间（向上取整：`(pile + k - 1) / k` 或 `ceil(1.0 * pile / k)`）
- 若能在 h 小时内吃完，尝试更小速度 `right = mid`
- 否则需要更大速度 `left = mid + 1`
- 时间复杂度 O(n log m)，n 为 piles 数量，m 为最大香蕉数

---

## 二分查找总结

| 类型 | 循环条件 | 更新方式 | 适用场景 |
|------|---------|---------|---------|
| 标准二分 | `left <= right` | `left = mid + 1` / `right = mid - 1` | 查找精确值 |
| 左边界 | `left <= right` | `left = mid + 1` / `right = mid - 1`，返回 `left` | 找第一个 >= target |
| 右边界 | `left <= right` | `left = mid + 1` / `right = mid - 1`，返回 `right` | 找最后一个 <= target |
| 隐式二分/答案二分 | `left < right` | `left = mid + 1` / `right = mid` 或相反 | 找峰值、二分答案 |

**关键点**:
1. 防溢出：`mid = left + (right - left) / 2`
2. 边界条件：根据问题选择合适的循环条件和更新方式
3. 二分答案：适用于答案具有单调性的场景（如本题 875）