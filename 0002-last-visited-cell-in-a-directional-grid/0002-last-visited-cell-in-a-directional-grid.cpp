class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int i = 0, j = 0, m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[i][j] = true;
        
        while (true) {

            int ni = i, nj = j;
            
            if (grid[i][j] == 'L'){
                nj--;
            }
            else if (grid[i][j] == 'R'){
                nj++;
            }

            else if (grid[i][j] == 'U'){
                ni--;
            }

            else if (grid[i][j] == 'D'){
                ni++;
            }

            if (ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni][nj]){
                break;
            }

            i = ni;
            j = nj;
            visited[i][j] = true;

        }
        return {i, j};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna