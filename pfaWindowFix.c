#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    const char param1 [18]= "MainLeft";
    const char param2 [9]= "MainTop";

    FILE *fr, *fw;
    char c; 
    char *search;

    int x = 0;
    char text1[2048], text2[1024];

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
    }

    else{
        system("cls");
        printf("The contents of Config.xml are now: \n");
        
        //read until end of file and store it in a character array "text"
        while (!feof(fr)){
            c = fgetc(fr);
            text1[x] = c;
            x++;
            //printf("%c",c);
        }

        text1[strlen(text1)-2]='\0'; //To remove the extra 2 characters at the end that I do not know where it came from

        //Change MainLeft="X" to MainLeft="0" +++++++++++++++++TURN THIS INTO A FUNCTION 
        search = strstr(text1, param1) + 10;
        
        strcpy(text2, search);
        text1[strlen(text1)-strlen(text2)]='\0'; //cuts the whole string removing the length of text 2

        int num = 0;
        while(text2[num] != '\"'){
            text2[num] = '0';
            num++;
        }

        //concat the strings back ++++++FUNCTION ENDS AT THE NEXT LINE
        strcat(text1,text2);

        //Change MainTop="X" to MainLeft="0"
        search = strstr(text1, param2) + 9;
        
        strcpy(text2, search);
        text1[strlen(text1)-strlen(text2)]='\0'; //cuts the whole string removing the length of text 2

        num = 0;
        while(text2[num] != '\"'){
            text2[num] = '0';
            num++;
        }

        //concat the strings back ++++++FUNCTION ENDS AT THE NEXT LINE
        strcat(text1,text2);
        //debug
        printf("%s\n",text1);

    //Writes the main Config.xml
    fw = fopen(buffer, "w");
    fprintf(fw, "%s", text1);
    }

    fclose(fw);
    fclose(fr);
    system("pause"); 
    return 0;
}