#include <stdio.h>
#include <string.h>

int converter(char *sent){
    int length = strlen(sent);
    int num=0;
    for(int i=0; i<length; i++){
        if(sent[i] >= 48 && sent[i] <=57){
            num=num*10 + sent[i]-48;
        }
    }
    return num;


}

int main(){

    char sent[]="12a0";
    int num=0;
    num = converter(sent);
    printf("%d\n" , num);
    if(num==0){
        printf("Nums don't found");
        return 0;
    }
    if(0==(num%4)) printf("True");
    else printf("False");


}
