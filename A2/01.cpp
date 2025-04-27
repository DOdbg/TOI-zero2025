#include <iostream>
#include <vector>

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

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    cin >> a >> b;

    a.insert(a.begin(), 0); 
    b.insert(b.begin(), 0);

    int ans = 1;

    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if (i % 2 == j % 2)
                ans += ((a[i] < b[j] && a[i + 1] >= b[j + 1]) || 
                         a[i] > b[j] && b[j + 1] >= a[i + 1]);
            else
                ans += ((b[j] < a[i + 1] && b[j + 1] > a[i]) || 
                        (a[i] > b[j + 1] && a[i + 1] < b[j]));
        }
    }
    cout << ans << '\n';
}