#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template<typename T> istream &operator >> (istream &in, pair<T, T> &p){
    return in >> p.first >> p.second;
}

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

const int inf = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> point(n);
    cin >> point;
    
    struct Ans {
        int mx = 0, mn = inf, dist = 0;
        Ans merge(const int b) const {
            return {max(mx, b), min(mn, b), max(mx, b) - min(mn, b)};
        }
    };

    map<int, Ans> mp1, mp2;
    int ans = 0;
    for (auto [a, b]:point){
        mp1[a - b] = mp1[a - b].merge(a);
        mp2[a + b] = mp2[a + b].merge(a);
        ans = max(ans, max(mp1[a - b].dist, mp2[a + b].dist));
    }

    cout << ans << '\n';
}