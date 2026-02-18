// Define a struct
struct Car {
  char brand[30];
  int year;
};

// Function that takes a pointer to a Car struct and updates the year
void updateYear(struct Car *c) {
  c->year = 2025;  // Change the year
}

#include <stdio.h>

int main() {
  struct Car car = {"Toyota", 2020};

  // Declare a pointer to the struct
  struct Car *ptr = &car;

  // Access members using the -> operator
  printf("Brand: %s\n", ptr->brand);
  printf("Year: %d\n", ptr->year);

  updateYear(&car);  // Pass a pointer so the function can change the year
  
  printf("\n\n\nBrand: %s\n", car.brand);
  printf("Year: %d\n", car.year);

  /*
  !   Why Use Struct Pointers?
  ?      + You want to avoid copying large amounts of data.
  *           Instead of copying a whole struct, you can just pass a pointer.
  *           This makes your program faster and uses less memory.           
  ?      + You want to change values inside a function.
  *           If you pass a pointer to a struct into a function, 
  *           the function can change the original values.
  ?      + You want to create structs dynamically using memory allocation.
  *           With pointers, you can use malloc() to create structs
  *           while the program is running.
*/
  return 0;
}