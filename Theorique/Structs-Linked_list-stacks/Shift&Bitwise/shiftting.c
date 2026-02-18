#include <stdio.h>

int	is_odd(int n)
{
	return (n & 1);
}

int	has_permission(int perms, int bit)
{
	return ((perms >> bit) & 1);
}

int	main()
{
	int x = 5;


	/*	
	!	  x << n  : Left shift, shift bits ti the left, adding 0 to the right => Mutliplies by 2^n

	?	  x >> n  : Right shift, shift bits to the right, adding 0 to the left => Divides by 2^n
	*/
	printf("%d\n", x);
	if (is_odd(x))
		printf("odd number\n");
	else
		printf("odd number\n");
	x = x << 2; // 00000101 => 00010100 => 10
	printf("%d\n", x);
	if (is_odd(x))
		printf("odd number\n");
	else
		printf("odd number\n");
	int perms = 5;
	printf("%d\n", has_permission(perms, 1));
	printf("%d\n", has_permission(perms, 2));
}