/*#include"matrix.hpp"
#include<vector>
#include<iostream>
using namespace std;


//template<typename T>

Matrix::Matrix(vector<vector<float>>& a){
	row = a.size();
	col = a[0].size();
	m1 = a;
}
	
vector<float>& Matrix::operator[](int i){
	return m1[i];	
};
void Matrix::print(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout<<m1[i][j]<<"\t";
	
		}
		cout<<endl;
	}
};

 
