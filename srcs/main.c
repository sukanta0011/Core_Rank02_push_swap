#include "push_swap.h"

int	main(void)
{
	int a[6] = {5, -10, -4, 3, 1, '\0'};
	int	b[6];

	b[0] = '\0';
	swap_a(a);
	printf("%s\n", "-----------a-----------");
	for (int i = 0; a[i]; i++)
		printf("%d\n", a[i]);
	printf("%s\n", "-----------b-----------");
	for (int i = 0; b[i]; i++)
		printf("%d\n", b[i]);
}