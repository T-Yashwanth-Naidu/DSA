#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STATIC_ARRAY_SIZE 15

#define DISPLAY_STATIC_ARRAY
#define DISPLAY_DYNAMIC_ARRAY
#define DISPLAY_2D_ARRAY
#define DISPLAY_3D_ARRAY
#define DISPLAY_4D_ARRAY
#define DISPLAY_Multi_2D_ARRAY

void printArray(int *pointerToArray, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(pointerToArray + i));
    }
    printf("\n");
}


#ifdef DISPLAY_STATIC_ARRAY
void staticArray(void) {

    printf("\n Static Array\n");

    /* This is a simple static array.
       It Can be quite useful when you know the size of the array.   
    */
    int static_array[STATIC_ARRAY_SIZE] = {0};

    for (int i = 0; i < STATIC_ARRAY_SIZE; i++) {
        static_array[i] = rand() % 1000; // Random values between 0 and 999
    }

    printf("\nOutput of Static Array: \n");
    printArray(static_array, STATIC_ARRAY_SIZE);
}
#endif


#ifdef DISPLAY_DYNAMIC_ARRAY
void dynamicArray(void) {

    printf("\n Dynamic Array\n");

    /*
    You use this when you are unsure about the size of the array.
    Let's assume, you ask the user how much data to be allocated, you'd be allocating that using Dynamic Memory Allocation.
    */

    int *dynamic_array = NULL;
    int dynamic_size;

    printf("\nHow many cells do you want to allocate?\n");
    if (scanf("%d", &dynamic_size) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return;
    }

    dynamic_array = (int*)calloc(dynamic_size, sizeof(int));
    if (dynamic_array == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < dynamic_size; i++) {
        dynamic_array[i] = rand() % 1000; // Random values between 0 and 999
    }

    printf("\nOutput of Dynamic Array: \n");
    printArray(dynamic_array, dynamic_size);

    free(dynamic_array);
}
#endif



#ifdef DISPLAY_2D_ARRAY
void twoDArray(void) {

    printf("\n 2-Dimensional Array\n");

    /*
    Implementation of a 2D array with 2 rows and 2 columns. 
    */
   int rows=2, columns=2; // Since 2D

   int array_2D[rows][columns];

   for(int i=0;i<rows;i++)
   {
    for(int j=0;j<columns;j++)
    {
        array_2D[i][j]=rand();
    }
   } 

   //Printing 2D Array 

   for(int i=0;i<rows;i++)
   {
    for(int j=0;j<columns;j++)
    {
        printf("%d", array_2D[i][j]);
        printf("\t");
    }
    printf("\n"); 
   } 

}
#endif



#ifdef DISPLAY_Multi_2D_ARRAY
void multi2DArray(void) {

    printf("\n Multi Dimensional Array\n");
    /*
    Just an Extension of 2D array but with some flexibility for Multi Dimensionality.
    */
   int rows, columns; // Take from user

    printf("\nEnter Number of Rows and Columns you want for the Array: ");
    scanf("%d%d", &rows, &columns);

   int array_multi2D[rows][columns];

   for(int i=0;i<rows;i++)
   {
    for(int j=0;j<columns;j++)
    {
        array_multi2D[i][j]=rand();
    }
   } 

   //Printing MultiDimensional Array 

   for(int i=0;i<rows;i++)
   {
    for(int j=0;j<columns;j++)
    {
        printf("%d", array_multi2D[i][j]);
        printf("\t");
    }
    printf("\n"); 
   } 
}
#endif

// Function to demonstrate a 3D array (or higher dimensions)
void threeDArray(void) {
    // Define the dimensions of the 3D array (rows, columns, and depth)
    int rows = 2, columns = 3, depth = 4;

   int array_3D[rows][columns][depth];

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            for (int k = 0; k < depth; k++) {
                array_3D[i][j][k] = rand() % 1000;
            }
        }
    }

    // Print the 3D array in a structured format
    printf("\nOutput of 3D Array (rows x columns x depth):\n");
    for (int i = 0; i < rows; i++) {
        printf("Layer %d:\n", i + 1);
        for (int j = 0; j < columns; j++) {
            for (int k = 0; k < depth; k++) {
                printf("%d\t", array_3D[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to demonstrate a 4D array 
void fourDArray(void) {
    
    int w = 2, x = 2, y = 3, z = 2;
    int array_4D[w][x][y][z];

    
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                for (int l = 0; l < z; l++) {
                    array_4D[i][j][k][l] = rand() % 1000; 
                }
            }
        }
    }

    // Print the 4D array in a structured format
    printf("\nOutput of 4D Array (w x x x y x z):\n");
    for (int i = 0; i < w; i++) {
        printf("Dimension %d:\n", i + 1);
        for (int j = 0; j < x; j++) {
            printf("Layer %d:\n", j + 1);
            for (int k = 0; k < y; k++) {
                for (int l = 0; l < z; l++) {
                    printf("%d\t", array_4D[i][j][k][l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(0));  // Seed the random number generator

#ifdef DISPLAY_STATIC_ARRAY
    staticArray();
#endif

#ifdef DISPLAY_DYNAMIC_ARRAY
    dynamicArray();
#endif

#ifdef DISPLAY_2D_ARRAY
    twoDArray();
#endif

#ifdef DISPLAY_Multi_2D_ARRAY
    multi2DArray();
#endif

#ifdef DISPLAY_3D_ARRAY
    threeDArray();
#endif

#ifdef DISPLAY_4D_ARRAY
    fourDArray();
#endif

    return 0;
}


