#include<stdio.h>
#include<stdlib.h>
int month;

void head();

int main(){
    int W_day, date, Y_day, year, M_day, count=1, leap, Y_D1;
    printf("Enter the year: ");
    scanf("%d",&year);

    //Checking leap year
    if((year%4==0 && year%100!=0) || year%400==0)
    leap=1;
    else
    leap=0;
    //Weakday of  1 Jan
    Y_D1=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
    printf("%d\n",Y_D1);
    count=Y_D1+1;

    for(month=1;month<=12;month++){     //This is month loop, it will run 12 times
    head();
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)      //If current month have 31 days
        M_day=31;
        else if(month==2 && leap)      //Feb of leap year
        M_day=29;
        else if(month==2 && !leap)      //Feb of non-leap year
        M_day=28;
        else if(month==4||month==6||month==9||month==11)
        M_day=30;
        else
        exit(1);
        for(int i=1;i<count;i++){
            printf("     ");
        }

        for(date=1;date<=M_day;date++, count++){
            if(count>7){
                printf("\n");
                printf("%5d",date);
                count=1;
            }
            else
                printf("%5d",date);
        }
    }
    printf("\n");
    return 0;
}

void head(){
        printf("\n\n====================================\n");
        if(month==1)
        printf("\t\tJanuary");
        else if(month==2)
        printf("\t\tFebruary");
        else if(month==3)
        printf("\t\tMarch");
        else if(month==4)
        printf("\t\tApril");
        else if(month==5)
        printf("\t\tMay");
        else if(month==6)
        printf("\t\tJune");
        else if(month==7)
        printf("\t\tJuly");
        else if(month==8)
        printf("\t\tAugust");
        else if(month==9)
        printf("\t\tSeptember");
        else if(month==10)
        printf("\t\tOctober");
        else if(month==11)
        printf("\t\tNovember");
        else if(month==12)
        printf("\t\tDecember");
        printf("\n====================================\n");
        printf("  \033[1;31m  S\033[0m    M    T    W   Th    F    S\n");
}