#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool Palindromes(char input[1024]){
    int head = 0;
    int back = strlen(input) - 1;
    int count = (strlen(input) / 2);
    while(count--){
        if(input[head] == input[back]){
            head++;
            back--;
        }else{
            return false;
        }
    }
    return true;
}

bool Mirror(char input[1024]){
    char character[21][2]={
        {'A','A'},{'E','3'},{'H','H'},{'I','I'},{'J','L'},{'L','J'},
        {'M','M'},{'O','O'},{'S','2'},{'T','T'},{'U','U'},{'V','V'},
        {'W','W'},{'X','X'},{'Y','Y'},{'Z','5'},{'1','1'},{'2','S'},
        {'3','E'},{'5','Z'},{'8','8'}
    };
    char repeat[13][2]={
        {'A','A'},{'H','H'},{'I','I'},{'M','M'},
        {'O','O'},{'T','T'},{'U','U'},{'V','V'},
        {'W','W'},{'X','X'},{'Y','Y'},{'1','1'},
        {'8','8'}
    };
    int count = (strlen(input) / 2);
    int head = 0;
    int back = strlen(input) - 1;
    while(count--){
        bool find = false;
        for(int i = 0;i<21;i++){
            if(input[head] == character[i][0]){
                find = true;
                if(input[back] != character[i][1]){
                    return false;
                }else{
                    break;
                }
            }
        }
        if(!find){ return false;}
        head++;
        back--;
    }
    if(strlen(input)%2 == 1){
        for(int i = 0;i<13;i++){
            if(input[(strlen(input)/2)] == repeat[i][0]){
                return true;
            }
        }
        return false;
    }
    return true;
}

int main(){
    char input[1024];
    while(gets(input)){
        if(Palindromes(input) && Mirror(input)){
            printf("%s",input);
            printf(" -- is a mirrored palindrome.\n");
        }else if(!Palindromes(input) && !Mirror(input)){
            printf("%s",input);
            printf(" -- is not a palindrome.\n");
        }else if(Palindromes(input) && !Mirror(input)){
            printf("%s",input);
            printf(" -- is a regular palindrome.\n");
        }else{
            printf("%s",input);
            printf(" -- is a mirrored string.\n");
        }
        printf("\n");
    }
}