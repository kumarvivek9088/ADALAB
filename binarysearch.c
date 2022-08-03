//binary key program without reccursion
# include <stdio.h>
void binarysearch(int array[],int n,int key){
  int first = 0;
  int last = n - 1;
  int middle = (first+last)/2;
  while (first <= last) {
    if (array[middle] < key)
      first = middle + 1;
    else if (array[middle] == key) {
      printf("%d found at location %d and at index %d.\n", key, middle+1,middle);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", key);
}

int main(){
    int array[100],n,s;
    printf("Enter number of elements: -");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter elements %d in sorted order: -",i+1);
        scanf("%d",&array[i]);
    }
    printf("Array is: -\n");
    for (int i=0;i<n;i++){
        printf("%d \t",array[i]);
    }
    printf("\nEnter element to search: - ");
    scanf("%d",&s);
    binarysearch(array,n,s);

    returnv 0;
}
