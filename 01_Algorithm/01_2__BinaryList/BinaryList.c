#include<stdio.h>

//big-O is log(n)
int BSearch(int ar[], int len, int target){
    int first = 0;
    int last = len - 1;
    int mid;
    while(first <= last){
        mid = (first+last)/2;
        if(target == ar[mid]){
            return mid;
        }
        else{
            if(target > ar[mid]){
                first = mid + 1;
            }
            else if(target < ar[mid]){
                last = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int index = BSearch(arr, sizeof(arr)/sizeof(int), 8);
    if(index == -1){
        printf("target number is not in array\n");
    }
    else{
        printf("target number index: %d\n", index);
    }
}