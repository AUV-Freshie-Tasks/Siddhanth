#include "matrix.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<vector<float>> a = {{1, 2, 3}, {3, 4, 5}, {10, 11, 12}};
	vector<vector<float>> b = {{5, 6, 9}, {7, 8, 13}, {15, 16, 17}};
	vector<vector<float>> idv = {{1,0,0},{0,1,0},{0,0,1}};
	Matrix m1(a), m2(b);
	Matrix sum = m1 + m2;
	Matrix idm(idv);
	/*cout << "finished"<<endl;
    	sum.print()
	sum.Transpose();
	cout<<"Transpose"<<endl;
	sum.print();
	sum.swapRow(1,2);
	cout<<"Swapped rows 1 and 2"<<endl;
	sum.print();
	Matrix suminv = sum.gaussJordan();
	cout<<"Gauss Jordan"<<endl;
	suminv.print();*/
	idm.gaussJordan().print();
	return 0;

}
