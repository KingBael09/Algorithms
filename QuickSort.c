#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int piviot = arr[low];

    int start = low;
    int end = high;

    while(start < end){
        while(arr[start] <= piviot){
            start++;
        }
        while(arr[end]>piviot){
            end--;
        }
        if(start < end){
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[low], &arr[end]);

    return end;
}

int quickSort(int arr[], int low, int high){
    if(low < high){
        int p = partition(arr, low, high);

        quickSort(arr, low, p -1);
        quickSort(arr, p+1, high);
    }
}

void display(int arr[], int n){
    printf("\nDisplaying: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int size;

    printf("\nEnter size of Array: ");
    scanf("%d", &size);

    int arr[size];

    printf("\nEnter %d Elements: \n",size);

    for(int i = 0; i<= size -1;i++){
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted Array: ");
    display(arr, size);
    quickSort(arr,0,size-1);
    display(arr, size);

}