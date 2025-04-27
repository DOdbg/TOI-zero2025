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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, t;
    cin >> n >> k >> t;
    vector<bool> vis(n + 1, false);

    int now = 1, ans = 0;
    while (now != t && !vis[now]){
        vis[now] = true;
        ans++;
        now = (now + k);
        if (now > n)
            now -= n;
    }
    cout << ans + (now == t) << '\n';
}