# 2026-03-16 算法总结

## 主题：贪心算法

---

### 1. [455. 分发饼干](https://leetcode.cn/problems/assign-cookies/)

**难度**：🟢 简单

**思路**：排序 + 贪心匹配
- 将孩子胃口 `g` 和饼干尺寸 `s` 分别排序
- 双指针遍历，小饼干优先满足小胃口孩子
- 若饼干满足当前孩子，则两者都前进；否则只前进饼干指针

**代码要点**：
```cpp
sort(g.begin(), g.end());
sort(s.begin(), s.end());
// 双指针匹配
```

---

### 2. [55. 跳跃游戏](https://leetcode.cn/problems/jump-game/)

**难度**：🟡 中等

**思路**：维护最远可达范围
- 遍历数组，维护 `max_reachable` 表示当前能到达的最远位置
- 若当前下标 `i > max_reachable`，说明无法到达，返回 false
- 否则更新 `max_reachable = max(max_reachable, i + nums[i])`

**代码要点**：
```cpp
if (i > max_reachable) return false;
max_reachable = max(max_reachable, i + nums[i]);
```

---

### 3. [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)

**难度**：🟡 中等

**思路**：贪心边界 + 最少跳跃次数
- 维护 `farthest`（当前跳跃能到达的最远位置）和 `end`（当前跳跃边界）
- 遍历过程中不断更新 `farthest`
- 当到达 `end` 边界时，必须跳跃一次，更新边界为 `farthest`

**代码要点**：
```cpp
if (i == end) {
    end = farthest;
    ++jumps;
}
```

---

### 4. [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/)

**难度**：🟡 中等

**思路**：区间调度 / 贪心排序
- 按区间右端点排序（保证结束最早的在前）
- 贪心选择不重叠的区间，计数保留的区间数
- 答案 = 总区间数 - 保留的区间数

**代码要点**：
```cpp
sort(intervals.begin(), intervals.end(),
     [](const vector<int>& a, const vector<int>& b) {
         return a[1] < b[1];
     });
// 贪心选择不重叠区间
```

---

### 5. [135. 分发糖果](https://leetcode.cn/problems/candy/)

**难度**：🟡 中等

**思路**：两次遍历
- 第一次从左到右：若右边评分更高，则右边糖果 = 左边 + 1
- 第二次从右到左：若左边评分更高，则左边糖果 = max(当前, 右边 + 1)
- 最后求和

**代码要点**：
```cpp
// 左到右
if (ratings[i] > ratings[i - 1])
    candies[i] = candies[i - 1] + 1;
// 右到左
if (ratings[i] > ratings[i + 1])
    candies[i] = max(candies[i], candies[i + 1] + 1);
```

---

## 总结

贪心算法的核心：**局部最优 → 全局最优**

| 题目 | 贪心策略 |
|------|----------|
| 455 | 小饼干喂小胃口 |
| 55 | 维护最远可达 |
| 45 | 每次跳到能到的最远位置 |
| 435 | 选结束最早的区间 |
| 135 | 分别从左右两个方向保证条件 |