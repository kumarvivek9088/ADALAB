//binarysearch using reccursion

#include <stdio.h>

int binarysearch(int arr[], int l, int n, int key){
    if (n >= l) {
        int mid = l + (n- l) / 2;
        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarysearch(arr, l, mid - 1, key);
        return binarysearch(arr, mid + 1, n, key);
    }
    return -1;

}
int main(){
    int array[100],n,s;
    printf("enter number of element: -");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter elements %d in sorted order: -",i+1);
        scanf("%d",&array[i]);
    }
    printf("Elements in arrays are: -");
    for (int i=0;i<n;i++){
        printf("%d \t",array[i]);
    }
    printf("\nEnter element to search : -");
    scanf("%d",&s);
    int result = binarysearch(array, 0, n, s);
    if (result == -1){
        printf("\nElement is not present in array\n");

    }
    else{
        printf("\nElement is present at index %d\n", result);
    }
    return 0;
}