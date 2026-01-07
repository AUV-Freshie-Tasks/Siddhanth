#ifndef MATRIX_H
#define MATRIX_H

#include<vector>
#include<iostream>
#include<list>
using namespace std;

//template<typename T>
class Matrix{
public:
	vector<vector<float>> m1; int row; int col;
	Matrix(vector<vector<float>>& a);
	vector<float>& operator[](int i);
	void swapRow(int r1, int r2);
	Matrix swapCol(int c1, int c2);
	void Transpose();
	Matrix operator+(Matrix b);
	Matrix operator*(Matrix b);
	Matrix gaussJordan();
	void print();
	struct LUCacheNode;
	list<LUCacheNode> luCache;
	int cap;
	Matrix LUdecomp(Matrix a, Matrix b);
	Matrix gradientDescent(Matrix X, Matrix y, float alpha, int iters);
};
#endif
