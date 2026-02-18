#include <unistd.h>

void	print_bits(unsigned char octet)
{

    int i = 8; // Initialize a counter variable i to 8
    char c;
    while (i--)
    {
        c = '0' + ((octet >> i) & 1);
        write(1, &c, 1);
    }
}
/*
!   Condition       First value inside body     Last value inside body      Iterations

?   while(i--)                  7                          0                    8
*   while(--i)                  7                          1                    7
    while(i) + i-- inside       8                          1                    8

*/
int main()
{
    int i = 5;
    print_bits((unsigned char)i);
}