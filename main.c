#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <conio.h>
static int levelcont,step=1;
char word[100];
int a[3][3];
char disp[100];
int main()
{
    printf("WELCOME TO HANGMAN GAME\n");
    levels(2);
    return 0;
}
void levels(int k)
{
    //display levels list
    FILE *saves;
    saves=fopen("levels.txt","a+");
    int count=0;
    int n;
    char c;

    if(k==2){

    ////////////////////
    n=rand()%210+1;
    //filling the word from the text file
    FILE *level;
    level=fopen("levels.txt","r");
    int zz=0;
    int stop=0;
    for (c = getc(level); stop<n; c = getc(level)){
            if(c=='\n'){
                stop++;
                zz=0;
            }
        if(stop==n-1){
        word[zz]=c;
        zz++;
            }
    }
    fclose(level);
    if(n>1){
    for(int i=0;i<strlen(word);i++){
        word[i]=word[i+1];
    }
    }
    game(1);
    }


}
void game(int z)
{
    strcpy(disp,word);
    int flag=0;
    system("cls");
    char s;
    if(z==0){
    levels(1);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j]=' ';
        }
    }

    int wordl=strlen(word);

    char wor[wordl+1];
    for(int i=0;i<wordl;i++){
        wor[i]=' ';
    }
    int x=0,counter=0;



    while(x<=6){
        int k=0;

        printf("\nTHE WORD IS %d LETTERS\n",wordl);
        printf("GUESS THE LETTER\n");
        printf("click (/) to return to main menu\n");
        board(1);
        fflush(stdin);
        for(int i=0;i<wordl;i++){
        printf("%c",wor[i]);
        }
        printf("\n");
        for(int i=0;i<wordl;i++){
            printf("-");
        }
        printf("\n");
        scanf("%c",&s);
        if(s=='/'){
            main();
        }
        system("cls");
        for(int i=0;i<wordl;i++){
            if(s==word[i]){
                board(1);
                wor[i]=word[i];
                word[i]=' ';
                counter++;
                k=1;

            }
        }

        if(k==0){
            board(0);
            x++;
        }
        if(counter==wordl){
            flag=1;
            break;
        }
        //x++;

        system("cls");

    }
    system("cls");
    printf("What You Entered: ");
    for(int i=0;i<wordl;i++){
        printf("%c",wor[i]);
        }
        printf("\n");

    printf("The Word: ");
    for(int i=0;i<wordl;i++){
        printf("%c",disp[i]);
        }
        printf("\n");

    if(flag==1){
        printf("you won");
    }
    else{
        printf("you lost");

    }
    printf("\nYOU WILL BE REDIRECTED TO NEXT LEVEL IN 5 SECONDS");
    sleep(5);
    system("cls");
    levels(2);

}
void board(int n)
{
    if(!n){
        if(a[0][1]==' '){
            a[0][1]='O';
        }
        else if(a[1][0]==' '){
            a[1][0]='//';
        }
        else if(a[1][2]==' '){
            a[1][2]='\\';
        }
        else if(a[1][1]==' '){
            a[1][1]='|';
        }
        else if(a[2][0]==' '){
            a[2][0]='//';
        }
        else if(a[2][2]==' '){
            a[2][2]='\\';
        }
    }
    printf("\n _____");
    printf("\n|     |");
    printf("\n|     %c",a[0][1]);
    printf("\n|    %c %c",a[1][0],a[1][2]);
    printf("\n|     %c",a[1][1]);
    printf("\n|    %c %c",a[2][0],a[2][2]);
    printf("\n______\n");

}

