#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffleArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int j = rand() % (i + 1);

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printingTwoRows(char topRow[256], char bottomRow[256], int length, int nums[6])
{
    memset(topRow, '\0', sizeof(topRow));
    memset(bottomRow, '\0', sizeof(bottomRow));
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

int main()
{
    //! The array where we store the input numbers
    int nums[6];
    int num;
    //! The length of the array
    int length = sizeof(nums) / sizeof(nums[0]);
    int shuffleCount = 0;

    for (int i = 0; i < length; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        nums[i] = num;
    }

    //! Helper func Line[5-14], this shuffles the array
    shuffleArray(nums, length);
    while (1)
    {
        char topRow[256] = "";
        char bottomRow[256] = "";

        //! Moving the predences and the values in two separate rows
        printingTwoRows(topRow, bottomRow, length, nums);

        printf("%s\n%s\n", topRow, bottomRow);
        //! Variables for swapping the 2 indexes
        int swapIndexOne, swapIndexTwo;

        printf("1.st index to swap: ");
        scanf("%d", &swapIndexOne);
        printf("\n2.nd index to swap: ");
        scanf("%d", &swapIndexTwo);

        swapIndexOne--;
        swapIndexTwo--;

        char temp = nums[swapIndexOne];
        nums[swapIndexOne] = nums[swapIndexTwo];
        nums[swapIndexTwo] = temp;

        printingTwoRows(topRow, bottomRow, length, nums);

        printf("%s\n%-6s\n", topRow, bottomRow);
    }

    return 0;
}