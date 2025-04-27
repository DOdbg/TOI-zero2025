#include <iostream>
#include <vector>
#include <unordered_map>

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

    int n, ans = 0;
    cin >> n;
    unordered_map<int, int> ump;

    for (int i = 1;i <= n;i++){
        int t;
        cin >> t;
        ump[t]++;
        ans = max(ans, ump[t]);
    }

    cout << ans << '\n';
}