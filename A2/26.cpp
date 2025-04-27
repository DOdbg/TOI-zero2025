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

    int n;
    cin >> n;
    int ans = 0;
    priority_queue<pair<int, string>> pq;
    for (int i = 0;i < n;i++){
        string name;
        int w;
        cin >> name >> w;
        pq.push({w, name});
        ans += w > 15;
    }    
    cout << ans << '\n';
    cout << pq.top().second << ' ' << pq.top().first << '\n';
}