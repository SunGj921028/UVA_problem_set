#include<iostream>
#include<vector>
#include<string>

using namespace std;

int depth = 0;

int nine(string s){
    int sum = 0;
    for(int i = 0;i < s.size();i++){
        sum += (s[i] - '0');
    }
    if(sum % 9 == 0){
        depth++;
        if(sum == 9){ return sum;}
        return nine(to_string(sum));
    }else{
        return sum;
    }
}

int main(){
    string s;
    while(cin >> s){
        depth = 0;
        if(s == "0"){ break;}
        int sum = nine(s);
        if(sum % 9 == 0){
            cout << s << " is a multiple of 9 and has 9-degree " << depth << "." << endl;
        }else{
            cout << s << " is not a multiple of 9." << endl;
        }
    }
    return 0;
}