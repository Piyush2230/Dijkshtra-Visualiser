#include <fstream>  
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int r, c, dist;
    bool operator>(const Node &other) const { return dist > other.dist; }
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dijkstra(vector<vector<int>> &grid, pair<int,int> start, pair<int,int> end) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start.first, start.second, 0});
    dist[start.first][start.second] = 0;

    while (!pq.empty()) {
        auto [r, c, d] = pq.top();
        pq.pop();
        if (d > dist[r][c]) continue;
        if (make_pair(r,c) == end) break;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr<0 || nc<0 || nr>=n || nc>=m) continue;
            if (grid[nr][nc] == 1) continue;
            int newDist = d + 1;
            if (newDist < dist[nr][nc]) {
                dist[nr][nc] = newDist;
                parent[nr][nc] = {r,c};
                pq.push({nr, nc, newDist});
            }
        }
    }

    //Path restoration 
    vector<pair<int,int>> path;
    pair<int,int> cur = end;
    while (cur != make_pair(-1,-1)) {
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());

    // Write data to output file
    ofstream fout("output.txt");
    fout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) fout << grid[i][j] << " ";
        fout << "\n";
    }
    fout << start.first << " " << start.second << "\n";
    fout << end.first << " " << end.second << "\n";
    fout << path.size() << "\n";
    for (auto [r,c] : path) fout << r << " " << c << "\n";
    fout.close();

    cout << "Path written to output.txt successfully!\n";
}

int main() {
    int n = 10, m = 10;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    // Some walls
    for (int i = 3; i <= 7; i++) grid[5][i] = 1;
    for (int i = 2; i <= 6; i++) grid[i][3] = 1;

    pair<int,int> start = {1, 0};
    pair<int,int> end = {6,9};

    dijkstra(grid, start, end);
    return 0;
}
