#include <stdio.h>
//function for the factorial
int fctl(int n) {
   int f;
   for(f=1;n>1;n--){
       f*=n;
   }
   return f;
}
int nCr(int n,int r){
    int ans;
    //Using factorial function in below formula
    ans=fctl(n)/(fctl(r)*fctl(n-r));
    return ans;
}
int main() {
   int n,row,column;
   n=7;
   for(row=0;row<=n;row++){
        //loop for spacing before triangle
        for(column=0;column<=n-row;column++){
            printf("  ");
        }
        //loop for Pascal triangle
        for(column=0;column<=row;column++){
            printf(" %3d",nCr(row,column));
        }
    printf("\n");
   }
   return 0;
}