#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class SymmetricMatrix{
public:
	SymmetricMatrix(T* a,size_t size)
		:_arry(new T[size*(size+1)/2])
		,_size(size*(size + 1) / 2)
		,_n(size){
		size_t index = 0;
		for (size_t i = 0; i < size; ++i){
			for (size_t j = 0; j < size; ++j){
				if (i >= j){
					_arry[index++] = a[i*size + j];
				}
				else{
					break;
				}
			}
		}
		//for (size_t i = 0; i < _size; ++i)
		//	cout << _arry[i] << " ";
	}
	~SymmetricMatrix(){
		if (_arry){
			delete[] _arry;
			_arry = NULL;
			_size = 0;
		}
	}
	void Print(){
		size_t index = 0;
		for (size_t i = 0; i < _n; ++i){
			for (size_t j = 0; j < _n; ++j){
				if (i < j){
					swap(i, j);
					cout << _arry[i*(i + 1) / 2 + j] << " "; //a[i][j]与_arry[k]的下标k的关系
					swap(i,j);
				}
				if (i >= j){
					cout << _arry[i*(i+1)/2+j] << " ";
				}
			}
			cout << endl;
		}
	}
protected:
	T* _arry;
	size_t _size;
	size_t _n;
};

template <class T>
struct Triple{
	T _value;
	size_t _row;
	size_t _col;
};

template <class T>
class SparseMatrix{
public:
	SparseMatrix()
		:_rowSize(0), _colSize(0), _invalue(0)
	{}
	SparseMatrix(T *a,size_t row,size_t col,const T& invalue)
		:_rowSize(row), _colSize(col), _invalue(invalue)
	{
		for (size_t i = 0; i < _rowSize; ++i){
			for (size_t j = 0; j < _colSize; ++j){
				if (a[i*_colSize + j] != _invalue){
					Triple<T> t;
					t._value = a[i*_colSize + j];
					t._row = i;
					t._col = j;
					_a.push_back(t);
				}
			}
		}
		//for (size_t i = 0; i < _a.size(); i++){
		//	cout << _a[i]._value << " ";
		//}
		//cout << endl;
	}
	~SparseMatrix(){
		if (!_a.empty()){
			_a.pop_back();
		}
		_rowSize = 0;
		_colSize = 0;
		_invalue = 0;
	}
	void Print(){
		size_t index = 0;
		for (size_t i = 0; i < _rowSize; ++i){
			for (size_t j = 0; j < _colSize; ++j){
				if ((index < _a.size()) &&
					(i == _a.operator[](index)._row) &&
					(j == _a.operator[](index)._col))
					cout << _a.operator[](index++)._value << " ";
				else
					cout << _invalue << " ";
			}
			cout << endl;
		}
	}
     void Transport(){
		SparseMatrix<T> tem;
		tem._a.resize(_a.size());
		tem._colSize = _rowSize;
		tem._rowSize = _colSize;
		tem._invalue = _invalue;

		size_t index = 0;
		for (size_t i = 0; i < _colSize;++i){            //按列扫描
			for (size_t j = 0; j < _a.size(); ++j){      //匹配三元组中的列，进行行列交换
				if (i == _a[j]._col){
					tem._a[index]._value = _a[j]._value;
					tem._a[index]._col = _a[j]._row;
					tem._a[index]._row = _a[j]._col;
					index++;
				}
			}
		}

		swap(_a,tem._a);
		swap(_rowSize, tem._rowSize);
		swap(_colSize, tem._colSize);
	}
	 /*SparseMatrix<T>*/ 
	 void FastTransport(){
		 int *RowCount = new int[_colSize];
		 int *RowStart = new int[_colSize];
		 memset(RowCount,0,sizeof(int) * _colSize);
		 memset(RowStart, 0, sizeof(int)* _colSize);

		 size_t index = 0;
		 for (size_t i = 0; i < _a.size()-1; ++i){               //确定每一行的有效值个数
			 RowCount[_a[index++]._col]++;
		 }
		 for (size_t i = 1; i < _a.size()-1; ++i){               //确定起始位置
			 RowStart[i] = RowStart[i - 1] + RowCount[i - 1];
		 }

		 vector<Triple<T>> tem;
		 tem.resize(_a.size());
		 index = 0;
		 for (size_t i = 0; i < _a.size(); ++i){               //访问转置前三元表
			 tem[RowStart[_a[i]._col]]._value = _a[i]._value;  //通过转置前三元表中的元素的
			 tem[RowStart[_a[i]._col]]._col = _a[i]._row;      //列号确定起始位置数组的下标；
			 tem[RowStart[_a[i]._col]]._row= _a[i]._col;       //通过这个下表去确定转置前三元组
			 RowStart[_a[i]._col]++;                           //的元素在转置后三元组中的位置；
			                                                   //填入之后，将起始位置++
		 }
		
		 swap(_a,tem);
		 int temp = _rowSize;
		 _rowSize = _colSize;
		 _colSize = temp;
	 }
protected:
	vector<Triple<T>> _a; //存储有效元素
	size_t _rowSize;      //稀疏矩阵行数
	size_t _colSize;	  //稀疏矩阵行数
	T _invalue;			  //无效值
};