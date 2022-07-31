#include <stdio.h>
void bubblesort(int array[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[i]>array[j]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

int main(){
    int arr[100];
    int n;
    printf("Vivek Kumar\nA2305220527\n---------------------\n");
    printf("enter number of elements: -");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("enter element %d :- ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("unsorted array is :- \n");
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    bubblesort(arr,n);
    printf("\nsorted array is : - \n");
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}