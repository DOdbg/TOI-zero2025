#include <iostream>
#include <vector>
#include <functional>

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

const int inf = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l, mn = 0, mx = 0;
    cin >> n >> l;

    for (int i = 1;i <= n;i++){
        int h;
        cin >> h;
        if (h % 3 == 0 && h % 4 == 0){
            mn += 10 * h / 4;
            mx += 10 * h / 3;
        }
        else if (h % 3 == 0){
            mn += 10 * h / 3;
            mx += 10 * h / 3;
        }
        else{
            mn += 10 * h / 4;
            mx += 10 * h / 4;          
        }
    }
    cout << l - mx << ' ' << l - mn << '\n';
}