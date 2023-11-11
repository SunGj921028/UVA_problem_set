#include<iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        int count=0;
        for(int i=2;i<=n/2;i++){
            int flag=0;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                for(int j=2;j<(n-i);j++){
                    if((n-i)%j==0){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                count++;
            }
        }
        cout<<count<<endl;
    }
}