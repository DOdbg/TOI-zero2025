#include <iostream>
#include <vector>
#include <algorithm>

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

#define sort_all(v) sort(v.begin(), v.end())

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> in1(n), in2(n), out1(n), out2(n);
    cin >> in1 >> in2 >> out1 >> out2;
    sort_all(in1); sort_all(in2); sort_all(out1); sort_all(out2);
    int ans = 1e9;
    for (int i = 0;i <= min(n, k);i++){
        int j = k - i, mx = 0;
        if (j > n) continue;
        for (int l = 0;l < i;l++)
            mx = max(mx, in1[l] + out1[i - l - 1]);
        for (int l = 0;l < j;l++)
            mx = max(mx, in2[l] + out2[j - l - 1]);
        ans = min(ans, mx);
    }
    cout << ans << '\n';
}