#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void turnToZeros(char *text1, size_t text1_length, const char *PARAM, size_t PARAM_length);

int main(){
    const char PARAM1 [9]= "MainLeft";
    const char PARAM2 [8]= "MainTop";
    char text1[2048];
    int x = 0;
    char *point;
    
    FILE *fr, *fw;

    char * appdata = getenv("APPDATA");
    if (!appdata) {
        printf("Error enviroment");
    }

    char buffer[0x400];
    snprintf(buffer, sizeof(buffer), "%s\\Piano From Above\\Config.xml", appdata);

    //opens xml file to write and read
    fr = fopen(buffer,"r");

    if (fr == NULL){
        system("cls");
        printf("Error Loading the File\n");
    } else {
        system("cls");
        printf("The contents of Config.xml are now: \n");
        
    //read until end of file and store it in a character array 
        while (!feof(fr)){
            text1[x] = fgetc(fr);
            x++;
        }

        text1[strlen(text1)-1]='\0'; //To remove the extra character(s) at the end that I did not know where it came from

        turnToZeros(text1, strlen(text1), PARAM1, strlen(PARAM1));
        turnToZeros(text1, strlen(text1), PARAM2, strlen(PARAM2));

        printf("%s",text1);

        //Writes the main Config.xml
        fw = fopen(buffer, "w");
        fprintf(fw, "%s", text1);
    }

    fclose(fw);
    fclose(fr);
    system("pause"); 
    return 0;
}

void turnToZeros(char *text1, size_t text1_length, const char *PARAM, size_t PARAM_length){
    char text2[1024];
    char *search;
    search = strstr(text1, PARAM) + PARAM_length + 2;
    
    strcpy(text2, search);
    text1[text1_length-strlen(text2)]='\0'; //cuts the whole string removing the length of text 2

    int num = 0;
    while(text2[num] != '\"'){
        text2[num] = '0';
        num++;
    }

    strcat(text1,text2);//concat the strings back
}
