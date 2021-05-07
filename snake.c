#include<stdio.h>
#include<conio.h>
#include<windows.h>
char direction;
int width=80,height=20; //height & width of playground
int score,highScore;
int x,y, xFruit,yFruit, index;
int xTail, yTail, nTail;
char a=219;
void gotoxy(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void walls(){       //playground walls
    for(int c=2;c<=80;c++){
        gotoxy(c,0);
        printf("%c",a);
    }
    for(int r=0;r<=20;r++){
        gotoxy(2,r);
        printf("%c%c",a,a);
    }
    for(int r=0;r<=20;r++){
        gotoxy(80,r);
        printf("%c%c",a,a);
    }
    for(int c=80;c>=2;c--){
        gotoxy(c,20);
        printf("%c",a);
    }
}
void banner(){      //snake bannner
    walls();
    gotoxy(8,3);
    printf("              \033[1;31m_____\033[0m         _____ _   _____    __ __ ______\n");
    gotoxy(8,4);
    printf("             \033[1;31m/ _  \"\\_\033[0m      / ___// | / /   |  / //_// ____/\n");
    gotoxy(8,5);
    printf("            \033[1;31m/ / \\___/--\033[0m    \\__ \\/  |/ / /| | / ,<  / __/\n");
    gotoxy(8,6);
    printf("            \033[1;31m\\ \\\033[0m           ___/ / /|  / ___ |/ /| |/ /___\n");
    gotoxy(8,7);
    printf("    \033[1;31m______   \\ \\\033[0m         /____/_/ |_/_/  |_/_/ |_/_____/\n");
    gotoxy(8,8);
    printf("  \033[1;31m/  ___  \\__/ /                                 _______\033[0m\n");
    gotoxy(8,9);
    printf(" \033[1;31m/  /   \\_____/                                 /  ___//\\#=~~-\033[0m\n");
    gotoxy(8,10);
    printf(" \033[1;31m\\  \\____                                      /  /\033[0m\n");
    gotoxy(8,11);
    printf("  \033[1;31m\\____  \\____________________________________/  /\033[0m\n");
    gotoxy(8,12);
    printf("       \033[1;31m\\______\\\\____\\\\____\\\\____\\\\____\\\\____\\\\__/\033[0m\n");
    loadingBar();
    system("cls");
}
void gameOver(){    //gameOver msg
    walls();
    gotoxy(12,7);
    printf("\033[1;31m  ____                       ___                   __ \033[0m\n");
    gotoxy(12,8);
    printf("\033[1;31m / ___| __ _ _ __ ___   ___ / _ \\__   _____ _ __  |  |\033[0m\n");
    gotoxy(12,9);
    printf("\033[1;31m| |  _ / _` | '_ ` _ \\ / _ \\ | | \\ \\ / / _ \\ '__| |  |\033[0m\n");
    gotoxy(12,10);
    printf("\033[1;31m| |_| | (_| | | | | | |  __/ |_| |\\ V /  __/ |    |__|\033[0m\n");
    gotoxy(12,11);
    printf("\033[1;31m \\____|\\__,_|_| |_| |_|\\___|\\___/  \\_/ \\___|_|    (__)\033[0m\n");
    scoreBoard();
    getch();
}
void loadingBar()   //loading animation
{
	char a=177,b=219;
	gotoxy(20,15);
	printf("Loading...");
	gotoxy(20,16);
	for (int i=0;i<40;i++){
        printf("%c",a);
	}
    gotoxy(20,16);
	for (int i=0;i<40;i++) {
        printf("\033[1;36m");
		printf("%c",b);
		// Sleep for 1 second
		Sleep(70);
	}
    printf("\033[0m");
}
int randomX(){     //generate random X-axis
    int min=2, max=15;
    srand(time(NULL));
    return min+(rand()%max);
}
int randomY(){     //generate random Y-axis
    int min=2, max=12;
    srand(time(NULL));
    return min+(rand()%max);
}
void fruit0(){
    gotoxy(5,5);
    printf("F");
}
void fruit(){       //fruit appear at any random axis
    xFruit=randomX();
    yFruit=randomY();
    gotoxy(xFruit,yFruit);
    printf("F");
}
void setup(){   //initial state of the game
    score=0;
    index=0;
    nTail=1;
    x=width/2;
    y=height/2;
    snakeHead(x,y);
}
void snakeHead(int x,int y){
    gotoxy(x,y);
    printf("O");
}
void Tail(){
    int X2[100];    //array of X-axis of tail
    int Y2[200];    //array of Y-axis of tail
    X2[0]=x;
    Y2[0]=y;
    for(int i=nTail;i>=0;i--){
        X2[i]=X2[i-1];
        Y2[i]=Y2[i-1];
    }
    for(int j=0;j<nTail;j++){
        gotoxy(X2[j],Y2[j]);
        printf("o");
    }
}
void input(){       //game controls
    if(kbhit()){
        switch(getch()){
        case 'a':
        case 'A':
            direction='L';
            break;
        case 'd':
        case 'D':
            direction='R';
            break;
        case 'w':
        case 'W':
            direction='U';
            break;
        case 's':
        case 'S':
            direction='D';
            break;
        case 'x':
        case 'X':
            break;
        }
    }
}
void logic(){
    switch(direction){
    case 'L':
        x--;
        break;
    case 'R':
        x++;
        break;
    case 'U':
        y--;
        break;
    case 'D':
        y++;
        break;
    default:
        break;
    }
}
int conditions(){
    if(x<=2 || x>=80 || y<=0 || y>=20){   //gameOver conditions
        gameOver();
        getch();
        exit(0);
    }
    if(x==xFruit && y==yFruit){     //fruit condition
        score++;
        index++;
        nTail++;
    }
}

void scoreBoard(){
    gotoxy(0,22);
    printf("  Score: %d",score);
}

int main(){
    system("color f");
    srand(time(NULL));
    int X[100];     //array for X-axis of fruit
    int Y[100];     //array for Y-axis of fruit
    for(int i=0;i<100;i++){
        X[i]=3+(rand()%78);
        Y[i]=1+(rand()%19);
    }
    setup();
    banner();
    int i=1;
    while(i=1){
        system("cls");
        xFruit=X[index];
        yFruit=Y[index];
        gotoxy(xFruit,yFruit);
        printf("F");
        walls();
        snakeHead(x,y);

        conditions();
        input();
        logic();
        //Tail();
        scoreBoard();
        Sleep(200);
    }

    return 0;
}
