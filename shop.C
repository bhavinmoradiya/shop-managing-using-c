
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define mobile 10000
#define laptop 30000
#define tv 40000

struct customer {

    int billno,total;
    char name[20],date[10];

}c;


void irec();
void vrec();
void drec();
void srec();

FILE *fp;
int main(){

    int i,ch;
//    clrscr();

    do{
    printf("\nWELCOME TO SHOP");
    printf("\n1.INSERT NEW BILL");
    printf("\n2.VIEW BILL");
    printf("\n3.DELETE BILL");
    printf("\n4.SEARCH RECORD");
    printf("\n5.EXIT");
    printf("\nChoose : ");
    scanf("%d",&ch);

    switch(ch){

    case 1:
    irec();
    break;

    case 2:
    vrec();
    break;


    case 3:
    drec();
    break;

    case 4:
    srec();
    break;

    case 5:
    printf("Exititng....");
    break;

    default:
    printf("Choose valid Option!");
    }

    }while(ch != 5);
    getch();
    return 0;
}

void irec(){


    int ch,quan;

    fp=fopen("shop.txt","a");
    printf("\nENTER BILL NUMBER : ");
    scanf("%d",&c.billno);

    printf("\nENTER CUSTOMER'S NAME : ");
    scanf("%s",&c.name);

    printf("\nENTER DATE : ");
    scanf("%s",&c.date);

    printf("\nSELECT NAME OF THE PRODUCT ");
    printf("\nPRESS 1 FOR MOBILE \nPRESS 2 FOR LAPTOP \nPRESS 3 FOR TV\n ");
    scanf("%d",&ch);

    switch(ch){

    case 1:
    printf("Enter Quantity : ");
    scanf("%d",&quan);
    c.total=quan*mobile;
    break;

    case 2:
    printf("Enter Quantity : ");
    scanf("%d",&quan);
    c.total=quan*laptop;
    break;

    case 3:
    printf("Enter Quantity : ");
    scanf("%d",&quan);
    c.total=quan*tv;
    break;

    default:
    printf("Please! Choose valid Option");
    }

    fwrite(&c,sizeof(c),1,fp);

    printf("Your Total is %d",c.total);
    printf("\nThank you For Shopping");

    fclose(fp);
    getch();
}


void vrec(){
    fp=fopen("shop.txt","r");

    if(fp == NULL){
    printf("\nFile is empty");
    exit(0);
    }

    else{

    printf("\nBILL NO\t\tDATE \t\tNAME\t\tTOTAL");
    while(fread(&c,sizeof(c),1,fp))
    printf("\n%d \t\t%s \t%s \t\t%d",c.billno,c.date,c.name,c.total);
    fclose(fp);}

    getch();

}

void drec(){
    {
    FILE *fp1,*fpt;
    int n, ch;
    printf("Enter the Bill no you want to delete :");
    scanf("%d", &n);

    fp1 = fopen("shop.txt", "r");
    fpt = fopen("temp.txt", "w");
    while(fread(&c,sizeof(c),1,fp1))
      {
       ch = c.billno;
       if (ch != n)
        fwrite(&c,sizeof(c),1,fpt);
      }
      fclose(fp1);
      fclose(fpt);
      fp1 = fopen("shop.txt", "w");
      fpt = fopen("temp.txt", "r");
      while(fread(&c,sizeof(c),1,fpt))
       fwrite(&c,sizeof(c),1,fp1);
      printf("\nRECORD DELETED\n");
      fclose(fp1);
      fclose(fpt);
     }


 }

 void srec(){

    int n, r;
    printf("\nEnter the Bill no you want to search  :");
    scanf("%d", &n);

    fp = fopen("shop.txt", "r");
    while (fread(&c, sizeof(c), 1, fp))
    {
    r = c.billno;
    if (r == n)
    {
    printf("\nBILL DATE = %s", c.date);
    printf("\nNAME      = %s", c.name);
    printf("\nTOTAL     = %d", c.total);
    }
    }
    fclose(fp);
    }
