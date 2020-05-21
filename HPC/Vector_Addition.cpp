#include<iostream>
//#include<omp.h>
# define MAX 10000

using namespace std;

void populate(int arr[],int n){
	
	for(int i=0;i<n;i++)
	{
		arr[i]=i;
		
	}
	
}

int *sum(int arr1[], int arr2[],int n)
{
	int * temp;
	for(int i =0;i<n;i++)
	{
		temp[i] = arr1[i]+arr2[i];
	}
	
	return temp;
}	

int main()
{
	int n,arr1[MAX],arr2[MAX];
	cout<<"Enter the No. of Elements in Vector:";
	cin>>n;
	populate(arr1,n);
	populate(arr2,n);
	for(int i=0;i<n;i++)
	{
		cout<<"1:"<<arr1[i]<<" "<<"2:"<<arr2[i];
		cout<<"\n";
	
	}
	int * add=sum(arr1,arr2,n);
	//cout<<"Sum:";
	for(int i=0;i<n;i++)
	{
	
		cout<<add[i]<<"\n";
		
	
	}
}

	
	
	
	
	
	
	
	
		
