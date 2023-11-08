#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t = 0,n = 0,d = 0;
    cin >> t;
    int case_num = 1;
    while(case_num <= t){
        cin >> n;
        vector<pair<string,int>> v;
        for(int i = 0;i < n;i++){
            string s;
            int x = 0;
            cin >> s >> x;
            v.push_back(make_pair(s,x));
        }
        cin >> d;
        string s;
        cin >> s;
        int i = 0;
        for(;i < n;i++){
            if(v[i].first == s){
                if(v[i].second <= d){
                    cout << "Case " << case_num++ << ": Yesss" << endl;
                }else if(v[i].second <= d+5){
                    cout << "Case " << case_num++ << ": Late" << endl;
                }else{
                    cout << "Case " << case_num++ << ": Do your own homework!" << endl;
                }
                break;
            }
        }
        if(i == n){
            cout << "Case " << case_num++ << ": Do your own homework!" << endl;
        }
    }
    return 0;
}