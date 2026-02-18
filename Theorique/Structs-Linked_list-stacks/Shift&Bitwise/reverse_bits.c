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

unsigned char	reverse_bits(unsigned char octet)
{

    unsigned int i = 8; // Initialize a counter variable i to 8
    unsigned char c;
    while (i--)
    {
        c = (c << 1 | (octet & 1));
        octet = octet >> 1;
    }
    return (c);
}
#include <stdio.h>
// If you want to test the code:
int	main(void)
{
	unsigned char bit = 0;
	// by changing the number on the next line, you change
	// the bits that are sent to the reverse_bits function
	// 5 => 0000 0101, the result should be 1010 0000
	unsigned char res = reverse_bits((unsigned char)2);
	print_bits(res);
	// int i = 8;
	// while (i--)
	// {
	// 	bit = (res >> i & 1) + 48;
	// 	printf("%c", bit);
	// }
}