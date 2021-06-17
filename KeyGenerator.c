//This program can generate random serial keys, you can use those keys as a strong password.
//This program is made for linux. For windows, you need to do changes at lines 5 and 26.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>  //#include<windows.h    for windows
#include<time.h>
void key(){
    char num[10]={'0','1','2','3','4','5','6','7','8','9'};
    char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char temp;
    srand(time(0));
    for(int i=1;i<20;i++){
        if(i==5 || i==10 || i==15)
        temp='-';
        else if(i==3 || i==6 || i==12 || i==19)
        temp=num[rand()%10];
        else
        temp=alphabet[rand()%26];
    printf("%c",temp);
    }
}
int main(){
    for(int i=0;i<5;i++){
        key();
        printf("\n");
        sleep(1);   //Sleep(1000) for windows
    }
    return 0;
}
