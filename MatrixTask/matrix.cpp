#include<vector>
using namespace std;


//template<typename T>
class Matrix{
public:
vector<vector<float>> m1; int row; int col;
Matrix(vector<vector<float>>& a){
	row = a.size();
	col = a[0].size();
	vector<vector<float>> m1;
	m1 = a;
}
	
vector<float> operator[](int i){
	return m1[i];	
}
};
int main(){
	return 0;
}
