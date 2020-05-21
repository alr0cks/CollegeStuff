import random
import time

def quicksort(arr, start , stop):
    if(start < stop):
        pivoti = partitionRand(arr, start, stop)
        print(pivoti)
        quicksort(arr , start , pivoti - 1)
        quicksort(arr, pivoti + 1, stop)

def partitionRand(arr , start, stop):
    randpivot = random.randrange(start, stop)

    arr[start], arr[randpivot] = arr[randpivot], arr[start]
    return partition(arr, start, stop)

def partition(arr,start,stop):
    pivot = start
    i = start + 1
    for j in range(start + 1, stop + 1):
        if arr[j] <= arr[pivot]:
            arr[i] , arr[j] = arr[j] , arr[i]
            i = i + 1
    arr[pivot] , arr[i - 1] = arr[i - 1] , arr[pivot]
    pivot = i - 1
    return (pivot)

array = [29,12,87,26,32,71,16]
start_time = time.time()
quicksort(array, 0, len(array) - 1)
end_time = time.time()
print(array)
print("Time taken = ",end_time-start_time)
