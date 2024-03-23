#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 0;
    cin >> t;
    while(t--){
        int r_num = 0;
        cin >> r_num;
        int r[r_num] = {0};
        for(int i = 0; i < r_num; i++){
            cin >> r[i];
        }
        sort(r, r + r_num);
        int sum = 0;
        for(int i = 0;i < r_num;i++){
            sum += abs(r[i] - r[r_num / 2]);
        }
        cout << sum << "\n";
    }
    return 0;
}