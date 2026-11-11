#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
    FILE *fp = fopen("input.txt","r");
    char states[20][20],result[20][20];
    char from[20],symbol[20],to[20];
    int n;

    if(fp == NULL){
        perror("Error opening file !");
        exit(EXIT_FAILURE);
    }
    printf("Enter the number of states:\t");
    if(scanf("%d",&n) != 1 || n<1 || n>20){
        printf("Invalid number of states\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter the states\n");
    for(int i = 0;i < n;i++){
        printf("->\t");
        if(scanf("%19s",states[i]) != 1){
            exit(EXIT_FAILURE);
        }
    }
    for(int k =0;k<n;k++){
        int count = 1;
        strcpy(result[0],states[k]);
        for(int i = 0;i < count;i++){
            rewind(fp);
            while(fscanf(fp,"%19s %19s %19s",from,symbol,to) == 3){
                if(strcmp(result[i],from) != 0 || strcmp(symbol,"e") != 0)
                  continue;
                int j;
                for(j = 0;j < count;j++){
                    if(strcmp(result[j],to) == 0)
                     break;
                }
                if(j == count){
                    if(count == 20){
                        printf("Too many states in closure\n");
                        fclose(fp);
                        return 1;                    
                    }
                      strcpy(result[count++],to);

                }
            }
        }
        printf("Epsilon closure of %s = { ", states[k]);
        for (int i = 0; i < count; i++)
            printf("%s ", result[i]);
        printf("}\n");
    }

}