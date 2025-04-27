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

vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, 
                              {1, 1}, {1, 0}, {1, -1}, {0, -1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r, sta, stb;
    cin >> n >> m >> sta >> stb >> r;
    sta++, stb++;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    struct A {
        int i, j, w;
    };
    queue<A> q;
    for (int i = 0;i < r;i++){
        int x, y;
        cin >> x >> y;
        q.push({++x, ++y, 100});
    }

    auto invalid = [&](int i, int j) -> bool {
        return i < 1 || i > n || j < 1 || j > m;
    };

    while (!q.empty()){
        auto [i, j, w] = q.front(); q.pop();
        if (grid[i][j] != 0) continue;
        grid[i][j] = w;
        for (auto [di, dj]:dir){
            if (invalid(i + di, j + dj)) continue;
            int nw = w - 40;
            if (nw > 0)
                q.push({i + di, j + dj, nw});
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            ans += (grid[i][j] == 0);   
    cout << ans << '\n' << grid[sta][stb] << "%\n";
}