class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
      
        dist[0][0] = grid[0][0];
      
        queue<pair<int, int>> bfsQueue;
        bfsQueue.emplace(0, 0);
      
        int dirs[5] = {-1, 0, 1, 0, -1};
      
        while (!bfsQueue.empty()) {
            auto [currentX, currentY] = bfsQueue.front();
            bfsQueue.pop();
          
            for (int i = 0; i < 4; ++i) {
                int nextX = currentX + dirs[i];
                int nextY = currentY + dirs[i + 1];
              
                if (nextX >= 0 && nextX < rows && 
                    nextY >= 0 && nextY < cols && 
                    dist[nextX][nextY] > dist[currentX][currentY] + grid[nextX][nextY]) {
                  
                    dist[nextX][nextY] = dist[currentX][currentY] + grid[nextX][nextY];
                  
                    bfsQueue.emplace(nextX, nextY);
                }
            }
        }
        return dist[rows - 1][cols - 1] < health;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna