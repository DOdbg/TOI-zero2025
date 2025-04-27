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

const string LOVE = "LOVElove";

bool is_love(char a, char b){
    for (auto c:LOVE)
        if (a == c || b == c)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string ans = "", a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size(), mx = max(n, m);
    int cnt = 0, sum = 0, con = 0;
    for (int i = 0;i < mx;i++){
        if (is_love(a[i % n], b[i % m])){
            cout << 'w';
            cnt++, sum++, con = max(con, sum);
        }
        else{
            cout << '$';
            sum = 0;
        }
    }
    if (cnt % 2 == 1)
        cout << con;
    else if (con < 2)
        cout << '#';
    cout << '\n';
}