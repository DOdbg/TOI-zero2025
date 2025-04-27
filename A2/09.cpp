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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;    
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            cin >> grid[i][j];

    queue<int> q;
    for (int i = 1;i <= n;i++)
        q.push(i);

    while (q.size() > 1){
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();

        if (grid[a][b] != k && (a == k || b == k)){
            q.push(k);
            k = 0;
        }
        else
            q.push(grid[a][b]);
    }
    cout << q.front() << '\n';
}