#include "Matrix.h"

void test1(){
	int a[][4] = {
		{ 0, 1, 3, 4 },
		{ 1, 0, 2, 5 },
		{ 3, 2, 0, 6 },
		{ 4, 5, 6, 0 }
		
	};
	//for (int i = 0; i < 4; ++i){
	//	for (int j = 0; j < 4; ++j){
	//		cout << a[i][j]<<" ";
	//	}
	//	cout << endl;
	//}
	SymmetricMatrix<int> sm((int*)a,4);
	sm.Print();
}

void test(){
	int a[][5] = {
		{ 1, 0, 2, 0, 3 },
		{ 0, 0, 0, 0, 0 },
		{ 4, 0, 5, 0, 6 },
		{ 0, 0, 0, 0, 0 }
	};
	SparseMatrix<int> sm((int*)a,4,5,0);
	sm.Print();
	cout << "-------------------" << endl;
	//sm.Transport();
	sm.FastTransport();
	sm.Print();
}
int main(){
	test();
	//vector<int> s;
	//s.push_back(2);
	//s.push_back(2);
	//s.push_back(2);
	//s.push_back(2);
	//s.operator[](1);
	getchar();
	return 0;
}