# [Largest Unblocked Submatrix](https://www.geeksforgeeks.org/problems/largest-unblocked-submatrix/1)
## Medium
You are given integers n and m, and an array arr[][] of size k, where arr[i] = [r, c] represents a blocked cell in an n × m grid.
Each blocked cell blocks its entire row and column. Find the largest continuous unblocked area in the grid.
Note: No two blocked cells are in the same row or the same column.
Examples:
Input: n = 2, m = 2, k = 1, arr[][] = [[2, 2]]
Output: 1
Explanation: Since only (1,1) cell is free from the enemy hence answer is 1.
Input: n = 3, m = 3, k = 1, arr[][] = [[3, 3]]
Output: 4
Explanation: The cells (1,1), (1,2), (2,1) and (2,2) are free hence answer is 4.
Constraints:1 ≤ n, m ≤ 1040 ≤ k ≤ min(n, m)1 ≤ r&nbsp;≤&nbsp;n1 ≤ c&nbsp;≤ m