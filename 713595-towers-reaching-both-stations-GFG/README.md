# [Towers Reaching Both Stations](https://www.geeksforgeeks.org/problems/geeks-island--170646/1)
## Medium
Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal strength of a communication tower. Two control stations monitor the network:

Station P covers the top and left boundaries of the grid.
Station Q covers the bottom and right boundaries of the grid.

A signal can propagate from a tower to one of its neighbouring towers in the four directions (North, South, East, and West) only if the neighbouring tower has a signal strength less than or equal to that of the current tower.
Determine the number of towers (x, y) from which a signal can eventually reach both Station P and Station Q. Any tower located on a boundary covered by a station can transmit directly to that station.
Examples:
Input: mat[][] = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
Output: 7
Explanation: (0, 4) &amp; (4, 0) are part of both P &amp; Q (1, 3) reaches P using (1,3)-&gt;(0,3) and Q using (1,3)-&gt;(1,4)(1, 4) reaches P using (1,4)-&gt;(1,3)-&gt;(1,2)-&gt;(0,2) and it is on Q(2, 2) reaches P using (2,2)-&gt;(2,1)-&gt;(2,0) and Q using (2,2)-&gt;(2,3)-&gt;(2,4)(3, 0) is on P and reaches Q using (3,0)-&gt;(4,0)(3, 1) reaches P using (3,1)-&gt;(3,0) and Q using (3,1)-&gt;(4,1)
Input: mat[][] = [[2, 2], [2, 2]]
Output: 4
Explanation: In the following example, all cells allow signals to propagate to both the stations.
Constraints:1 ≤ n, m ≤ 1031 ≤ mat[i][j] ≤ 103&nbsp;