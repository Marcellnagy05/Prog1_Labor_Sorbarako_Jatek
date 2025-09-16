#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffleArray(int arr[], int length){
    for (int i = 0; i < length; i++)
    {
        int j = rand() % (i + 1);

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){
    //! The array where we store the input numbers
    int nums[6];
    int num;
    //! The length of the array
    int length = sizeof(nums) / sizeof(nums[0]);

    
    for(int i = 0; i < length; i++){
        printf("Enter a number: ");
        scanf("%d",&num);
        nums[i] = num;
    }
    
    //! Helper func Line[5-14], this shuffles the array 
    shuffleArray(nums,length);
    for(int i = 0; i < length; i++){
        printf("%d%6d\t",i+1,nums[i]);
        if((i+1 % 2 == 0)){
            printf("\n");
        }
    }
    
    return 0;
}