#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//#include<system.h>
#include<string.h>

void main()
{
	FILE *fp,*ft;
	char another,choice;
	struct emp
	{
		char name[10];
		int age;
		float salary;
	}e;
	char empname[10];
	long int recsize;

	fp=fopen("Emp.DAT","rb+");

	if(fp==NULL)
	{
		fp=fopen("Emp.DAT","wb+");

		if(fp==NULL)
		{
			puts("Cannot open file");
			exit(1);
		}
	}

	recsize=sizeof(e);

	while(1)
	{
		clrscr();

		gotoxy(30,10);
		printf("1. Add records");
		gotoxy(30,12);
		printf("2. List records");
		gotoxy(30,14);
		printf("3. Modify records");
		gotoxy(30,16);
		printf("4. Delete records");
		gotoxy(30,18);
		printf("5. Exit");
		gotoxy(30,20);
		printf("Your choice");

		fflush(stdin);
		choice=getche();

		switch(choice)
		{
			case 1:

				fseek(fp,0,SEEK_END);
				another='y';

				while(another=='y'||another=='Y')
				{
					printf("Enter name, age and salary");
					scanf("%s %d %f",e.name,e.age,e.salary);
					fwrite(&e,recsize,1,fp);
					printf("\nAdd another record?? (y/n)");
					fflush(stdin);
					another=getche();
				}
			break;

			case 2:
				rewind(fp);

				while(fread(&e,recsize,1,fp)==1)
				{
					printf("\n%s %d %f",e.name,e.age,e.salary);
				}
			break;

			case 3:

			another='y';
			while(another=='y');
			{
				printf("\nEnter employee name to modify");
				scanf("%s",empname);

				rewind(fp);
				while(fread(&e,recsize,1,fp)==1)
				{
					if(strcmp(e.name,empname)==0)
					{
						printf("\nEnter new name, age & salary");
						scanf("%s %d %f",e.name,&e.age,&e.salary);
						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&e,recsize,1,fp);
						break;
					}
				}
				printf("\nModify another record??(y/n)");
				fflush(stdin);
				another=getche();
			}
			break;

			case 4:

			another='y';
			while(another=='y'|| another=='Y')
			{
				print("\nEnter employee name to delete");
				scanf("%s",empname);

				ft=fopen("Temp.DAT","wb");

				rewind(fp);
				while(fread(&e,recsize,1,fp)==1)
				{
					if(strcmp(e.name,empname)!=0)
/* print list without deleted name*/    fwrite(&e,recsize,1,ft);
				}
				fclose(fp);
				fclose(ft);
				remove("Emp.DAT");
				rename("Temp.DAT","Emp.DAT");

				fp=fopen("Emp.DAT","rb+");
				printf("Delete another record??(y/n)");
				fflush(stdin);
				another=getche();
			}
			break;

			default:
				fclose(fp);
				exit(0);
		}
	}
}