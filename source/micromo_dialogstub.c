#include <stdio.h>

void Createdialogbox(int x, int y) {
    printf("created a nice dialog box !\n");
}

void Drawmessagebox(char *titre, char *text1[], char *text2[])
{
    printf(" = %s =",titre);
    for (int i = 0; text1[i][0] != 0; i++) {
        printf("%s\n",text1[i]);
    }
    printf(" == \n");
    for (int i = 0; text1[i][0] != 0; i++) {
        printf("%s\n",text1[i]);
    }
}

void Drawstatusbar() {}

void Drawk7index()
{
    extern FILE * fk7;
    extern int k7index, k7indexmax;
    if(fk7 != NULL)
        printf("K7 index %03d/%03d\n", k7index, k7indexmax);
}

