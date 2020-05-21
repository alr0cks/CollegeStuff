#include<stdio.h>
#include<omp.h>

int main()
{
    int id,i;
    #pragma omp parallel
    {
        for(i = 0; i<16; i++)
        {
            
            printf("\nI=%d BY %d",i,omp_get_thread_num());
            
        }
    }
        
    
    
    return 0;
    
}
