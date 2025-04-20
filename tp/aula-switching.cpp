#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream fin("test_cases.in");
    // ofstream fout("output.txt");
    int T;
    cin >> T;
    // fin >> T; 

    for(int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m; 

        // leer matriz
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        // implementacion ComputePath()
        cout << "NO" << endl;
    }

    // fin.close();
    // fout.close();
    return 0;
}