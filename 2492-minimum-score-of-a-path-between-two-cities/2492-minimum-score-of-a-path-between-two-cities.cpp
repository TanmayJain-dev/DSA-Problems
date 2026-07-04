class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        int min_score = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        
        // Step 2: Initialize BFS from node 1
        q.push(1);
        visited[1] = true;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (const auto& neighbor : adj[current]) {
                int next_node = neighbor.first;
                int distance = neighbor.second;
                
                // Track the absolute lowest edge weight seen in this component
                min_score = min(min_score, distance);
                
                if (!visited[next_node]) {
                    visited[next_node] = true;
                    q.push(next_node);
                }
            }
        }
        
        return min_score;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna