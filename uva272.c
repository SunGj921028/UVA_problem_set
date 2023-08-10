#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    char input[1024];
    bool can = true;
    while(gets(input)){
        int len = strlen(input);
        for(int i = 0; i < len ; i++){
            if(input[i] == '"'){
                if(can){
                    printf("``");
                }else{
                    printf("''");
                }
                can = !can;
            }else{
                printf("%c",input[i]);
            }
        }
        printf("\n");
    }
    return 0;
}