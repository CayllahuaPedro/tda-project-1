#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXM = 1000;
const int OFFSET = 1000;  

bool hasValidPathPD(const vector<vector<int>>& grid, vector<vector<bitset<2002>>>& visited, 
                   const int i, const int j, const int sum, const int n, const int m)
{
    if (abs(sum) > OFFSET) return false;
    
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    
    int idx = sum + OFFSET;
    if (idx < 0 || idx >= 2002) return false;
    
    if (visited[i][j][idx]) return false;
        
    if (i == n-1 && j == m-1)
        return sum + grid[i][j] == 0;
        
    visited[i][j][idx] = true;
    
    int newSum = sum + grid[i][j];
    if (abs(newSum) > OFFSET) return false;
    
    return (j + 1 < m && hasValidPathPD(grid, visited, i, j + 1, newSum, n, m)) ||
           (i + 1 < n && hasValidPathPD(grid, visited, i + 1, j, newSum, n, m));
}

bool canChangeAulas(const vector<vector<int>>& grid, const int n, const int m)
{
    if (n <= 0 || m <= 0 || n > MAXN || m > MAXM) return false;
    if ((n + m) % 2 == 0) return false;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(abs(grid[i][j]) != 1) return false;
        }
    }
    
    vector<vector<bitset<2002>>> visited(n, vector<bitset<2002>>(m));
    return hasValidPathPD(grid, visited, 0, 0, 0, n, m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num_cases;
    cin >> num_cases;
    
    while (num_cases--)
    {
        int n, m;
        cin >> n >> m;
        
        if (n <= 0 || m <= 0 || n > MAXN || m > MAXM) {
            cout << "NO\n";
            continue;
        }
        
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cout << (canChangeAulas(grid, n, m) ? "YES" : "NO") << "\n";
    }
    return 0;
}