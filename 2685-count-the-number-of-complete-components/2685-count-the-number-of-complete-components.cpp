class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& vertex_count, int& edge_count) {
        visited[node] = true;
        vertex_count++;
        edge_count += adj[node].size();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, vertex_count, edge_count);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int complete_components = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertex_count = 0;
                int edge_count = 0;

                dfs(i, adj, visited, vertex_count, edge_count);

                if (edge_count == vertex_count * (vertex_count - 1)) {
                    complete_components++;
                }
            }
        }

        return complete_components;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna