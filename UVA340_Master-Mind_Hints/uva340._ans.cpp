#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    int game = 1;
    int n = 0;
    while(cin >> n , n > 0){
        vector<int> code(n);
        for(int i = 0;i<n;i++){
            cin >> code[i];
        }
        cout << "Game " << game++ << ":" << endl;
        while(n == n){
            vector<int> guess(n);
            for(int i = 0;i<n;i++){
                cin >> guess[i];
            }
            if (count(guess.begin(), guess.end(), 0) == n){break;}
            vector<bool> marks(n, false);
            int match[2] = {0};
            // Check strong matches.
            for (int i = 0; i < n; i++){
                if (code[i] == guess[i])
                {
                    match[0]++;
                    marks[i] = true;
                    guess[i] = -1;
                }
            }
            // Check weak matches.
            for (int d = 0; d < n; d++){
                if (!marks[d])
                {
                    vector<int>::iterator iter = 
                        find(guess.begin(), guess.end(), code[d]);
                    if (iter != guess.end())
                    {
                        match[1]++;
                        marks[d] = true;
                        *iter = -1;
                    }
                }
            }
            cout << "    (" << match[0] << "," << match[1] << ")" << endl;
        }

    }
}