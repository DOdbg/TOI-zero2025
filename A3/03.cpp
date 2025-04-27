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

    int n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);

    auto meet = [&](int t) -> bool {
        int anow = a[t], bnow = b[t], anext = a[t + 1], bnext = b[t + 1];
        if (anext == bnext)
            return true;
        // set anow < anext, bnow < bnext
        if (anow > anext)
            swap(anow, anext);
        if (bnow > bnext)
            swap(bnow, bnext);
        if (anow < )
        return ;
    };
}