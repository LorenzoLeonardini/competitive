#include <stdio.h>

void rotate(char *array, int size)
{
	for (int n = 0; n < size - 1; n++)
	{
		for(int m = n + 1; m < size; m++)
		{
			char temp = array[n + m * size];
			array[n + m * size] = array[m + n * size];
			array[m + n * size] = temp;
		}
	}

	for(int y = 0; y < size / 2; y++)
	{
		for(int x = 0; x < size; x++)
		{
			char temp = array[x + y * size];
			array[x + y * size] = array[x + (size - y - 1) * size];
			array[x + (size - y - 1) * size] = temp;
		}
	}
}

void printArray(char *array, int size)
{
	printf("-----------------------\n");
	for(int y = 0; y < size; y++)
	{
		for(int x = 0; x < size; x++)
			printf("%c ", array[x + y * size]);
		printf("\n");
	}
}

int contains(char *array1, int size1, char *array2, int size2)
{
	int times = 0;

	for(int x1 = 0; x1 < size1 - size2 + 1; x1++)
	{
		for(int y1 = 0; y1 < size1 - size2 + 1; y1++)
		{
			bool found = true;
			for(int x2 = x1; x2 < x1 + size2; x2++)
			{
				for(int y2 = y1; y2 < y1 + size2; y2++)
				{
					if(array1[x2 + y2 * size1] != array2[x2 - x1 + (y2 - y1) * size2])
						found = false;
				}
			}
			if(found) times++;
		}
	}
	return times;
}

int main(void)
{
	int s1, s2;
	while(true)
	{
		char b;
		scanf("%d %d", &s1, &s2);
		if(s1 == 0 && s2 == 0)
			break;

		char array1[s1 * s1];
		for(int i = 0; i < s1 * s1;)
		{
			scanf("%c", &b);
			if(b != '\n')
				array1[i++] = b;
		}

		char array2[s2 * s2];
		for(int i = 0; i < s2 * s2;)
		{
			scanf("%c", &b);
			if(b != '\n')
				array2[i++] = b;
		}

		int times[4];
		times[3] = contains(array1, s1, array2, s2);
		for(int i = 0; i < 3; i++)
		{
			rotate(array2, s2);
			times[i] = contains(array1, s1, array2, s2);
		}

		for(int i = 3; i >= 0; i--)
			printf(i > 0 ? "%d " : "%d", times[i]);

		printf("\n");
	}

	return 0;
}
