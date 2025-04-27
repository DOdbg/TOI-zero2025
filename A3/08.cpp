#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>

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

#define fr first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, l = 1, cnt = 0;
    cin >> n >> k;

    unordered_map<int, int> ump;
    vector<int> v(n + 1);
    long long ans = 0ll;
    for (int i = 1;i <= n;i++)
        cin >> v[i];

    deque<pair<int, int>> dq;
    for (int i = 1;i <= n;i++){
        if (ump[v[i]] == 0)
            cnt++;
        ump[v[i]]++;
        
    }
    cout << ans << '\n';
}