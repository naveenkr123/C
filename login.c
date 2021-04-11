#include<stdio.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void frame(){
        //frame block
    for(int c=2;c<=80;c++){
        gotoxy(c,0);
        printf("#");
    }
    for(int r=0;r<=20;r++){
        gotoxy(2,r);
        printf("#");
    }
    for(int r=0;r<=20;r++){
        gotoxy(80,r);
        printf("#");
    }
    for(int c=80;c>=2;c--){
        gotoxy(c,20);
        printf("#");
    }
}

void layout01(){
    frame();
    //Login bannner
    gotoxy(25,3);
    printf("\033[1;36m");
    printf(" _             _\n");
    gotoxy(25,4);
    printf("| | ___   __ _(_)_ __\n");
    gotoxy(25,5);
    printf("| |/ _ \\ / _` | | '_ \\ \n");
    gotoxy(25,6);
    printf("| | (_) | (_| | | | | |\n");
    gotoxy(25,7);
    printf("|_|\\___/ \\__, |_|_| |_|\n");
    gotoxy(25,8);
    printf("         |___/  \n");
    printf("\033[0m");
    //username box
    gotoxy(10,13);
    printf("Enter username:");
    gotoxy(30,12);
    printf("--------------------------\n");
    gotoxy(29,13);
    printf("|");
    gotoxy(56,13);
    printf("|");
    gotoxy(30,14);
    printf("--------------------------\n");
    //password box
    gotoxy(10,16);
    printf("Enter password:");
    gotoxy(30,15);
    printf("--------------------------\n");
    gotoxy(29,16);
    printf("|");
    gotoxy(56,16);
    printf("|");
    gotoxy(30,17);
    printf("--------------------------\n");
}
void loadingBar()
{
	char a=177,b=219;
	gotoxy(20,12);
	printf("Loading...");
	gotoxy(20,14);
	for (int i=0;i<40;i++){
        printf("%c",a);
	}
    gotoxy(20,14);
	for (int i=0;i<40;i++) {
        printf("\033[1;36m");
		printf("%c",b);
		// Sleep for 1 second
		Sleep(50);
	}
    printf("\033[0m");
}

void welcome(){
    frame();
    //Login bannner
    gotoxy(20,3);
    printf("\033[1;36m");
    printf("__        __   _");
    gotoxy(20,4);
    printf("\\ \\      / /__| | ___ ___  _ __ ___   ___");
    gotoxy(20,5);
    printf(" \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\");
    gotoxy(20,6);
    printf("  \\ V  V /  __/ | (_| (_) | | | | | |  __/");
    gotoxy(20,7);
    printf("   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|");
    printf("\033[0m");
    loadingBar();
}

void login(){
    //USERNAME
    char username[22];
    gotoxy(31,13);
    scanf("%s",&username);
    //PASSWORD
    char password[22];
    gotoxy(31,16);
    scanf("%s",&password);
    if(strcmp(username,"naveen")==0){
            if(strcmp(password,"abc123")==0){
                gotoxy(29,18);
                printf("\033[1;32m");
                printf("Welcome!");
                Sleep(1000);
                printf("\033[0m");
            }
            else{
                gotoxy(29,18);
                printf("\033[1;31m");
                printf("Incorrect password!");
                printf("\033[0m");
                Sleep(2000);
                exit(0);
            }
        }
    else{
        gotoxy(29,18);
        printf("\033[1;31m");
        printf("User doesn't exist!");
        printf("\033[0m");
        Sleep(2000);
        exit(0);
    }

}

int main(){
    //stage01
    system("color 4");
    layout01();
    login();
    system("cls");
    //stage02
    system("color 2");
    welcome();
    //stage03

    return 0;
}
