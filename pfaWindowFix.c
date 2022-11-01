#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* fp;
    char c[2048]; 

    char * appdata = getenv("APPDATA");
    if (!appdata) {
        printf("Error enviroment");
    }

    char buffer[0x400];
    snprintf(buffer, sizeof(buffer), "%s\\Piano From Above\\Config.xml", appdata);

    //opens text file to read
    fp = fopen(buffer,"r");
    if (fp == NULL){
        printf("%s", buffer);
    }
    else{
        printf("The contents of the file are: \n");

        //read until end of file
        while (!feof(fp)){
            fgets(c, 2047, fp );
            printf("%s",c);
        }
    fclose(fp);    
    }
    system("pause");
    return 0;
}