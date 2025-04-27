#include <iostream>
#include <vector>
#include <cstring>

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

    string s;
    cin >> s;
    int n = s.size(), cnt = 0, mx = 0, bu = 0;
    bool have_b = false;
    for (auto &c:s){
        if (toupper(c) == 'B'){
            have_b = true;
            bu = 1;
            cnt = 0;
        }
        else if (toupper(c) == 'U' && bu)
            mx = max(mx, ++cnt);
        else {
            cnt = 0;
            bu = 0;
        }
    }
    
    if (mx > 0){
        cout << "Yes " << mx << '\n';
        return 0;
    }
    if (have_b){
        bool ch = false;
        for (auto c:s){
            if (ch)
                cout << 'U';
            else
                cout << c;
            ch |= toupper(c) == 'B';
        }
        cout << '\n';
    }
    else {
        for (int i = 0;i < n;i++)
            cout << "BUU"[i % 3];
        cout << '\n';
    }
}