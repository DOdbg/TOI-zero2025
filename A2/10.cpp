#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

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

const int inf = 1e9 + 7;

struct dep {
    int d, l, r;
    dep(int nd, int nl, int nr) : d(nd), l(nl), r(nr) {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<dep> v(n);
    int depth = 0, dist = 0;
    for (auto &[d, l, r]:v){
        int delta_depht, delta_dist;
        cin >> delta_depht >> delta_dist;
        depth += delta_depht;
        d = depth;
        l = dist;
        dist += delta_dist;
        r = dist;
    }
    v.push_back(dep(0, dist, inf));
    stack<dep> st;
    st.push(dep(0, 0, 0));
    map<int, int> bruh;
    int nl = 0, nr = 0;
    for (auto [d, l, r]:v){
        while (!st.empty() && d <= st.top().d){
            
        }
        st.push(dep(d, l, r));
    }

}