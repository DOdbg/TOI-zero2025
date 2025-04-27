#include <iostream>
#include <vector>
#include <queue>

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
    cin >> n;
    priority_queue<int> drone, object;
    for (int i = 1;i <= n;i++){
        int t;
        cin >> t;
        object.push(t); 
    }
    for (int i = 1;i <= 200;i++){
        for (int j = 1;j <= 9;j++)
            drone.push(-2 * i);
        drone.push(-i);
    }
    /*
    drone = {-400, -400, ..., -2, -2, -1}
    -drone.top() = 1 // minimum value in drone
    */
    
    int ans = 0;
    while (!object.empty()){
        ans += (-drone.top()) * object.top(); 
        // use cheap drone to carry bigger value
        drone.pop();
        object.pop();
    }
    cout << ans << '\n';
}