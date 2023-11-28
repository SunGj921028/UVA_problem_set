#include<iostream>
#include<cmath>

using namespace std;

int arr[1000000];
int main(){
    int x = 0;
    while(cin >> x){
        int n = 0;
        for(n = 0; ; ++n){
            int a = 0;
            cin >> arr[n];
            if(cin.get() == '\n') break;
        }
        int ans = arr[n - 1];
        for(int i = n - 2, val = x; i >= 0 ; i-- , val *= x){
            ans += (val * arr[i] * (n - i));
        }
        // int derivative = 0;
        // for (int i = 0; i < n; i++) {
        //     derivative += arr[i] * (n - i) * pow(x, n - i - 1);
        // }
        cout << ans << "\n";
    }
    return 0;
}