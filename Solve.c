#include<stdio.h>
#include<math.h>
#define PI 3.14

//Distance between any two points in 3D
void dist3D(){
    float x1,x2, y1,y2, z1,z2, num,dist3D;
    printf("Warning: seperate coodinates using comma ','\n");
    printf("Enter the coordinates of point A: ");
    scanf("%f,%f,%f",&x1,&y1,&z1);
    printf("Enter the coordinates of point B: ");
    scanf("%f,%f,%f",&x2,&y2,&z2);
    num=((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
    dist3D=sqrt(num);
    printf("\nDistance between points A and B is %.2f\n",dist3D);
}

//Distance between any two points in 2D
void dist2D(){
    float x1,x2, y1,y2, num,dist2D;
    printf("Warning: seperate coodinates using comma ','\n");
    printf("Enter the coordinates of point A: ");
    scanf("%f,%f",&x1,&y1);
    printf("Enter the coordinates of point B: ");
    scanf("%f,%f",&x2,&y2);
    num=((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
    dist2D=sqrt(num);
    printf("\nDistance between points A and B is %.2f",dist2D);
}

//Factorial of any number
void factorial(){
    int x,y=1;
    printf("Enter any number to find its factorial: ");
    scanf("%d",&x);
    printf("\n!%d = ",x);
    for(int i=x;i>0;i--){
        y*=i;

        if(i!=1)
        printf("%d*",i);
        else
        printf("%d",i);
    }
    printf("\nFactorial of %d is %d\n",x,y);
}

//Volume of sphere
void sphereVol(){
    float r,sphereVol;
    printf("Enter the radius of sphere: ");
    scanf("%f",&r);
    sphereVol=(4.0/3.0)*PI*(r*r*r);
    printf("\nVolume of sphere is %.2f\n",sphereVol);
}

//Suface area of sphere 
void sphereAr(){
    float r,sphereAr;
    printf("Enter the radius of sphere: ");
    scanf("%f",&r);
    sphereAr=4.0*PI*(r*r);
    printf("\nSurface area of sphere is %.2f\n",sphereAr);
}

//Volume of hemi-sphere
void hemiSphereVol(){
    float r,hemiSphereVol;
    printf("Enter the radius of hemi-sphere: ");
    scanf("%f",&r);
    hemiSphereVol=(2.0/3.0)*PI*(r*r*r);
    printf("\nVolume of hemi-sphere is %.2f\n",hemiSphereVol);
}

//Surface area of hemi-sphere
void hemiSphereAr(){
    float r,hemiSphereAr;
    printf("Enter the radius of hemi-sphere: ");
    scanf("%f",&r);
    hemiSphereAr=3.0*PI*(r*r);
    printf("\nSurface area of hemi-sphere is %.2f\n",hemiSphereAr);
}

//Volume of Cone
void coneVol(){
    float r,h,coneVol;
    printf("Enter the radius of cone: ");
    scanf("%f",&r);
    printf("Enter the height of cone: ");
    scanf("%f",&h);
    coneVol=(1.0/3.0)*PI*(r*r)*h;
    printf("\nVolume of cone is %.2f\n",coneVol);
}

//Surface area of Cone
void coneAr(){
    float r,l,coneAr;
    printf("Enter the radius of cone: ");
    scanf("%f",&r);
    printf("Enter the slant height of cone: ");
    scanf("%f",&l);
    coneAr=PI*r*(l+r);
    printf("\nSurface area of cone is %.2f\n",coneAr);
}

//Volume of Cylinder
void cylinderVol(){
    float r,h,cylinderVol;
    printf("Enter the radius of cylinder: ");
    scanf("%f",&r);
    printf("Enter the height of cylinder: ");
    scanf("%f",&h);
    cylinderVol=PI*(r*r)*h;
    printf("\nVolume of cylinder is %.2f\n",cylinderVol);
}

//Surface area of Cylinder
void cylinderAr(){
    float r,h,cylinderAr;
    printf("Enter the radius of cylinder: ");
    scanf("%f",&r);
    printf("Enter the height of cylinder: ");
    scanf("%f",&h);
    cylinderAr=2.0*PI*r*(r+h);
    printf("\nSurface area of cylinder is %.2f\n",cylinderAr);
}

//Volume of cube
void cubeVol(){
    float a,cubeVol;
    printf("Enter the edge of cube: ");
    scanf("%f",&a);
    cubeVol=a*a*a;
    printf("\nVolume of cube is %.2f\n",cubeVol);
}

//Surface area of cube
void cubeAr(){
    float a,cubeAr;
    printf("Enter the edge of cube: ");
    scanf("%f",&a);
    cubeAr=6.0*(a*a);
    printf("\nSurface area of cube is %.2f\n",cubeAr);
}

//Volume of cuboid
void cuboidVol(){
    float l,b,h,cuboidVol;
    printf("Enter the length of cuboid: ");
    scanf("%f",&l);
    printf("Enter the width of cuboid: ");
    scanf("%f",&b);
    printf("Enter the height of cubiod: ");
    scanf("%f",&h);
    cuboidVol=l*b*h;
    printf("\nVolume of cuboid is %.2f\n",cuboidVol);
}

//Surface area of cuboid
void cuboidAr(){
    float l,b,h,cuboidAr;
    printf("Enter the length of cuboid: ");
    scanf("%f",&l);
    printf("Enter the width of cuboid: ");
    scanf("%f",&b);
    printf("Enter the height of cubiod: ");
    scanf("%f",&h);
    cuboidAr=2.0*((l*b)+(b*h)+(h*l));
    printf("\nSurface area of cuboid is %.2f\n",cuboidAr);
}

int main(){
    int option;

    printf("1 -> Distance between any two points A and B in 3D\n");
    printf("2 -> Distance between any two points A and B in 2D\n");
    printf("3 -> Factorial of any number\n");
    printf("4 -> Volume of sphere\n");
    printf("5 -> Surface area of sphere\n");
    printf("6 -> Volume of Hemi-sphere\n");
    printf("7 -> Surface area of Hemi-sphere\n");
    printf("8 -> Volume of cone\n");
    printf("9 -> Surface area of cone\n");
    printf("10 -> Volume of Cylinder\n");
    printf("11 -> Surface area of Cylinder\n");
    printf("12 -> Volume of cube\n");
    printf("13 -> Surface area of cube\n");
    printf("14 -> Volume of cuboid\n");
    printf("15 -> Surface area of cuboid\n");
    printf("\nChoose any option: ");
    scanf("%d",&option);
    printf("\n");

    switch(option){
        case 1: dist3D();
        break;
        case 2: dist2D();
        break;
        case 3: factorial();
        break;
        case 4: sphereVol();
        break;
        case 5: sphereAr();
        break;
        case 6: hemiSphereVol();
        break;
        case 7: hemiSphereAr();
        break;
        case 8: coneVol();
        break;
        case 9: coneAr();
        break;
        case 10: cylinderVol();
        break;
        case 11: cylinderAr();
        break;
        case 12: cubeVol();
        break;
        case 13: cubeAr();
        break;
        case 14: cuboidVol();
        break;
        case 15: cuboidAr();
        break;
        default: printf("\nInvalid option!\n");
    }

    return 0;
}
