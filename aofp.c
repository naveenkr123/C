#include<stdio.h>

int add(int x,int y){
  return(x+y);
}
int subtract(int x,int y){
  return(x-y);
}
int multiply(int x,int y){
  return(x*y);
}
int divide(int x,int y) {
  if (y!=0)
    return(x/y);
  else
    return 0;
}

int main(){
    int x,y,choice,result;
    int (*op[4])(int,int);

    op[0]=add;
    op[1]=subtract;
    op[2]=multiply;
    op[3]=divide;

    printf("Enter first integers: ");
    scanf("%d",&x);
    printf("Enter second integers: ");
    scanf("%d",&y);
    printf("Choose any option:\n0 --> Add\n1 --> Subtract\n2 --> Multiply\n3 --> Divide\n");
    printf("Enter here: ");
    scanf("%d",&choice);
    result=op[choice](x,y);
    printf("Result is %d\n",result);

    return 0;
}