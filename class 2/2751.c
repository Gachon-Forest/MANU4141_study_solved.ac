/*
Date: 7/10
No: 2751
Tier: s - 5
Name: 수 정렬하기 2
Language: C 99

선택 정열로 하면 안되는구만...

#include <stdio.h>

#define MAX 1000000

void selection_sort(int arr[], int n)
 {
    for (int i = 0; i < n - 1; i++)
     {
        int min = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min])
                min = j;
        }
       
        int temp = arr[i];
       
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int N, numbers[MAX];
    
    scanf("%d", &N);
   
    for (int i = 0; i < N; i++) 
      
        scanf("%d", &numbers[i]);
    
    selection_sort(numbers, N);

    for (int i = 0; i < N; i++) 
      
        printf("%d\n", numbers[i]);
    
    return 0;
}
*/

// 퀵 정열로 다시

#include <stdio.h>

#define MAX 1000000

void quicksort(int arr[], int low, int high); 

int partition(int arr[], int low, int high); 

int main() 
{
    int N, numbers[MAX];
    
    scanf("%d", &N);
   
    for (int i = 0; i < N; i++) 
        scanf("%d", &numbers[i]);
    
    quicksort(numbers, 0, N - 1);

    for (int i = 0; i < N; i++) 
        printf("%d\n", numbers[i]);
    
    return 0;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high); 

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
           
            int temp = arr[i];

            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
// 시봉방 왜?????
// 너무 어려움
// 아직은 못 풀듯...