#include <iostream>
#include <vector>
#include <algorithm>

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

    int n, w, l;
    cin >> n >> w >> l;

    vector<vector<int>> v(n + 1), freq(n + 1, vector<int>(w + 2, 0));
    for (int i = 1;i <= n;i++){
        int m;
        cin >> m;
        for (int j = 1;j <= m;j++){
            int t;
            cin >> t;
            v[i].push_back(t);
        }
    }

    for (int i = 1;i <= n;i++){
        for (auto e:v[i]){
            int lb = max(0, e - l), ub = min(w + 1, e + l + 1);
            freq[i][lb]++;
            freq[i][ub]--;
        }
    }

    for (int i = 1;i <= w;i++)
        for (int j = 1;j <= n;j++)
            freq[j][i] += freq[j][i - 1];

    for (int i = 1;i <= w;i++){
        bool ans = true;
        for (int j = 1;j <= n && ans;j++)
            ans &= (freq[j][i] > 0);
        if (ans){
            cout << "1\n";
            return 0;
        }
    }
    cout << "0\n";
}