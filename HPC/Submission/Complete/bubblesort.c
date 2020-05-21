#include<stdio.h>
#include<omp.h>
#include<math.h>

#define max 10
int arr[max];




void populate(int arr[])
{
 int i=0;
 for(i=0;i<max;i++)
  {
    arr[i]=max-i;
  }
}


void display(int arr[])
{
 for(int i=0;i<max;i++)
  {
   printf("%d",arr[i]);
   printf(" ");
  }
}

void serial_bubble(int arr[])
{
    printf("\nStart of execution: \n%f\n", omp_get_wtime());
    int temp;
    for(int i =0; i<max; i++)
    {
        for(int j = 0; j<max-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nEnd of execution: \n%f\n", omp_get_wtime()); 
    
}


void modified_bubblesort(int arr[])
{
 printf("\nStart of execution: \n%f\n", omp_get_wtime());
 for(int i=0;i<(max+1)/2; i++)
  {

        int j,k;
        int temp,temp2;
       #pragma omp parallel for
       for(k=0;k<max-1;k+=2)
	{
		if(arr[k]>arr[k+1])
		{
                        printf(" ");			
                        temp=arr[k+1];
			arr[k+1]=arr[k];
			arr[k]=temp;
		}
	}

        #pragma omp parallel for       
	   for(j=1;j<max-1;j+=2)
		{
			if(arr[j]>arr[j+1])
			{
				printf(" ");
				temp2=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp2;
			}
		}
  }
 printf("\nEnd of execution: \n%f\n", omp_get_wtime());
}


int main()
{
 populate(arr);
 display(arr);
 serial_bubble( arr);
 printf("\n");
 modified_bubblesort(arr);
 printf("\n");
 printf("sorted array :-\n");
 display(arr);
 printf("\n");
 return 0;
}

