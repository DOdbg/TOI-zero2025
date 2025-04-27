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

const int N = 360;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> freq(N + 1, 0);
    for (int i = 0;i < n;i++){
        int l, r;
        cin >> l >> r;
        if (l > r)
            r += N;
        for (int i = l;i < r;i++)
            freq[i % N]++;
    }
    int ans = 0, cnt = 0;

    for (int i = 1;i <= 2 * N;i++){
        if (freq[i % N] > 0){
            cnt++;
            ans = max(ans, cnt);
        }
        else
            cnt = 0;
    }
    
    cout << min(360, ans) << '\n';
}