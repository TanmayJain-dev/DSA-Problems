# [Min Edge Movements to Connect a Graph](https://www.geeksforgeeks.org/problems/connecting-the-graph/1)
## Medium
Given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between&nbsp;any two vertices in one operation. 
Find the minimum number of operations required to connect the graph. If it is not possible to connect the graph, return -1.
Examples:&nbsp;
Input: n = 4, edges[][] = [[0, 1], [0, 2], [1, 2]]Output: 1Explanation: Remove edge&nbsp;between vertices&nbsp;1 and 2 and add&nbsp;between vertices&nbsp;1 and 3.
Input: n = 6, edges[][] = [[0,1], [0,2], [0,3], [1,2], [1,3]]Output: 2Explanation: Remove edge between (1,2) and (0,3), and add edge between (1,4) and (3,5)