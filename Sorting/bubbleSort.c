/*
Bubble Sort: Rev 1.0

= Start with the first element of the array and compare it to the next element.
- If the first element is greater than the second, swap them.
- Move to the next pair of adjacent elements and repeat the comparison and swap if necessary.
- Continue this process until the end of the array is reached.
- After each complete pass through the array, the largest element will have "bubbled up" to its correct position.
- Repeat the entire process for the remaining unsorted portion of the array.
- The algorithm stops when no swaps are needed during a pass, meaning the array is sorted.

Features:
Use AUTO_INPUT for Initializing the array with Random input (<1000)
Use USER_INPUT for Initializing the array with Input From user.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define AUTO_INPUT
#define USER_INPUT

void printArray(int *pointerToArray, int arraySize)
{

    printf("\n");
    for (int i = 0; i < arraySize; i++)
    {
        // Access and print each element in the array
        printf("%d  ", *(pointerToArray + i));
    }
    printf("\n");
}

void bubbleSort(int *pointerToArray, int arraySize)
{

    // Temporary variable to hold values during swapping
    int storeTempVal;

    // Outer loop for the number of passes needed
    for (int i = 0; i < arraySize; i++)
    {
        // Inner loop to compare adjacent elements
        for (int j = 1; j < arraySize; j++)
        {
            // If the previous element is greater, swap it with the current element
            if (pointerToArray[j - 1] > pointerToArray[j])
            {

                storeTempVal = pointerToArray[j - 1];
                pointerToArray[j - 1] = pointerToArray[j];
                pointerToArray[j] = storeTempVal;
            }
        }
    }
}

int main(void)
{

    srand(time(0));
    // Variable to store array size that is given by user
    int userArraySize;
    // Variable to store integer variable
    int userInputElement;
    // Variable to keep count while increasing the size of array
    int userCount = 0;

    printf("\nEnter the size of array: ");
    scanf("%d", &userArraySize);

    // Array to store the input
    int userArray[userArraySize];
    // Temporary array to store character input to check if End of Input
    char userBuffer[10];

    printf("\nEnter Elements for the array( Integer only) (type ` to exit filling the array): ");

    while (userCount < userArraySize)
    {
#ifdef USER_INPUT
        scanf("%s", userBuffer);
#endif

#ifdef AUTO_INPUT
        int storeInt;
        // Generate a random number between 0 and 999
        storeInt = rand() % 1000;
        // Convert the number to a string
        snprintf(userBuffer, sizeof(userArraySize), "%d", storeInt);
#endif

#ifdef USER_INPUT
        // Check if the input is the special exit character '`'
        if (userBuffer[0] == '`' && userBuffer[1] == '\0')
        {

            break;
        }
#endif
        // Convert the string to an integer and store it in the array
        userInputElement = atoi(userBuffer);
        userArray[userCount] = userInputElement;
        userCount++;
    }

#ifdef USER_INPUT
    // If the user exited early, fill the remaining elements with 0
    while (userCount < userArraySize)
    {

        for (int i = 0; i < userArraySize; i++)
        {
            userArray[userCount] = 0;
            userCount++;
        }
    }
#endif

    printf("Array Before Sorting: ");
    printArray(userArray, userArraySize);

    bubbleSort(userArray, userArraySize);

    printf("\nAfter Bubble Sort: \n");
    printArray(userArray, userArraySize);

    return 0;
}

/*
Issue -1:
Error:


The error "variable-sized object may not be initialized" occurs because in C, you cannot initialize a variable-length array (VLA) directly when you declare it. VLAs are arrays where the size is not a constant expression but instead is determined at runtime. Since the size is determined dynamically, the compiler doesn't allow initializing the array elements at the time of declaration.

Code that caused it:
    printf("\nEnter the size of array: ");
    scanf("%d",&userArraySize);

    int userArray[userArraySize]={0};

Resolution:
Don't initialize the array as the size is determined at run time.

int userArray[userArraySize];


Issue -2:

while(userCount<userArraySize)
    {
        if( userInputElement != '`'){
        scanf("%d",&userInputElement);
        userArray[userCount] = userInputElement;
        userCount++;
        }

        else{
            break;
        }
    }

    printf("\nUser Count:%d\n",userCount);

    User Count euqals to userArraySize even after break statement execution.

Solution:

The scanf cannot parse the character '`' (which is not a valid integer) as we are reading input as integer. This is leading to unexpected behaviour.



Issue 3-

Differnce between
scanf("%c",%input) and  scanf(" %c",%input)

scanf(" %c",%input) - Ignore any leading whitespace (including newlines). The space before %c tells scanf to skip any whitespace.


*/