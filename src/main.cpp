#include "./../include/matrix.h"
#define SIZE 3

int main(){

// Matrix should be sized properly before setting values.

	Matrix <int> M1(SIZE, SIZE);

	M1.set_matrix(0, 1, 2, 3, 4, 5, 6, 7, 8);
	M1.set_row(0, 10, 11, 12);
	M1.set_col(2, 13, 14, 15);

	M1.display_matrix();


	Matrix <int> M2(M1);

	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			M2.set_value(i, j, (i*SIZE+j));
		}
	}

	M2.display_matrix();


	M1 = M1 / 2;

	M1.display_matrix();

	M2 += 10;
	M2.display_matrix();


	Matrix <int> M3;
	M3.resize(SIZE, SIZE);

	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			M3.set_value(i, j, (i*SIZE+j));
		}
	}

	M3.set_row(0, 2, 8, 7);
	M3.display_matrix();

	std :: cout<<"The determinate of M3 matrix is: "<<M3.det()<<std::endl;

	Matrix <double> M4;
	M4 = M3.inv(M3);
	std :: cout<<"The inverse of M3 matrix is:"<<std::endl;
	M4.display_matrix();

	//Explicit typecasting
	Matrix <double> M5(M3);

	Matrix <double> M6;	
	M6 = M5 * M4;
	std :: cout<<"The M3 * inverse of M3 matrix is:"<<std::endl;	
	M6.display_matrix();


/////////////////////////////////////////////////////////////////////////////////
////////	COMPLEX NUMBERS
/////////////////////////////////////////////////////////////////////////////////

	std::cout<<std::endl<<"Complex number testing."<<std::endl;
	
	Matrix <std::complex<int>> M7;
	M7.resize(SIZE, SIZE);

	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			M7.set_value(i, j, std::complex<int>(i*SIZE+j, i*SIZE+j));
		}
	}

	M7.set_row(0, std::complex<int>(2, 2), std::complex<int>(8, 8), std::complex<int>(7, 7));
	M7.display_matrix();

	std :: cout<<"The determinate of M7 matrix is: "<<M7.det()<<std::endl;

	Matrix <std::complex<double>> M8;
	M8 = M7.inv(M7,1);
	
	std :: cout<<"The inverse of M7 matrix is:"<<std::endl;
	M8.display_matrix();

	//Explicit typecasting
	Matrix <std::complex<double>> M9(M7);

	Matrix <std::complex<double>> M10;	
	M10 = M9 * M8;
	std :: cout<<"The M7 * inverse of M7 matrix is:"<<std::endl;	
	M10.display_matrix();




	return 0;
}