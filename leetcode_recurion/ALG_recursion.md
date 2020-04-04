# 递归(Recursion)

LeetCode刷题大神的博客    [Grandyang](https://www.cnblogs.com/grandyang/default.html?page=7)

LeetCode Recursion I card [Recursion I](https://leetcode.com/explore/learn/card/recursion-i/)  刷完这个感觉对使用递归算法有了基本的自信。



### Why Recursion

优雅，简单，可根据**递推关系**求问题的解 (**Recurrence Relation**)

例如**费波那契数列(Fibonacci)** 我们知道(或推导)出其递推关系为:

$Fib_n = Fib_{n-1}+ Fib_{n-2}$

并定义 $Fib_1 = 1 $  $ Fib_2 = 2$

因其通项公式是相对难以计算的，通过递归，我们可以只求球的$Fib_n$的解



### Principle of Recursion

A recursive function should have the following properties so that it does not result in an infinite loop:

1. A simple `base case` (or cases) — a terminating scenario that **does not use recursion to produce an answer.**
2. A set of rules, also known as `recurrence relation` that **reduces all other cases towards the base case.**

总结来说，设计递归函数就是要寻找 **1.不使用递归也能解决问题的情况**  和每次调用递归函数 **2.任务与子任务之间的联系** 。



### 使用递归求解问题

1. Reverse String

2. Swap Nodes in Pairs(链表中逆序两两成对的元素)

   ![](https://raw.githubusercontent.com/papinnon/storage/master/20200404190443.png)

3. Reverse Linked List

4. Search In Binary Search Tree

5. Pascal's Triangle 

   ![](https://raw.githubusercontent.com/papinnon/storage/master/20200404190643.png)

6. Climbing Stairs(Fibonacci)
7. Max Depth of a Binary Search Tree
8. Merge two sorted List
9. K-th Symbol in Grammar
10. **Unique Binary Search II**