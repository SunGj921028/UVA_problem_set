#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 0;
    cin >> t;
    vector<pair<string, int > > list;
    while(t--){
        string country;
        cin >> country;
        int flag = 0;
        for(int i = 0;i < list.size();i++){
            if(list[i].first == country){
                list[i].second++;
                flag = 1;
                break;
            }else{ flag = 0;}
        }
        if(!flag){ list.push_back(make_pair(country, 1));}
        getline(cin, country);
    }
    sort(list.begin(), list.end());
    for(int i = 0;i < list.size(); i++){
        cout << list[i].first << " " << list[i].second << "\n";
    }
    return 0;
}