/*
 *  Дана непустая последовательность слов из строчных букв ; между соседними словами - запятая , пробел за последним
 *  словом - точка . Напечатать все слова , которые встречаюся в последовательности по одному разу.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copy_word(char *sent, int t){
    int len_word = 0;
    int len_sent = strlen(sent);
    for(int i=t; i<len_sent; i++){
        if((sent[i]==32)||(sent[i]==44)||(sent[i]==46)){
            break;
        }
        else len_word++;
    }
    char *word = (char*) malloc(sizeof(char) * len_word+1);
    word[len_word] = '\0';

    int i=t, j=0;
    while (sent[i]!=44&&sent[i]!=32&&sent[i]!=46){
        word[j]=sent[i];
        i++;
        j++;
    }


//    for(int i=t; i<len_sent; i++){
//        for(int j=0, i=0; j<len_word;){
//            if((sent[i]==32)||(sent[i]==44)||(sent[i]==46)){
//                break;
//            }
//            else{
//                word[j]=sent[i];
//                break;
//            }
//        }
//    }
    return word;
}


// Функция table строит таблицу , которая каждому символу подстроки ставит в соответсвие число ,зависящее от позиции
// этого символа . Отсчёт ведётся с конца подстроки.
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


// Функция checkup считает количество вхождений подсроки в строку.
int checkup(char *sentense, int *tablew, char *word, int t){ // delete t

    int count=0;
    int lengthw = strlen(word);
    int lengths = strlen(sentense);

    for(int i=t+lengthw-1; i<=lengths; ){ // t на lengthw-1

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

    char sent[]="qwerty uhiui uno hskdjfun ffdafh.";
    unsigned int len_sent = strlen(sent);
    if(len_sent==0){
        printf("ERROR");
        return 0;
    }
    for(int i=0; i<len_sent; i++){
        if((sent[i]>96)&&(sent[i]<123)&&((sent[i-1]==32)||(sent[i-1]==44)||(i==0))){
            char *word = copy_word(sent, i);
            unsigned int len_word = strlen(word);
            int *tab = table(word);
            int count = checkup(sent, tab, word, i);
            if(count == 1) for(int t=0; t<len_word; t++) printf("%c", word[t]);
            printf("\n");
            free(word);
            free(tab);
        }
        else if(sent[i]==46) break;
    }
    return 0;
}
