#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *table(char *word) {
    int lengthw = strlen(word);
    int *mass= (int*) malloc(lengthw*sizeof(int));

    for(int i=1; i<lengthw; i++){
        mass[lengthw-i-1]=i;
        for(int j=lengthw-i; j<lengthw-1; j++){
            if(word[lengthw-i-1]==word[j] && i!=1) mass[lengthw-i-1]=mass[lengthw-i];
        }
    }

    for(int i=0; i<lengthw-1; i++){
        if(word[i]==word[lengthw-1]){
            mass[lengthw-1]=mass[i];
            break;
        }
        else mass[lengthw-1]=1 + mass[0];
    }
    return mass;
}

int checkup(char *sentense, int *tablew, char *word){

    int count=0;
    int lengthw = strlen(word);
    int lengths = strlen(sentense);

    for(int i=lengthw-1; i<=lengths; ){

        for(int j=1; j<lengthw; j++){
            if(sentense[i-j+1]!=word[lengthw-j]){
                int t=0;
                for(int k=0; k<lengthw; k++){
                    if(sentense[i-j+1]==word[k]){
                        t = tablew[k];
                        break;
                    }
                    else t=0;
                }
                if(t) {
                    i = i + t;
                    break;
                }
                else i = i+lengthw-1;
                break;
            }
             else if((lengthw-j-1)==0){
                count++;
                i = i + lengthw-1;
                break;
            }
        }
    }
    return count;

}

int main(){

    char sentense[]="slowo sdkjfslowoslowo slwo slowo";
    char word[]= "slowo";
    int lengthw = strlen(word);
    int lengths = strlen(sentense);
    int *tablew = table(word);
    int result = checkup(sentense, tablew,word);
    for(int i=0; i<lengthw; i++) printf("%c", word[i]);
    printf("\n");
    for(int i=0; i<lengths; i++) printf("%c", sentense[i]);
    printf("\nThis word meets: %d times", result);


}
