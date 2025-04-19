class Solution {
public:
    /**
     * Depth-First Search (DFS) helper to count how many bombs can be detonated starting from bomb i.
     *
     * @param i Current bomb index.
     * @param mp Adjacency list representing which bombs can trigger others.
     * @param visited Boolean vector to keep track of visited bombs.
     * @param n Total number of bombs.
     * @param count Reference to count how many bombs get detonated.
     */
    void dfs(int i, unordered_map<int, vector<int>>& mp, vector<bool>& visited, int n, int &count) {
        count++;
        visited[i] = true;

        for (int a : mp[i]) {
            if (!visited[a]) {
                dfs(a, mp, visited, n, count);
            }
        }
    }

    /**
     * Calculates the square of Euclidean distance between two points (no need for sqrt).
     *
     * @param x1 X-coordinate of point 1
     * @param y1 Y-coordinate of point 1
     * @param x2 X-coordinate of point 2
     * @param y2 Y-coordinate of point 2
     * @return Squared distance between the two points
     */
    long long euclidian(long long x1, long long y1, long long x2, long long y2) {
        return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    /**
     * Main function to determine the maximum number of bombs that can be detonated in a chain reaction.
     *
     * @param bombs A vector of bombs where each bomb is represented as [x, y, radius].
     * @return The maximum number of bombs that can be detonated starting from any one bomb.
     */
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: Build the graph - create directed edges if one bomb is within another's range
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = 0; j < bombs.size(); j++) {
                if (i == j) continue;

                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long radius = bombs[i][2];

                long long distance = euclidian(x1, y1, x2, y2);
                if (radius * radius >= distance) {
                    mp[i].push_back(j); // Bomb i can trigger bomb j
                }
            }
        }

        int maxans = 0;

        // Step 2: Try detonating from each bomb and count the result
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int count = 0;
            dfs(i, mp, visited, n, count);
            maxans = max(maxans, count);
        }

        return maxans;
    }
};
