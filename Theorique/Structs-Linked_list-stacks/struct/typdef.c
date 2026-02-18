

#include <stdio.h>

typedef float Tempearture;

// Without typedef:
struct Car {
  char brand[30];
  int year;
};

// With typedef:
typedef struct {
  char brand[30];
  int year;
} Car;


struct Example {
  char a; // 1 byte
  int b;  // 4 bytes
  char c; // 1 byte
};


int main()
{
    //! The typedef keyword lets you create a new name (an alias) for an existing type. 
    //! This can make complex declarations easier to read, and your code easier to maintain.

    Tempearture today = 11.7;
    Tempearture tomorrow = 9.3;
    printf("Today temperature: %.1f\n",today);
    printf("Tomorrow temperature: %.1f\n",tomorrow);

    /*
    TODO: Why Use typedef?
    ?      + Simplifies code: Shorter, easier-to-read type names.
    ?      + Improves clarity: Expresses intent better (for example, AGE instead of just int).
    ?      + Also helps avoid confusion when many variables share the same base type (like float or double).

    * Good To Know:  In modern C, typedef is often used together with struct, enum, 
    *                and function pointers to keep code clean and easier to read.
    */

    struct Car car1 = {"BMW", 1999}; // needs "struct"
    Car car2 = {"Ford", 1969}; // shorter with typedef
    
    printf("%s %d\n", car1.brand, car1.year);
    printf("%s %d\n", car2.brand, car2.year);
    
    /*
        When you create a struct in C, the compiler may add some extra bytes of padding between members.

        This is done to make the program run faster on your computer, because most CPUs read data more efficiently when it's properly aligned in memory.

        You rarely need to worry about this unless you work with low-level memory or file formats.

        You might expect the size to be 1 + 4 + 1 = 6 bytes - but it will usually print 12 bytes!
    
        Why?
        The compiler adds padding bytes so that the int member (b) starts at a memory address that's a multiple of 4. This helps the CPU read it faster.
    
        Padding depends on the order of members in the struct. If you group larger types first, you can make the struct smaller:

        Why It Matters
        Padding helps programs run faster by keeping data aligned in memory.
        It can make structs bigger than expected.
        Reordering members can reduce the total size.
        Note: You rarely need to worry about this unless you work with low-level memory or file formats.

    */
    printf("Size of struct: %zu bytes\n", sizeof(struct Example));
    return 0;
}