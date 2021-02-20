#include <stdio.h>
#include <stdlib.h>

/**
*   Task 007
*/

#define MAX_VALUE 5

int main()
{
	int size, x, y, value = 1;
	printf("Please Enter The Size of The Square Array: ");
	scanf("%d",&size);
	fflush(stdin);
	while((size <= 0)||(size > MAX_VALUE))
	{
		system("cls");
		printf("Wrong Entery. Please Enter a Number Between 0 and %d: ",MAX_VALUE);
		scanf("%d",&size);
		fflush(stdin);
	}

	int arr[size][size];

	printf("Please Enter The Start Point x,y: \n");
	printf("NOTE: x & y values ranges from 0 to %d. Enter x value then space then enter y value\n", size-1);
	scanf("%d %d",&x,&y);
	fflush(stdin);
	while((x >= size) || (y >= size) || (x < 0) || (y < 0))
	{
		system("cls");
		printf("Wrong Entery. Please Enter a Number Between 0 and %d: ",size-1);
		scanf("%d %d",&x,&y);
		fflush(stdin);
	}

    system("cls");
	arr[x][y] = value;

	int i;
	for(i = 1; i < (size * size) ; i++)
	{
		if(value % size == 0)
		{
			y++;
			if(y == size)
				y = 0;
		}
		else
		{
			y--; x--;
			if(x < 0)
				x = size - 1;
			if(y < 0)
				y = size - 1;
		}
		arr[y][x] = ++value;
	}

	int j;
	for(i = 0; i < size; i++ ){
		for(j = 0; j < size; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

    return 0;
}
