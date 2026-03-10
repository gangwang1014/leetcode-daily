# 2026-03-10

- 19. Remove Nth Node From End of List  
  https://leetcode.com/problems/remove-nth-node-from-end-of-list/  
  思路：用虚拟头结点，快指针先走 n 步，再与慢指针同步前进到末尾，删除慢指针后继。  
  复杂度：时间 O(n)，空间 O(1)。

- 25. Reverse Nodes in k-Group  
  https://leetcode.com/problems/reverse-nodes-in-k-group/  
  思路：先探测是否有 k 个节点，不足直接返回；对 [head, tail) 迭代反转，再递归处理剩余部分并拼接。  
  复杂度：时间 O(n)，空间 O(n/k) 递归栈。

- 105. Construct Binary Tree from Preorder and Inorder Traversal  
  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/  
  思路：前序首元素为根，在中序中定位根划分左右子树区间，递归构建。  
  复杂度：时间 O(n^2)（当前实现为线性查找根），空间 O(h)。

- 141. Linked List Cycle  
  https://leetcode.com/problems/linked-list-cycle/  
  思路：快慢指针（Floyd 判环），相遇则有环。  
  复杂度：时间 O(n)，空间 O(1)。

- 142. Linked List Cycle II  
  https://leetcode.com/problems/linked-list-cycle-ii/  
  思路：先用 Floyd 判环，相遇后从头结点与慢指针同步前进，相遇点即入环点。  
  复杂度：时间 O(n)，空间 O(1)。

- 148. Sort List  
  https://leetcode.com/problems/sort-list/  
  思路：链表归并排序，快慢指针拆分为两段，递归排序后合并。  
  复杂度：时间 O(n log n)，空间 O(log n)。

- 226. Invert Binary Tree  
  https://leetcode.com/problems/invert-binary-tree/  
  思路：递归交换左右子树。  
  复杂度：时间 O(n)，空间 O(h)。
