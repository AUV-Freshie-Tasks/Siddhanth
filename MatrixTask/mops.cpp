/*#include<vector>
#include"matrix.hpp"
using namespace std;
//template<typename T>
#ifndef MOPS_TPP_CPP
#define MOPS_TPP_CPP
template<typename T>
Matrix Matrix::operator+(Matrix b){
	if((row != b.row)||(col != b.col))
        	throw std::invalid_argument("Matrix size mismatch");
	
	vector<vector<T>> ct(row, vector<T>(col, 0)); 
    Matrix c(ct);
        
	for(int i = 0; i < row; i++){
        for(int j = 0; j < b.col; j++){
            c[i][j] = m1[i][j] + b[i][j];
        }
    }
    return c;
};

template<typename T>
Matrix Matrix::operator*(Matrix b){
	//if(a.col != b.row)
		//return;
	vector<vector<T>> v(row, vector<T>(b.col, 0));
	for(int i = 0; i < row; i++){
		for(int j = 0; j < b.col; j++){
			for(int k = 0; k < col; k++){
				v[i][j] += m1[i][k] + b[k][j];
			}

		}

	}

	return Matrix(v);
}

//template<typename T>
/*Matrix Matrix::operator*(float sc, Matrix(mat)){
    vector<vector<float>> result(mat.row, vector<float>(mat.col));
    for(int i = 0; i < mat.row; i++){
        for(int j = 0; j < mat.col; j++){
            result[i][j] = mat.m1[i][j] * sc;
        }
    }
    return Matrix(result);
};*/

//template<typename T>

void Matrix::swapRow(int r1, int r2){
	vector<float> temp = m1[r1-1];
	m1[r1-1] = m1[r2-1];
	m1[r2-1] = temp;
};
//template<typename T>
Matrix Matrix::swapCol(int c1, int c2){
	float temp;
	vector<vector<float>> mtv = m1;
	for(int i = 0; i < m1.size(); i++){
		temp = m1[i][c1-1];
		mtv[i][c1-1] = mtv[i][c2-1];
		mtv[i][c2-1] = temp;
	}
	return Matrix(mtv);	
};
//template<typename T>
void Matrix::Transpose(){
	for(int i = 0; i < row; i++){
		for(int j = i; j < col; j++){
			float temp;
			temp = m1[i][j];
			m1[i][j] = m1[j][i];
			m1[j][i] = temp;
		}
	}
};

Matrix Matrix::LUdecomp(Matrix a, Matrix b){//returns the solved X from AX = B
	int r = b.row;
	vector<vector<float>> xf(r, vector<float>(1, 0));
	Matrix x(xf);
	vector<vector<float>> Lv(r, vector<float>(r, 0));
	
	//starting row ech
	for(int i = 0; i < r; i++){
		Lv[i][i] = 1;
		for(int j = i+1; j < r; j++){
			float x = a[j][i]/a[i][i];
			Lv[j][i] = x;
			for(int sub = 0; sub < r; sub++){
				a[j][sub] -= x*a[i][sub];
			}
		}

	}
	vector<vector<float>> zv(r, vector<float>(1, 0));
	Matrix z(zv);
	z[r-1][0] = b[r-1][0];
	for(int i = 0; i<r; i++){
		float count = 0;
		for(int j = 0; j<i; j++){
			count+=Lv[i][j]*z[j][0];
		}
		z[i][0] = b[i][0] - count;
	}
	for(int i = r-1; i>=0;i--){
		float count = 0;
		for(int j=i+1;j<r;j++){
			count+=a[i][j]*x[j][0]
		}
		x[i][0] = (z[i][0] - count)/a[i][i];
	}
	return x;

}

Matrix Matrix::gradientDescent(Matrix X, Matrix Y, float alpha, int iters){
    int n = X.row;
	Matrix xt = X;
	xt.Transpose();
	Matrix y = Y;

    // θ = [c; m] initialized to 0
    vector<vector<float>> thetav = {{0.0},{0.0}};
	Matrix theta = Matrix(thetav);

    for (int iter = 0; iter < iters; iter++) {
        Matrix preds = X*theta;
        Matrix error = preds-y;
        Matrix gradient = (xt * error) * (1.0 / n);
        theta = theta - (gradient * alpha);
    }

    return theta;
}



#endif
/*int main()
{
return 0;
}*/
