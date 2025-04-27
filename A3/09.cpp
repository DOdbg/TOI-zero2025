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

    int n, k;
    cin >> n >> k;
    vector<int> line(k + 1, 0);
    line[0] = n;
    for (int i = 1;i <= n;i++){
        int t;
        cin >> t;
        line[t]++;
    }
    int mn = *min_element(line.begin(), line.end()), ans = 0;
    for (int i = 1;i <= k;i++)
        ans += line[i] - mn;
    cout << ans << '\n';
}