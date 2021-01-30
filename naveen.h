/*  In this header file, there're declarations for math's formula functions.
    NO COPYRIGHT (C) 2021, so you can distribute it and/or modify it.
    This header file "naveen.h" is written by Naveen Kumar at date 30-Jan-2021.
*/

#ifndef        _MATH_H
#define        _MATH_H 

#define         PI 3.14


float cuboidAr(float l,float b,float h){     //surface ar. of cuboid
    return(2.0*((l*b)+(b*h)+(h*l)));
}
float cuboidVol(float l,float b,float h){       //Vol. of cuboid
    return(l*b*h);
}
float factorial(int x){       //Factorial of any number
    int y=1;
    for(int i=x;i>0;i--){
        y*=i;
    }
    return(y);
}
float cubeVol(float a){     //vol. of cube
    return(a*a*a);
}
float cubeAr(float a){      //surface ar. of cube
    return(6.0*(a*a));
}
float sphereVol(float r){       //vol. of sphere
    return((4.0/3.0)*PI*(r*r*r));
}
float sphereAr(float r){      //surface ar. of sphere
    return(4.0*PI*(r*r));
}
float hemiSphereVol(float r){       //vol. of hemi-sphere
    return((2.0/3.0)*PI*(r*r*r));
}
float hemiSphereAr(float r){     //Surface ar. of hemi-sphere
    return(3.0*PI*(r*r));
}
float coneVol(float r,float h){      //Vol. of Cone
    return((1.0/3.0)*PI*(r*r)*h);
}
float coneAr(float r,float l){      //Surface ar. of Cone
    return(PI*r*(l+r));
}
float cylinderVol(float r,float h){     //Volume of Cylinder
    return(PI*(r*r)*h);
}
float cylinderAr(float r,float h){      //Surface area of Cylinder
    return(2.0*PI*r*(r+h));
}

#endif