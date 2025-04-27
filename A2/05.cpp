#include <iostream>
#include <vector>
#include <queue>

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

    int h, w, n, m;
    cin >> h >> w >> n >> m;

    vector<int> a(n), b(m);
    cin >> a >> b;

    a.insert(a.begin(), 0); a.push_back(h);
    b.insert(b.begin(), 0); b.push_back(w);

    priority_queue<int> pq;
    vector<int> na, nb;
    for (int i = 0;i <= n;i++)
        na.push_back(a[i + 1] - a[i]);
    for (int i = 0;i <= m;i++)
        nb.push_back(b[i + 1] - b[i]);
    for (int i = 0;i <= n;i++)
        for (int j = 0;j <= m;j++)
            pq.push(na[i] * nb[j]);
    cout << pq.top() << ' ';
    pq.pop();
    cout << pq.top() << '\n';
}