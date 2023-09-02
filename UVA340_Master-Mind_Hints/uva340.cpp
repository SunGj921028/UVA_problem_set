#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

void print(int *match){
    printf("    (%d,%d)\n",match[0],match[1]);
    return;
}

void check(int *mes, int *arr, int ok[2][1000], int n){
    int match[2] = {0};
    for(int i = 0;i<n;i++){
        if(mes[i] == arr[i]){
            match[0]++;
            ok[0][i] = false;
            ok[1][i] = false;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(!ok[0][i]){
                break;
            }else if(!ok[1][j]){
                continue;
            }else{
                if(mes[i] == arr[j]){
                    match[1]++;
                    ok[0][i] = false;
                    ok[1][j] = false;
                }
            }
        }
    }
    print(match);
    return;
}

//先1對1
int main(){
    int time = 0;
    while(++time){
        int n = 0;
        cin >> n;
        if(n==0){
            return 0;
        }else{
            cout << "Game " << time << ":\n";
        }
        int mes[1000] = {0};
        int count = 1;
        while(1){
            int arr[1000] = {0};
            int ok[2][1000];
            for(int i = 0;i<2;i++){
                for(int j = 0;j<n;j++){
                    ok[i][j] = 1;
                }
            }
            if(count){
                for(int i = 0;i<n;i++){
                    cin >> mes[i];
                }
                count = 0;
            }else{
                for(int i = 0;i<n;i++){
                    cin >> arr[i];
                }
                if(arr[0] == 0){
                    break;
                }else{
                    check(mes,arr,ok,n);
                }
            }
        }
    }
}