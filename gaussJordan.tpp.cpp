#include"matrix.hpp"
#include<cmath>
#include<algorithm>
using namespace std;

Matrix Matrix::gaussJordan(){
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
		T mx = -10000000;
		int idx;
		for(int j = i; j < r; j++){
			T temp = std::max((T)mx, (T)mtr[j][i]);
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
			T x = mtr[sub][i]/mtr[i][i];
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
