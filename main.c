#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffleArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        //! We chose a random number between 1 and i
        int j = rand() % (i + 1);

        //! We select the i indexed element of the array and pass it to our temporary container
        int temp = arr[i];
        //! We pass the value of our random indexed element to the i indexed element
        arr[i] = arr[j];
        //! after that we will pass the temp which contains the i indexed element to our randomly indexed element
        arr[j] = temp;
    }
}

int compareArr(int arrA[], int arrB[], int length){
    for (int i = 0; i < length; i++)
    {
        //! We check if array A's i indexed element is equal to array B's i indexed element if not we step out of the function
        if(arrA[i] != arrB[i]) return 0;
    }
    //! If all elements are equal we return 1 (True)
    return 1;
}

void printingTwoRows(char topRow[256], char bottomRow[256], int length, int nums[6])
{
    //! We are emptying both arrays before we are setting it again Line[35,36]
    memset(topRow, '\0', 256);
    memset(bottomRow, '\0', 256);

    for (int i = 0; i < length; i++)
    {
        //! Declaring a temporary buffer to store one element
        char tempBuff[32];

        //! sprint AKA "string print" is for storing a formatted string in a buffer
        sprintf(tempBuff, "%-6d", i + 1);
        //! Copiing our temp to our topRow array
        strcat(topRow, tempBuff);

        sprintf(tempBuff, "%-6d", nums[i]);

        //! Copiing our temp to our bottomRow array
        strcat(bottomRow, tempBuff);
    }
}

int *sortArr(int arr[], int length)
{
    //! We are allocating the proper size to our dynamic array
    int *returned = malloc(length * sizeof(int));
    //! If the allocating fails we return NULL
    if (!returned)
        return NULL;
    //! Passing all the elements of our arr to the returned array Line[53-66]
    for (int i = 0; i < length; i++)
    {
        returned[i] = arr[i];
    }   

    //! Sorting algorithm
    for (int i = 0; i < length - 1; i++)
    {
        //! Setting a min index to our i
        int minIdx = i;
        for (int j = i + 1; j < length; j++)
        {
            //! If our minIdx (i) indexed element is bigger than the j indexed element
            if (returned[j] < returned[minIdx])
            {
                //! We set the minIdx to j
                minIdx = j;
            }
        }
        //! So if the element smaller then the element after it we swap i with i 
        //! (basically doing nothing), but if its bigger we swap those 2 elements
        int temp = returned[i];
        returned[i] = returned[minIdx];
        returned[minIdx] = temp;
    }
    //! In the end we return our sorted array
    return returned;
}

int main()
{
    //! The array where we store the input numbers
    int nums[6];
    //! The num variable which we will put in the array from Line[85-90]
    int num;
    //! The length of the array
    int length = sizeof(nums) / sizeof(nums[0]);

    //! We take 6 inputs from the user
    for (int i = 0; i < length; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        nums[i] = num;
    }

    //! Sorted by ascending array
    int *sortedNums = sortArr(nums, length);
    
    //! Helper func Line[5-14], this shuffles the array
    shuffleArray(nums, length);
    while (1)
    {
        //! 2 char arrays with a fixed size of 256 to store the two rows separately
        char topRow[256] = "";
        char bottomRow[256] = "";

        //! Moving the predences and the values in two separate rows
        printingTwoRows(topRow, bottomRow, length, nums);

        //! Printing out these 2 rows
        printf("%s\n%s\n", topRow, bottomRow);
        //! Variables for swapping the 2 indexes
        int swapIndexOne, swapIndexTwo;

        //! Chosing which elements to swap
        printf("1.st index to swap: ");
        scanf("%d", &swapIndexOne);
        printf("\n2.nd index to swap: ");
        scanf("%d", &swapIndexTwo);

        //! changing the indexing to the correct values
        swapIndexOne--;
        swapIndexTwo--;

        //! Swapping the selected elements
        int temp = nums[swapIndexOne];
        nums[swapIndexOne] = nums[swapIndexTwo];
        nums[swapIndexTwo] = temp;

        //! Rearranging the array according to the swap
        printingTwoRows(topRow, bottomRow, length, nums);

        //! Using a helper function Line[47-73] which compares the sorted list Line[91]
        if(compareArr(sortedNums,nums,length)){
            //! If they are identical it means the user correctly sorted the array by hand so we print out the sorted array
            printf("%s\n%-6s\n", topRow, bottomRow);
            //! We congratulate and break out of the while loop in Line[131]
            printf("Congratulations you won!");
            break;
        }
    }
    //! We are freeing the allocated memory for the sortedNums dynamic array
    free(sortedNums);
    return 0;
}