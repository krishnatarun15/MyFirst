#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
FILE *p,*fp;
int selection[15],q;
struct cafe
{
	int slno;
	char name[15];
	int price;
}item;
struct payments
{
	int slno1;
	char name1[15];
	int price1;
}bill; 

void admin();
void user();
void addition();
void menu();
void search();
void billing();
void payments();
void back();
void deletingitems();


void admin()
{
	int i;
A:
	printf("\t\t 1.ADD NEW ITEM TO MENU\n\n");
	printf("\t\t 2.REMOVE ITEM FROM MENU\n\n");
	printf("\t\t 3.VIEW PAYMENTS\n\n");
	printf("\t\t 4.BACK TO LOGIN\n\n");
	printf("\t\t 5.VIEW MENU\n\n");
	
	printf("\t\t 6.EXIT\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			addition();
			goto A;
			break;
	    case 2:
	    	
	    	deletingitems();
			goto A;
	    	break;
	    case 3:
		    payments();
		    goto A;
			break;
		case 4:
			back();
			goto A;
			break;
	    case 5:
		    menu();
			goto A;
			break;		
		case 6:
			exit(0);
		default:
		   printf("INVALID INPUT\n");	     		
	}
	printf("CHOOSE OPTION NO.:\n");
}


void menu()
{
	int m;
	printf("\tItem Sl.no\t\tItem Name\t\tItem Price\n");
	fp=fopen("menu.txt","r");
	if(fp==NULL)
	{
		printf("cannot open file\n");
	}
	else
	{
	
    while(	fread(&item,sizeof(item),1,fp))
	{
		printf("\t%d\t\t\t%s\t\t\t%d\n",item.slno,item.name,item.price);
	}
}
fclose(fp);
}

void user()
{
	int k=0,count;
	char ch,z;
	printf("\t\tREFER MENU\n\n");
	menu();
	printf("DO YOU WANT TO SEARCH FOR ITEM ? (Y/N) \n");
	ch=getch();
	if( ch == 'Y' || ch == 'y')
	{
		search();
	}
	printf("\nSELECT ITEMS FROM MENU\n");

	billing();
}

void billing()
{
	int y=0,i=0,total=0,selection[15];
	char ch='Y';
	
	fflush(stdin);
	while(ch!='N')
	{
		printf("ENTER SERIAL NO. OF ITEM:\n");
		scanf("%d",&selection[i]);
		y++;
		printf("WANT TO SELECT ANY OTHER?(Y)  if not(N)\n");
		fflush(stdin);
		scanf("%c",&ch);
		i++;
	}
		fflush(stdin);

   
	p=fopen("bill.txt","a");
	fp=fopen("menu.txt","r");
	printf("\tItem Sl.no\t\tItem Name\t\tItem Price\n");
	
	i=0;
	
	while(fread(&item,sizeof(item),1,fp))
	{
		if(item.slno==selection[i]){
		printf("\t%d\t\t\t%s\t\t\t%d\n\n",item.slno,item.name,item.price);
		
		total=total+ item.price;
		fwrite(&bill,sizeof(bill),1,p);
		i++;
		
	}
	
    }
	 
    fflush(stdin);
	printf("\n\n\n\t TOTAL=%d\n",total);
	fclose(fp);
	fclose(p);
	printf("\n\n");
	admin();
}


void addition()
{
	int b,i,j=0;
	p=fopen("menu.txt","a");
	printf("HOW MANY ITEMS YOU WANT TO ADD?\n");
	scanf("%d",&b);
	q=q+b;
		for(i=0;i<b;i++){
		printf("Serial number:");
		scanf("%d",&item.slno);
        printf("Item name:");
        scanf("%s",&item.name);
        printf("Item Price:");
        scanf("%d",&item.price);
        fwrite(&item,sizeof(item),1,p);
        fflush(stdin);
}

	fclose(p);
	printf("ITEM(S) ADDED SUCCESSFULLY\n");
}



void deletingitems()
	{
		int f;
		printf("\nPlease Enter serial number to delete :");
		scanf("%d",&f);
		FILE *fp,*fp1;
	    fp=fopen("menu.txt","r");
		fp1=fopen("delitems.txt","w");
		while(fread(&item,sizeof(item),1,fp))
		{
		if(item.slno==f)
		{
			printf("DELETED");
		}
		else
		{
			fwrite(&item,sizeof(item),1,fp1);
		}
		}
		fclose(fp);
    	fclose(fp1);	
    	remove("menu.txt");
    	rename("delitems.txt","menu.txt");
    	printf("\n\n\n");
    }


void search()
{
	fflush(stdin);
	char element[10];
	int i=0;
	printf("Enter name of item that you want to search\n");
	gets(element);
	p=fopen("menu.txt","r");
while(fread(&item,sizeof(item),1,p)){

	if((stricmp(element,item.name))==0){
		printf("ITEM SL_NO.\t ITEM NAME \t ITEM PRICE\n");
		printf("\t%d\t\t%s\t\t%d",item.slno,item.name,item.price);
	}
	
}
}


void payments()
{
	printf("\t\t\t CAFE MANAGEMENT SYSTEM\t\t\t\n\n");
	printf("\tItem Sl.no\t\tItem Name\t\tItem Price\n");
	printf("\t==========\t\t=========\t\t==========\n");
	p=fopen("bill.txt","r");
	while(fread(&bill,sizeof(bill),1,p)){
		printf("\t%d\t\t\t%s\t\t\t%d\n\n",item.slno,item.name,item.price);
	}
	fclose(p); 
	admin();
}

void introduction()
{
	printf("\n\n\n\t\t\t-------------------------------WELCOME------------------------------\n");
	printf("\n\n\t\t\t\t\t\t\tCAFE  ");
	printf("\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~");
	
	printf("\n\n\n\n\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t\tSubmitted By ");
	printf("\n\t\t\t\t\t\t\t\t\t\t\tName :Management CAFE ");
}



int main()
{
 
 introduction();
 getch();
 back();
 return 0;
}

 void back()
 {
 	int j;
  system("cls");
  
	printf("\n\n\n\t\t\t-------------------------------WELCOME------------------------------\n");
	printf("\n\n\t\t\t\t\t\t\tCAFE  ");
	printf("\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\n\n");
 printf("\t\t1.ADMIN\n");
 printf("\t\t2.USER\n");
 fflush(stdin);
 scanf("%d",&j);
 
 switch(j)
 {
 	case 1:
 		admin();
 		break;
 	case 2:
 		user();
 		break;
 	default :
 		printf("INVALID INPUT\n");
 		break;
 }
}
 

