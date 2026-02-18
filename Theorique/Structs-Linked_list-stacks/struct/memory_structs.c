/*
    !   Structures and Dynamic Memory
    ?   This is useful when you don't know how many structs you'll need in advance, 
    ?    or want to save memory by only allocating what's necessary (e.g., in a car
    ?   dealership program where the number of cars is not fixed).
*/

//! Allocating Memory for a Struct

#include <stdio.h>
#include <stdlib.h>

char    *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

typedef struct Car {
    char brand[50];
    int year;
} Car;

/*

//* Allocate memory for one Car struct
int main()
{
   
    Car *ptr = malloc(sizeof(Car));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; //* Exit the programm with an error code
    } 

    //? Set values
    //! we use -> instead of .(dot) to derefrence struct values
    ft_strcpy(ptr->brand, "Honda");
    ptr->year = 2022;

    //? Print values
    printf("Brand: %s\n", ptr->brand);
    printf("Year: %d\n", ptr->year);
    
    //* Free memory
    free(ptr);
}
!    Example Explained
?        + malloc() allocates memory for one struct
?        + strcpy() is used to copy a string into the brand field
?        + We use -> to access members through the pointer
?        + free() is used at the end to release the memory
TODO:       
        Note: malloc() allocates uninitialized memory.The content will be undefined until you assign values. 
TODO:   If you want memory initialized to zero, you can use calloc().
*/

//!     Using Arrays of Structs

int main()
{
    Car *cars = malloc(3 * sizeof(Car));
    if (!cars)
    {
        printf("Memory allocation failed.\n");
        return (1);
    }

    //? Fill data
    
    ft_strcpy(cars[0].brand, "Ford");
    cars[0].year = 2015;
    
    ft_strcpy(cars[1].brand, "BMW");
    cars[1].year = 2018;
    
    ft_strcpy(cars[2].brand, "Volvo");
    cars[2].year = 2023;

    
    int i = 0;
    /*
    while (i < 3)
    {
        printf("Brand: %s, Year: %d\n",cars[i].brand, cars[i].year);
        i++;
    }
    free(cars);
    */
    
    //! Growing Arrays Later with realloc()

    int count = 4;  //* New size
    Car *tmp = realloc(cars, count * sizeof(Car));
    if (tmp == NULL)
    {
        // 'cars' is still valid here; free it to avoid a leak
        free(cars);
        printf("Reallocation failed.\n");
        return 1;
    }

    cars = tmp;     //  ! use the reallocated block

    //*     Initialize the new element at index 3
    ft_strcpy(cars[3].brand, "Kia");
    cars[3].year = 2022;

    while (i < count)
    {
        printf("\nBrand: %s\nYear: %d\n   ----------------    \n",cars[i].brand, cars[i].year);
        i++;
    }
    free(cars);
}