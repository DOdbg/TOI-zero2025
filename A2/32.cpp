#include <iostream>
#include <vector>

using namespace std;

/*
I'm too lazy to code
for (...) every single file Lol
*/

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<vector<int>> pokemon(n + 2, vector<int>(m + 2, 0));
    vector<vector<bool>> have_pokemon(n + 2, vector<bool>(m + 2, false));

    for (int i = 1;i <= p;i++){
        int x, y;
        cin >> x >> y;
        x++, y++; // array base 1
        pokemon[x][y]++;
        have_pokemon[x][y] = true;
    }

    auto calc = [&](int i, int j) -> int {
        int res = 0;
        for (int di = -1;di <= 1;di++)
            for (int dj = -1;dj <= 1;dj++)
                res += pokemon[i + di][j + dj];
        return res;
    };

    int ans = 0;

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (!have_pokemon[i][j])
                ans = max(ans, calc(i, j));
    cout << ans << '\n';
}