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

    int hb, hw, bb, bw, x, y, ans = 0;
    cin >> hb >> hw >> bb >> bw >> x >> y;

    for (int i = 0;i <= min(hb, bb);i++){
        for (int j = 0;j <= min(hw, bw);j++){
            int normal = max(0, min(hb - i, bw - j)) + max(0, min(hw - j, bb - i));
            ans = max(ans, min(x, i + j) + min(y, normal));
        }
    }
    cout << ans << '\n';
}