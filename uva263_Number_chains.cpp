#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
int a(int x){
    vector <int> v;
    int ret = 0;
    while (x){
        v.push_back(x%10);
        x /= 10;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i:v){
        ret *= 10;
        ret += i;
    }
    return ret;
}
int b(int x){
    vector <int> v;
    int ret = 0;
    while (x){
        v.push_back(x%10);
        x /= 10;
    }
    sort(v.begin(), v.end());
    for (int i:v){
        ret *= 10;
        ret += i;
    }
    return ret;
}
 
int main() {
    int n;
    while (cin >> n){
        if (n == 0) break;
        cout << "Original number was " << n << "\n";
        int cnt = 0;
        set <int> st;
        while (!st.count(n)){
            cnt++;
            st.insert(n);
            int A = a(n), B = b(n);
            n = A-B;
            cout << A << " - " << B << " = " << n << "\n";
        }
        cout << "Chain length " << cnt << "\n\n";
    }
}