#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char filename[50]){
    //OPENING AND READING FILE CONTENT
    FILE *fpr;
    fpr=fopen(filename,"r");
    if(fpr==NULL){
        printf("File not found!\n");
        exit(1);
    }
    char tempVar[999999];
    int index=0;
    char read=fgetc(fpr);

    //ENCRYPTION SALTING FILE CONTENT
    while(!feof(fpr)){
        read+=13;
        //printf("%c",read);
        tempVar[index]=read;
        index++;
        read=fgetc(fpr);
    }
    fclose(fpr);
    
    //ENCRYPTING FILE CONTENT!!
    FILE *fpw;
    fpw=fopen(filename,"w");
    if(fpw==NULL){
        printf("File not found!\n");
        exit(1);
    }
    for(index=0;index<=strlen(tempVar)-1;index++){
        putc(tempVar[index],fpw);
    }
    fclose(fpw);
    printf("\n%s encrypted successfully!\n\n",filename);

}

void decrypt(char filename[50]){
    //OPENING AND READING FILE CONTENT
    FILE *fpr;
    fpr=fopen(filename,"r");
    if(fpr==NULL){
        printf("File not found!\n");
        exit(1);
    }
    char tempVar[999999];
    int index=0;
    char read=fgetc(fpr);

    //DECRYPTION SALTING FILE CONTENT
    while(!feof(fpr)){
        read-=13;
        tempVar[index]=read;
        index++;
        read=fgetc(fpr);
    }
    fclose(fpr);
    
    //DECRYPTING FILE CONTENT!!
    FILE *fpw;
    fpw=fopen(filename,"w");
    if(fpw==NULL){
        printf("File not found!\n");
        exit(1);
    }
    for(index=0;index<=strlen(tempVar)-1;index++){
        putc(tempVar[index],fpw);
    }
    fclose(fpw);
    printf("\n%s decrypted successfully!\n",filename);
}

int main(){
    int choice;
    char file[50];
    printf("Choose any option:\n[ 1 ] --> Encrypt a file.\n[ 2 ] --> Decrypt a file.\n[ 3 ] --> Exit!\n\nEnter here: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("\nEnter the filename or filepath: ");
        scanf("%s",file);
        encrypt(file);
        break;
        case 2: printf("\nEnter the filename or filepath: ");
        scanf("%s",file);
        decrypt(file);
        break;
        case 3: exit(1);
        break;
        default: printf("Invalid option!\n");
    }

    return 0;
}
