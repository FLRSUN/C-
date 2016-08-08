#include "Maze.h"

void TestMaze()
{
	int a[10][10] = {};
	GetMazeMap((int*)a, 10, 10);
	PrintMaze((int*)a, 10, 10);

	Pos entry = { 2, 0 };
	GetMazePath((int*)a, 10, 10, entry);
	PrintMaze((int*)a, 10, 10);
}


template <typename T>
T** malloc_Array2D(int row, int col)
{
	int size = sizeof(T);
	int point_size = sizeof(T*);
	//先申请内存，其中point_size * row表示存放row个行指针  
	T **arr = (T **)malloc(point_size * row + size * row * col);
	if (arr != NULL)
	{
		memset(arr, 0, point_size * row + size * row * col);
		T *head = (T*)((int)arr + point_size * row);
		while (row--)
			arr[row] = (T*)((int)head + row * col * size);
	}
	return (T**)arr;
}

void free_Aarray2D(void **arr)
{
	if (arr != NULL)
		free(arr);
}

void test(){
	
	int **a = malloc_Array2D<int>(2, 2);
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			a[i][j] = i * 2 + j +1;
		}
	}
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			cout<<a[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	free_Aarray2D((void**)a);
}

int main()
{
	test();
	//TestMaze();
	getchar();
	return 0;
}