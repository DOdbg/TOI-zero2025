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
    int d, l;
    dep(int nd, int nl) : d(nd), l(nl) {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    stack<dep> st;
    vector<int> depht(n + 1, 0);
    int dep_n = 0, curr = 0, mx_dep = 0;
    for (int i = 0;i < n;i++){
        int d, l;
        cin >> d >> l;
        dep_n += d;
        mx_dep = max(mx_dep, dep_n);

        while (!st.empty() && st.top().d > dep_n){
            depht[st.top().d] = max(depht[st.top().d], curr - st.top().l);
            st.pop();
        }
        st.push({dep_n, curr});
        curr += l;
    }
    while (!st.empty() && st.top().d == dep_n){
        depht[st.top().d] = max(depht[st.top().d], curr - st.top().l);
        st.pop();
    }

    depht[0] = 1e9;

    while (q--){
        int x;
        cin >> x;
        int lb = 0, ub = mx_dep, ans = 0;
        while (lb <= ub){
            int mid = lb + (ub - lb) / 2;
            if (depht[mid] >= x){
                ans = mid;
                lb = mid + 1;
            }
            else
                ub = mid - 1;
        }
        cout << ans << '\n';
    }
}
/*
9 5
1 2
1 3
1 1
1 3
-1 1
-1 1
1 5
-1 1
-1 2
*/