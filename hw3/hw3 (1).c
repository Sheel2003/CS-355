#include<stdio.h>

int main(int argc,char* argv[]){

int i,j,indexCount,currIndex,charCount;

for (i=1; i<argc; i++){
    charCount=0;

    for(currIndex=0;*(*(argv+i)+currIndex)!='\0';currIndex++){
        
        if((*(*(argv+i)+currIndex)<='z' && *(*(argv+i)+currIndex)>='a')||(*(*(argv+i)+currIndex)<='Z' && *(*(argv+i)+currIndex)>='A')){
        
            charCount++;
        }   
    }
    for(j=1;j<=charCount;j++){
        for(indexCount=0;indexCount<j;indexCount++){
            printf("%c",*(*(argv+i)+indexCount));   
        }
    printf("\n");
    }
}
return 0;
}