#include<stdio.h>
#include<conio.h>
#include<windows.h>

char ball_Direction;
int x,y,n, ballX,ballY, min,max, score,life;
enum ball_Direction{downRight, downLeft, upLeft, upRight};
enum ball_Direction ballDir;

void gotoxy(int x,int y){   //console cursor position
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void walls(){       //playground walls
    char a=219;
    printf("\033[1;31m");
    for(int c=2;c<=41;c++){
        gotoxy(c,0);
        printf("%c",a);
    }
    for(int r=1;r<=20;r++){
        gotoxy(2,r);
        printf("%c%c",a,a);
    }
    for(int r=1;r<=20;r++){
        gotoxy(40,r);
        printf("%c%c",a,a);
    }
    for(int c=41;c>=2;c--){
        gotoxy(c,20);
        printf("%c",a);
    }
    printf("\033[0m");
}
void setup(){
    x=4, y=1;   //bars coordinates
    score=0;

    min=8, max=25;      //ball coordinates
    srand(time(NULL));
    ballX=min+(rand()%max);
    ballY=1;

    life=3;
    ballDir=downRight;
}
void bar(int x,int y){
    char b=219;
    gotoxy(x,y);
    printf("\033[1;36m");
    printf("%c%c",b,b);
    gotoxy(x,y+1);
    printf("%c%c",b,b);
    gotoxy(x,y+2);
    printf("%c%c",b,b);

    gotoxy(x+34,y);
    printf("%c%c",b,b);
    gotoxy(x+34,y+1);
    printf("%c%c",b,b);
    gotoxy(x+34,y+2);
    printf("%c%c",b,b);
    printf("\033[0m");
}
void input(){       //game controls
    if(kbhit()){
        switch(getch()){
        case 'w':
        case 'W':
            if(y==1)    //up
                y-=0;
            else
                y-=3;
            break;
        case 's':
        case 'S':
            if(y>=17)   //down
                y+=0;
            else
                y+=3;
            break;
        case 'x':
        case 'X':
            break;
        }
    }
}
void changeDirection(){
    if(ballDir==downRight)
        ballDir=downLeft;
    else if(ballDir==downLeft)
        ballDir=upLeft;
    else if(ballDir==upLeft)
        ballDir=upRight;
    else
        ballDir=downRight;
}
void move(){
    switch(ballDir){
    case downRight:
        ballX+=2, ballY++;
        break;
    case downLeft:
        ballX-=2, ballY++;
        break;
    case upLeft:
        ballX-=2, ballY--;
        break;
    case upRight:
        ballX+=2, ballY--;
        break;
    default:
        break;
    }
}
void ball(){
    //Sleep(100);
    gotoxy(ballX,ballY);
    printf("O");
}
void conditions(){
    //conditions for top and bottom walls
    if(ballY<=0 || ballY>=20)
    changeDirection();
    //conditions for left bar
    else if((ballY==y||ballY==y+1||ballY==y+2)&&(ballX==4||ballX==5||ballX==6)){
        score++;
        changeDirection();
    }
    //conditions for right bar
    else if((ballY==y||ballY==y+1||ballY==y+2)&&(ballX==37||ballX==38||ballX==39)){
        score++;
        changeDirection();
    }
    //conditions for game over
    else if(life==0){
            system("cls");
            walls();
            gotoxy(17,10);
            printf("GameOver!");
            getch();
            exit(0);
    }
    else if(ballX==2 || ballX==3 || ballX>=40 || ballX>=41){
        life--;
        Sleep(1000);
        min=8, max=20;      //reset ball coordinates
        srand(time(NULL));
        ballX=min+(rand()%max);
        ballY=1;
    }
}
void scoreLife(){
    gotoxy(2,22);
    printf("Score: %d",score);
    gotoxy(2,23);
    printf("Life: %d\n",life);
}
int main(){
    int i=1;
    setup();
    system("cls");
    while(i=1){
        system("cls");
        walls();
        bar(x,y);
        input();
        ball();
        scoreLife();
        Sleep(100);
        move();
        conditions();
    }
    return 0;
}
