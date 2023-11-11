#include<iostream>

using namespace std;

int main(){
    int t = 0;
    cin >> t;
    int count = 0;
    while(t--){
        int n = 0;
        cin >> n;
        int matrix[n][n];
        // input matrix
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < n; j++){
                matrix[i][j] = s[j] - '0';
            }
        }
        // input operation
        int m = 0;
        cin >> m;
        string s;
        for(int i = 0; i < m; i++){
            cin >> s;
            if(s == "transpose"){
                int temp = 0;
                for(int j = 0;j<n;j++){
                    for(int m = j;m<n;m++){
                        if(j == m) { continue;}
                        matrix[j][m] = matrix[j][m] ^ matrix[m][j];
                        matrix[m][j] = matrix[j][m] ^ matrix[m][j];
                        matrix[j][m] = matrix[j][m] ^ matrix[m][j];
                    }
                }
            }else if(s == "inc"){
                for(int j = 0;j<n;j++){
                    for(int m = 0;m<n;m++){
                        matrix[j][m] = (matrix[j][m] + 1) % 10;
                    }
                }
            }else if(s == "dec"){
                for(int j = 0;j<n;j++){
                    for(int m = 0;m<n;m++){
                        matrix[j][m] = (matrix[j][m] + 9) % 10;
                    }
                }
            }else if(s == "row"){
                int a = 0, b = 0;
                cin >> a >> b;
                for(int j = 0;j<n;j++){
                    matrix[a-1][j] = matrix[a-1][j] ^ matrix[b-1][j];
                    matrix[b-1][j] = matrix[a-1][j] ^ matrix[b-1][j];
                    matrix[a-1][j] = matrix[a-1][j] ^ matrix[b-1][j];
                }
            }else if(s == "col"){
                int a = 0, b = 0;
                cin >> a >> b;
                for(int j = 0;j<n;j++){
                    matrix[j][a-1] = matrix[j][a-1] ^ matrix[j][b-1];
                    matrix[j][b-1] = matrix[j][a-1] ^ matrix[j][b-1];
                    matrix[j][a-1] = matrix[j][a-1] ^ matrix[j][b-1];
                }
            }
        }
        cout << "Case #" << ++count << endl;
        for(int j = 0;j<n;j++){
            for(int m = 0;m<n;m++){
                cout << matrix[j][m];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}