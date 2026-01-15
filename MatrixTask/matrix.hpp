#include<vector>
#include<iostream>
#include<list>
using namespace std;

template<typename T>
class Matrix{
public:
	vector<vector<T>> m1; int row; int col;
	
	//template<typename T>
	
	Matrix(vector<vector<T>> a){
	row = a.size();
	col = a[0].size();
	m1 = a;
	}
	
	//template<typename T>
	vector<T>& operator[](int i){
		return m1[i];	
	};
	const vector<T>& operator[](int i) const {
		return m1[i];	
	};
	
	void print(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout<<m1[i][j]<<"\t";
	
		}
		cout<<endl;
	}
	};
	
	//template<typename T>	
	void swapRow(int r1, int r2){
	vector<T> temp = m1[r1-1];
	m1[r1-1] = m1[r2-1];
	m1[r2-1] = temp;
	};
	
	//template<typename T>
	Matrix multInt(float a, Matrix b){
		int r = b.row;
		vector<vector<float>> idv(r, vector<T>(r, 0)); //making identity matrix for the augment thing
		
		for(int i = 0; i<r; i++){
			for(int j=0; j<r; j++){
				if(i==j) idv[i][j] = a;
			}
		}
		Matrix idm(idv);
		return idm*b;
	}
	
	//template<typename T>
	Matrix swapCol(int c1, int c2){

		T temp;
		vector<vector<T>> mtv = m1;
		for(int i = 0; i < m1.size(); i++){
			temp = m1[i][c1-1];
			mtv[i][c1-1] = mtv[i][c2-1];
			mtv[i][c2-1] = temp;
		}
		return Matrix(mtv);	
	};
	
	//template<typename T>
	void Transpose(){
		for(int i = 0; i < row; i++){
			for(int j = i; j < col; j++){
				T temp;
				temp = m1[i][j];
				m1[i][j] = m1[j][i];
				m1[j][i] = temp;
			}
		}
	};

	//template<typename T>
	Matrix operator+(const Matrix &b) const {
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

	//template<typename T>	
	Matrix operator*(const Matrix &b)const {
		//if(a.col != b.row)
			//return;
		vector<vector<T>> v(row, vector<T>(b.col, 0));
		for(int i = 0; i < row; i++){
			for(int j = 0; j < b.col; j++){
				for(int k = 0; k < col; k++){
					v[i][j] += m1[i][k]*b[k][j];
				}

			}

		}

		return Matrix(v);
	}
	
	//template<typename T>
	Matrix gaussJordan(){
		int r = row;
		Matrix mtr(m1);

		vector<vector<T>> idv(r, vector<T>(r, 0)); //making identity matrix for the augment thing
		for(int i = 0; i<r; i++){
			for(int j=0; j<r; j++){
				if(i==j) idv[i][j] = 1.0;
			}
		}
		Matrix idm(idv);





		for(int i = 0; i < r; i++){
			float mx = -10000000;
			int idx;
			for(int j = i; j < r; j++){
				float temp = std::max((float)mx, (float)mtr[j][i]);
				mx = temp;
				if(mtr[j][i] == mx)
					idx = j;
				
			}	
			if(mx != 0){
				mtr.swapRow(i+1, idx+1);
				idm.swapRow(i+1, idx+1);
				//cout<<"Current Mtr::rowSwap"<<endl;mtr.print();
			}
			else
				break;
			for(int div=0; div<r; div++){
				mtr[i][div] /= mx; idm[i][div] /= mx;
				//cout<<"Current Mtr::division"<<endl;mtr.print();
				}
			for(int sub = 0; sub<r; sub++){
				if(sub != i){
				float x = mtr[sub][i]/mtr[i][i];
					for(int k = 0; k < r; k++){
						mtr[sub][k] -= x*mtr[i][k];
						idm[sub][k] -= x*idm[i][k];
						//cout<<"Current Mtr::subtraction"<<endl;mtr.print();
					}
				}
			}
			
		}
		return Matrix(idm);
		



		/*int main(){
	i		return 0;
		}*/
	}

	//template<typename T>
	Matrix LUdecomp(Matrix a, Matrix b){//returns the solved X from AX = B
		int r = b.row;
		vector<vector<T>> xf(r, vector<T>(1, 0));
		Matrix x(xf);
		vector<vector<T>> Lv(r, vector<T>(r, 0));
		
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
		vector<vector<T>> zv(r, vector<T>(1, 0));
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
				count+=a[i][j]*x[j][0];
			}
			x[i][0] = (z[i][0] - count)/a[i][i];
		}
		return x;
}
	//template<typename T>

	Matrix gradientDescent(Matrix X, Matrix Y, float alpha, int iters){
   		int n = X.row;
		Matrix xt = X;
		xt.Transpose();
		Matrix y = Y;

    		// theta = [c; m] initialized to 0
   		vector<vector<float>> thetav = {{0.0},{0.0}};
		Matrix theta = Matrix(thetav);

    		for (int iter = 0; iter < iters; iter++) {
        		Matrix preds = X*theta;
        		Matrix error = preds + multInt(-1,y);
        		Matrix gradient = multInt(1.0/n, xt*error);
        		theta = theta + multInt(-1, multInt(alpha, gradient));
    		}

    		return theta;
}
};
//template<typename T>
