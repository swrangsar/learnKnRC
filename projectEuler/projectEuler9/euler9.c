#include <stdio.h>

#define LIMIT 1000

int main()
{
	int i, j, k, found;
	i = j = k = found = 0;
	
	while (++i < LIMIT) {
		j = i;
		while (++j < LIMIT) {
			k = j;
			while (++k < LIMIT) {
				if (i+j+k == LIMIT) {
					if ((i*i + j*j) == (k*k))
						found = 1;
					break;
				} else if (i+j+k > LIMIT) {
					break;
				}
			}
			if (found)
				break;
		}
		if (found)
			break;
	}
	
	if (found) {
		printf("Triplet is: (%d, %d, %d)\n", i, j, k);
		printf("Product abc is: %d\n", i*j*k);
	} else {
		printf("Could not find triplet!\n");
	}

	return 0;
}