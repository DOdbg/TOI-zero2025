#include <iostream>
#include <vector>

using namespace std;

template<typename T> istream &operator >> (istream &in, vector<T> &v){
    for (auto &e:v)
        in >> e;
    return in;
}

template<typename T> ostream &operator << (ostream &out, vector<T> &v){
    for (auto &e:v)
        out << e << ' ';
    return out;
}

const int inf = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> bomb(n + 2, vector<int>(m + 2, 0));

    for (int i = 0;i < b;i++){
        int x, y;
        cin >> x >> y;
        x++, y++; // base 1 array
        for (int di = -1;di <= 1;di++)
            for (int dj = -1;dj <= 1;dj++)
                bomb[x + di][y + dj]++;
        bomb[x][y] = inf;
    }

    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++)
            if (bomb[i][j] >= inf)
                cout << "x ";
            else
                cout << bomb[i][j] << ' ';
        cout << '\n';
    }
}