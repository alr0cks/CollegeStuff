#include<stdio.h>
#include<omp.h>
int main()
{	int i,j,start,end;
	int n,temp=0;
	int arr[10],z;
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
			scanf("%d",&arr[i]);
	}
double total_time, start_time, end_time;
start_time=omp_get_wtime();

	for(z=0;z<n+1/2;z++)
	{
	#pragma omp parallel for
	
	for(i=0;i<n-1;i+=2)
		{
		
		if(arr[i]>arr[i+1]){
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}                                                              
	
	}
	#pragma omp parallel for
	for(j=1;j<n-1;j+=2)
		{
		
		if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}                                                              
	
		}
}
end_time=omp_get_wtime();
total_time=end_time-start_time;
printf("total time taken : %f", total_time);

printf("\nSorted array is:\n");
for(int z=0;z<n;z++)
{
	printf("%d",arr[z]);
	printf("\n");
}

}
