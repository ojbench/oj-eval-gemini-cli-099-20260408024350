#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dfs(int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c]) {
        return 0;
    }
    visited[r][c] = true;
    int sum = grid[r][c];
    sum += dfs(r + 1, c);
    sum += dfs(r - 1, c);
    sum += dfs(r, c + 1);
    sum += dfs(r, c - 1);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> m >> n)) return 0;
    grid.assign(m, vector<int>(n));
    visited.assign(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int max_fish = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                max_fish = max(max_fish, dfs(i, j));
            }
        }
    }
    
    cout << max_fish << "\n";
    return 0;
}
