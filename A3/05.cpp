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

    int l, n;
    cin >> l >> n;
    vector<int> freq(l + 1, 0);

    for (int i = 1;i <= n;i++){
        int s, t;
        cin >> s >> t;
        freq[s]++;
        freq[t + 1]--;
    }

    int ans = 0;
    for (int i = 1;i <= l;i++){
        freq[i] += freq[i - 1];
        ans = max(ans, freq[i]);
    }
    cout << ans << '\n';
}