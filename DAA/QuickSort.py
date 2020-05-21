def quicksort(low,high,a):
    if(low<high):
        b = []
        b = a
        j = partition(low,high,b)
        quicksort(low,j-1,b)
        quicksort(j+1,high,b)
        return b    
        
        
def partition(low,high,a):
    b = []
    b = a
    pivot = b[low]
    i = low
    j = high
    while (i<=j):
        while True:
            i = i +1
            if(b[i]<= pivot):
                break
        while True:
            j = j-1
            if(b[j]>pivot):
                break
        if(i<=j):
            b[i],b[j]=b[j],b[i]
        
    b[low],b[j]=b[j],b[low]
    return j

a = []
n =int(input("Enter the Number of elements tobe Quicksorted:"))
for i in range(0,n):
    num = int(input())
    a.append(num)

b = quicksort(0,len(a)-1,a)
print (b)
        
        
