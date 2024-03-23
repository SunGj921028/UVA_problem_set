#include<iostream>
#include<string>

using namespace std;

int main(){
    string l, r;
    while(cin >> l >> r){
        if(l == "0" && r == "0"){ return 0;}
        int carry_count = 0;
        int carry = 0;
        int number = min(l.size(), r.size());
        int judge = 0;
        for(int i = 0;i < number; i++){
            judge = (l[l.size() - 1 - i] - '0') + (r[r.size() - 1 - i] - '0') + carry;
            if(judge >= 10){ carry_count++, carry = 1;}
            else{ carry = 0;}
        }
        if(number < l.size()){
            for(int j = l.size() - number - 1;j >= 0; j--){
                if(((l[j] - '0') + carry) >= 10){ carry_count++; }
                else{ break;}
            }
        }else if(number < r.size()){
            for(int j = r.size() - number - 1;j >= 0; j--){
                if(((r[j] - '0') + carry) >= 10){ carry_count++; }
                else{ break;}
            }
        }
        cout << (carry_count == 0 ? "No" : to_string(carry_count)) << " carry operation" << (carry_count > 1 ? "s" : "") << ".\n";
    }
    return 0;
}