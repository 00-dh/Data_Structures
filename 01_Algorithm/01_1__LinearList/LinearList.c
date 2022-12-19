#include<stdio.h>

//Big-O is O(n)
int LSearh(int ar[], int len, int target){
    for(int i = 0; i < len; i++){
        if(ar[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {0,1,2,3,4,5};

    int idx = LSearh(arr, sizeof(arr)/sizeof(int), 3);
    if(idx == -1){
        printf("target number is not in array\n");
    }
    else{
        printf("target number index: %d\n", idx);
    }
}