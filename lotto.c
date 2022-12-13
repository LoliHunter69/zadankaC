#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void pause(){
     getch();     
}

void refresh(){
     system("cls");     
}

void printfAutoBlank(int number){
     if(number==0) printf("  ");
     else printf("%2.0d", number);
}

void printInterface(int numbers[6], char **display, int displayId){
   /*printf("++==========================================================++\n");
     printf("||         ##     ####### ######## ######## #######         ||\n");
     printf("||         ##     ##   ##    ##       ##    ##   ##         ||\n");
     printf("||         ##     ##   ##    ##       ##    ##   ##         ||\n");
     printf("||         ##     ##   ##    ##       ##    ##   ##         ||\n");
     printf("||         ###### #######    ##       ##    #######         ||\n");
     printf("++========++========++========++========++========++========++\n");
     printf("||        ||        ||        ||        ||        ||        ||\n");
     printf("||   00   ||   00   ||   00   ||   00   ||   00   ||   00   ||\n");
     printf("||        ||        ||        ||        ||        ||        ||\n");
     printf("++========++========++========++========++========++========++\n");
     printf("||                                                          ||\n");
     printf("||        spacja - losuj                   q - wyjdz        ||\n");
     printf("||                                                          ||\n");
     printf("++==========================================================++\n");*/
     
     printf("++==========================================================++\n");
     printf("||         ##     ####### ######## ######## #######         ||\n");
     printf("||         ##     ##   ##    ##       ##    ##   ##         ||\n");
     printf("||         ##     ##   ##    ##       ##    ##   ##         ||\n");
     printf("||         ##     ##   ##    ##       ##    ##   ##         ||\n");
     printf("||         ###### #######    ##       ##    #######         ||\n");
     printf("++========++========++========++========++========++========++\n");
     printf("||        ||        ||        ||        ||        ||        ||\n");
     printf("||   %2.0d   ||   %2.0d   ||   %2.0d   ||   %2.0d   ||   %2.0d   ||   %2.0d   ||\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5]);
     printf("||        ||        ||        ||        ||        ||        ||\n");
     printf("++========++========++========++========++========++========++\n");
     printf("||                                                          ||\n");
     printf("||        %s        ||\n", display[displayId]);
     printf("||                                                          ||\n");
     printf("++==========================================================++\n");
     printf("||                   By: Dominik Kuzyk                      ||\n");
     printf("++==========================================================++\n");
}


void loadAnimation(int numbers[6], char **display){
        refresh(); 
        printInterface(numbers, display, 0); 
        Sleep(400); 
        refresh();
        printInterface(numbers, display, 1);
}

int beenDrawn(int draws, int numbers[]){
    for(int i=0; i<draws; i++){
            if(numbers[draws]==numbers[i]) return 1;
            }
    return 0;
}

void release(int numbers[], char **display){
     
     refresh();
     printInterface(numbers, display, 2);
     
     for(int j=0; j<6; j++){
             int rolls=3+ rand()%4;
             for(int i=0;i<rolls;i++){
                     numbers[j] = 1 + rand()%48;
                     refresh();
                     printInterface(numbers, display, 2);
                     Sleep(100);
                     if(j!=0 && i==(rolls-1) && beenDrawn(j, numbers)) rolls++;
             }
     }
     refresh();
     printInterface(numbers, display, 3);
     pause();
            
     refresh();
     printInterface(numbers, display, 1);
}

int main(){
    
    int exit = 0;
    int numbers[6] = {0, 0, 0, 0, 0, 0};
    char *display[4] = {"                                          ", "spacja - losuj                   q - wyjdz","        ZWOLNIONO MASZYNE LOSUJACA        ","          OTO ZWYCIESKIE NUMERY           "};
    
    //ziarno i kolory CMD
    srand(time(NULL));
    system("@echo off");
    system("color 61");
    
    loadAnimation(numbers, display);
    
    while(!exit){
    switch(getch()){
            case 'q':
                 exit=1;
                 break;
            case ' ':
                 release(numbers, display);
                 for(int i=0;i<=5;i++) numbers[i]=0;
                 break;
        }             
    }
    
    return 0;
}
