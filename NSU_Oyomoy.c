#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>

void addpass(){
    char or;
    char FILE *fp;

    struct pass;
    do{
        clrscr();
        printf("\t\t\t\t\t===== Fingerprint ID =====\n");
        printf("\t\t\t\t\t__________________________");

        fp = fopen("Pass_Info.txt", a);
        printf("Please enter your fingerprint ID in the following bar.\n");
        scanf("%s", &info.fid);

        if(fp == NULL){
            fprintf(stderr, "Can't open your information server.\nPlease contact your service provider.\n");
        }

        else{
            printf("\tYour record has been stored successfully.\n");
        }

        fwrite(&info, sizeof(struct pass), 1, fp);
        fclose(fp);

        printf("\tDo you want to try another turn to store your fingerprint ID?\n[Y/N]\n");

    }   while(or == Y || or == y)
}

int main(void){

float fid;

addpass();


return 0;
}

