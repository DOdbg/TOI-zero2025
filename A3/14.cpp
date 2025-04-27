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

    int n, cnt[2] = {0, 0};
    cin >> n;
    for (int i = 1;i <= n;i++){
        int t;
        cin >> t;
        cnt[t > 18]++;
    }
    cout << n + max(0, cnt[1] - cnt[0] - 1) << '\n';
}