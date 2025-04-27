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

    string s;
    cin >> s;
    int n = s.size();
    bool pre_R = false, have_A = false, unknown = true, pure = true, pre_B = false;
    int mx = 0, idx = 0, cnt = 0;
    char pre = 'Z';
    
    for (auto &c:s)
        c = toupper(c);
    
    for (int i = 0;i < n;i++){
        char c = s[i];
        unknown &= (c == 'T') || (c == 'I');
        if (pre_B && c != 'I' && c != 'T') // check for BI..., BT...
            pure = false;
        
        pre_B = false;
        if (pre_R && c == 'A'){ // check for RA...
            cnt++;
            mx = max(mx, cnt);
            have_A = true;
        }
        else if (pre_R && have_A == false) // case R? (? != A)
            pure = false;
        
        else{ // case RA...
            pre_R = false;
            have_A = false;
        }
        if (c == 'A' && (pre != 'R' && pre != 'A')) // case ?A (? != R)
            pure = false;
        
        if (c == 'B')
            pre_B = true;
        if (c == 'R')
            pre_R = true;
        if (c != 'A')
            cnt = 0;
        pre = c;
        if (pure == false){
            cout << "no " << i << '\n';
            return 0;
        }
    }
    if (s.back() == 'B' || s.back() == 'R')
        cout << "no " << n - 1 << '\n';
    else if (unknown)
        cout << "unknown " << n << '\n';
    else
        cout << "yes " << mx << '\n';
}