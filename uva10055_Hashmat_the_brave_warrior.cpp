#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a = 0, b = 0;
    while(cin >> a >> b){
        cout << abs(a - b) << "\n";
    }
    return 0;
}