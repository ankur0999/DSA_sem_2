#include<iostream>
#include<math.h>
#define MAX_size 25
using namespace std;

class matrix{
	private:
		int arr[MAX_size];
		int row; 
		int col;
	public:
		matrix(int size){
		        int arr[size];
			row = sqrt(size);
			col = sqrt(size);
			//cout<<row<<col<<endl;
		}
		void data_entry(){
			cout<< "Enter element of matrix"<<endl;
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					//cout <<"M["<<i+1<<"]["<<j+1<<"] ";
					scanf("%d ",&arr[i*col +j]);
				}
			//cout<<endl;
			}
		}
		void show_data(){
			cout<< "the elements of matrix are "<<endl;
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++)
					printf("%d\t",arr[i*row + j]);
			cout<<endl;
			}}
		matrix operator +(matrix M){
                        matrix temp(row*col);
			for(int i=0; i<row; i++)
				for(int j=0; j<col; j++)
					temp.arr[i*col+j] = this->arr[i*col+j]+M.arr[i*col+j];
			return temp;
		}
		matrix operator -(matrix M){
			matrix temp(row*col);
			for(int i=0; i<row; i++)
				for(int j=0; j<col; j++)
					temp.arr[i*col+j] = this->arr[i*col+j] - M.arr[i*col+j];
			return temp;
		}
		matrix operator *(matrix M){
			matrix temp(row*col);
		        for(int i=0; i<row; i++)
				for(int j=0; j<col; j++)
					for(int k=0; k<row; k++)
					     temp.arr[i*col+j] += this->arr[i*col + k]*M.arr[j + col*k];
			return temp;
		}
};

int main(){
	matrix M(9),N(9);
	M.data_entry();
	getchar();
	M.show_data();
	N.data_entry();
	getchar();
	N.show_data();
	//M = M + N;
	//M.show_data();
	M = M*N;
	M.show_data();
}

