#include"matrix.hpp"
int main(){
	vector<vector<int>> av = {{1,0},{0,1}};
	vector<vector<int>> bv = {{3,4},{8,7}};
	Matrix<int> a(av);
	Matrix<int> b(bv);
	Matrix<int> c = a*b;
    c.print();
    return 0;
};