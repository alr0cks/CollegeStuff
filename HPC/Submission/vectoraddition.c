#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void filegenerator(int n,char a[])
{
	FILE *fptr;
	fptr=fopen(a, "w");
	int x;
	for(int i=0;i<n;i++)
	{
		x=rand()%100;
 		fprintf(fptr," %d \n",x);	
	}
	fclose(fptr);		
}

void addition(char a[],char b[],char c[],int n)
{
	FILE *fptr1,*fptr2,*fptr3,*fptr;
	fptr1=fopen(a, "r");
	fptr2=fopen(b, "r");
	fptr3=fopen(c, "w");
	int in1,in2;	
	int output;
	#pragma parallel omp for private(i) 
	for(int i=0;i<n;i++)
	{
		fscanf(fptr1, "%d", &in1);
		fscanf(fptr2, "%d", &in2);
		output=in1+in2;
		fprintf(fptr3," %d \n",output);	
	}
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	
}

int main()
{
	int n;
	printf("enter number of elements:\n");
	scanf("%d",&n);
	filegenerator(n,"file1.txt");
	filegenerator(n,"file2.txt");
	FILE *fptr1,*fptr2,*fptr3; 
	fptr1 = fopen("file1.txt","r");
	fptr2 = fopen("file2.txt","r");
	
	addition("file1.txt","file2.txt","file3.txt",n);
	printf("\nRESULTS ARE STORED IN FILE3: \n");
	return 0;
}

