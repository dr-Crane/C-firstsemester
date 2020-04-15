#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find_pos(char *sent){
    int count = 0;
    for(int i=0; i<strlen(sent);i++){
        if(sent[i]==32||sent[i]==44) count++;
    }
    int *arr = (int*) malloc(count*sizeof(int));
    int i=0,j=0;
    while (sent[i]!=46){
        if(sent[i]==32||sent[i]==44){
            arr[j] = i;
            j++;
        }
        i++;
    }
    return arr;
}

char *space_delete(char *sent){
    if(strlen(sent)==0) return NULL;
    char space;
    for(int i=0; i<strlen(sent); i++){
        if(sent[i]==32||sent[i]==44) {
            for (int j = i; j < strlen(sent); j++) {
                space = sent[j];
                sent[j] = sent[j + 1];
                sent[j + 1] = space;
            }
        }
    }
    return sent;
}

int main(){

    char sent[]="slowo slowo net net nn .";
    int *pos = find_pos(sent);
    char *arr = space_delete(sent);
    if(arr == NULL){
        printf("Error");
        return 1;
    }
    for(int i=0;i<strlen(pos);i++) printf("%d ",pos[i]);
    printf("\n");
    unsigned int len = strlen(arr);
    printf("%d", len);
    printf("\n");
    for(int i=0;i<strlen(arr);i++) printf("%c", arr[i]);

    return 0;

}
