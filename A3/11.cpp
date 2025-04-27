#include <iostream>
#include <vector>
#include <set>

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

    int n;
    cin >> n;
    vector<int> pf(n + 1, 0), v(n + 1);

    for (int i = 1;i <= n;i++){
        cin >> v[i];
        pf[i] = pf[i - 1] + v[i];
    }

    set<int> s;
    for (int i = 1;i <= n;i++)
        for (int j = i;j <= n;j++)
            s.insert(pf[j] - pf[i - 1]);
    cout << s.size() << '\n';
}