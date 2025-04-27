#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T> istream &operator >> (istream &in, vector<T> &v){
    for (auto &e:v)
        in >> e;
    return in;
}
template<typename T> ostream &operator << (ostream &out, vector<T> v){
    for (auto &e:v)
        out << e << ' ';
    return out;
}

vector<pair<int, int>> dir = {{0, -1}, {-1, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &s:grid)
        cin >> s;
    
    auto invalid = [&](int i, int j) -> bool {
        return i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 'X';
    };

    int ans = 0;
    auto floodfill = [&](int i, int j) -> void {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()){
            auto [i, j] = q.front(); q.pop();
            if (grid[i][j] == 'X') continue;
            grid[i][j] = 'X';
            ans++;
            for (auto [di, dj]:dir){
                if (invalid(i + di, j + dj)) continue;
                q.push({i + di, j + dj});
            }
        }
    };
    floodfill(n - 1, n - 1);
    cout << ans << '\n';
}