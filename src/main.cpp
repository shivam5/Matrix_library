#include "./../include/matrix.h"
#define SIZE 3

int main(){

/////////////////////////////////////////////////////////////////////////////////
////////	MATRICES OF TYPE INTEGER
/////////////////////////////////////////////////////////////////////////////////

	std::cout<<std::endl<<"////////////////////////////////////////////////////////////////"<<std::endl;
	std::cout<<"MATRICES OF TYPE INTEGER"<<std::endl;
	std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;

	// Creating matrices.
	//////////////////////////////////////////////////////////////////////
	Matrix <int> M1;
	Matrix <int> M2(SIZE, SIZE);
	Matrix <int> M3(M2);

	std:: cout<<"After creating three integer matrices:"<<std::endl;
	std:: cout<<"M1:"<<std::endl;
	M1.display_matrix();
	std:: cout<<"M2:"<<std::endl;
	M2.display_matrix();
	std:: cout<<"M3:"<<std::endl;
	M3.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;

	// Resizing matrix
	//////////////////////////////////////////////////////////////////////
	M1.resize(SIZE, SIZE);

	std:: cout<<"After resizing, M1:"<<std::endl;
	M1.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Setting values
	//////////////////////////////////////////////////////////////////////
	M1.set_matrix(0, 1, 2, 3, 4, 5, 6, 7, 8);

	M2.set_row(0, 10, 11, 12);
	M2.set_row(1, 13, 14, 15);
	M2.set_row(2, 26, 47, 3);

	M3.set_col(0, 0, 3, 6);
	for (int i=0; i<SIZE; i++){
		for (int j=1; j<SIZE; j++){
			M3.set_value(i, j, (i*SIZE+j));
		}
	}

	std:: cout<<"After setting the three integer matrices:"<<std::endl;
	std:: cout<<"M1:"<<std::endl;
	M1.display_matrix();
	std:: cout<<"M2:"<<std::endl;
	M2.display_matrix();
	std:: cout<<"M3:"<<std::endl;
	M3.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Displaying Matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Different types of displays."<<std::endl;
	std:: cout<<"M1:"<<std::endl;
	M1.display_matrix();
	std:: cout<<"M2 0th row:"<<std::endl;
	M2.display_row(0);
	std:: cout<<"M2 1st column:"<<std::endl;
	M2.display_col(1);
	std:: cout<<"M3 1st column 1st row:"<<std::endl;
	std::cout<<M3.get_value(1,1)<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Row and column getter functions
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Row and column getter functions"<<std::endl;
	std:: cout<<"M1 row size = ";
	std::cout<<M1.get_row_size()<<std::endl;
	std:: cout<<"M1 column size = ";
	std::cout<<M1.get_col_size()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Matrix multiplication, addition and subtraction of 2 matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M2 = M1 + M2;
	M1 += M2;
	M2 = M2 - M3;
	M3 = M1 *M2;
	M2 *= M1;
	std:: cout<<"After performing operations on matrices:"<<std::endl;
	std:: cout<<"M1:"<<std::endl;
	M1.display_matrix();
	std:: cout<<"M2:"<<std::endl;
	M2.display_matrix();
	std:: cout<<"M3:"<<std::endl;
	M3.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;


	// Scalar multiplication, addition, subtraction and division
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M2 = M1 + 2;
	M2 += 3;
	M2 = M1 - 2;
	M2 -= 10;
	M2 = M1 * 4;
	M2 *= 3;
	M2 = M1 / 1;
	M2 /= 2;

	std:: cout<<"After performing scalar operations on matrices:"<<std::endl;
	std:: cout<<"M1:"<<std::endl;
	M1.display_matrix();
	std:: cout<<"M2:"<<std::endl;
	M2.display_matrix();
	std:: cout<<"M3:"<<std::endl;
	M3.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;



	// Determinant of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Determinant of matrices:"<<std::endl;

	std :: cout<<"The determinate of M1 matrix is: "<<M1.det()<<std::endl;
	std :: cout<<"The determinate of M2 matrix is: "<<M2.det()<<std::endl;
	std :: cout<<"The determinate of M3 matrix is: "<<M3.det()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Inverse of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Inverse of matrices:"<<std::endl;

	Matrix <double> M4;
	M4 = M3.inv(M2);
	std :: cout<<"The inverse of M2 matrix is:"<<std::endl;
	M4.display_matrix();

	//Explicit typecasting
	Matrix <double> M5(M2);

	M5 = M5 * M4;
	std :: cout<<"The M2 * inverse of M2 matrix is:"<<std::endl;	
	M5.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


/////////////////////////////////////////////////////////////////////////////////
////////	MATRICES OF TYPE LONG
/////////////////////////////////////////////////////////////////////////////////

	std::cout<<std::endl<<"////////////////////////////////////////////////////////////////"<<std::endl;
	std::cout<<"MATRICES OF TYPE LONG"<<std::endl;
	std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;

	// Creating matrices.
	//////////////////////////////////////////////////////////////////////
	Matrix <long> M6;
	Matrix <long> M7(SIZE, SIZE);
	Matrix <long> M8(M7);

	std:: cout<<"After creating three long matrices:"<<std::endl;
	std:: cout<<"M6:"<<std::endl;
	M6.display_matrix();
	std:: cout<<"M7:"<<std::endl;
	M7.display_matrix();
	std:: cout<<"M8:"<<std::endl;
	M8.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;

	// Resizing matrix
	//////////////////////////////////////////////////////////////////////
	M6.resize(SIZE, SIZE);

	std:: cout<<"After resizing, M6:"<<std::endl;
	M6.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Setting values
	//////////////////////////////////////////////////////////////////////
	M6.set_matrix(0, 1, 2, 3, 4, 5, 6, 7, 8);

	M7.set_row(0, 10, 12221, 12);
	M7.set_row(1, 13, 14, 154444);
	M7.set_row(2, 26, 47, 3);

	M8.set_col(0, 0, 3, 6);
	for (int i=0; i<SIZE; i++){
		for (int j=1; j<SIZE; j++){
			M8.set_value(i, j, (i*SIZE+j));
		}
	}

	std:: cout<<"After setting the three long matrices:"<<std::endl;
	std:: cout<<"M6:"<<std::endl;
	M6.display_matrix();
	std:: cout<<"M7:"<<std::endl;
	M7.display_matrix();
	std:: cout<<"M8:"<<std::endl;
	M8.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Displaying Matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Different types of displays."<<std::endl;
	std:: cout<<"M6:"<<std::endl;
	M6.display_matrix();
	std:: cout<<"M7 0th row:"<<std::endl;
	M7.display_row(0);
	std:: cout<<"M7 1st column:"<<std::endl;
	M7.display_col(1);
	std:: cout<<"M8 1st column 1st row:"<<std::endl;
	std::cout<<M8.get_value(1,1)<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Row and column getter functions
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Row and column getter functions"<<std::endl;
	std:: cout<<"M6 row size = ";
	std::cout<<M6.get_row_size()<<std::endl;
	std:: cout<<"M6 column size = ";
	std::cout<<M6.get_col_size()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Matrix multiplication, addition and subtraction of 2 matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M7 = M6 + M7;
	M6 += M7;
	M7 = M7 - M8;
	M8 = M6 *M7;
	M7 *= M6;
	std:: cout<<"After performing operations on matrices:"<<std::endl;
	std:: cout<<"M6:"<<std::endl;
	M6.display_matrix();
	std:: cout<<"M7:"<<std::endl;
	M7.display_matrix();
	std:: cout<<"M8:"<<std::endl;
	M8.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;


	// Scalar multiplication, addition, subtraction and division
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M7 = M6 + (long) 2;
	M7 += (long) 3;
	M7 = M6 - (long) 2;
	M7 -= (long) 10;
	M7 = M6 * (long) 4;
	M7 *= (long) 3;
	M7 = M6 / (long) 1;
	M7 /= (long) 2;

	std:: cout<<"After performing scalar operations on matrices:"<<std::endl;
	std:: cout<<"M6:"<<std::endl;
	M6.display_matrix();
	std:: cout<<"M7:"<<std::endl;
	M7.display_matrix();
	std:: cout<<"M8:"<<std::endl;
	M8.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;



	// Determinant of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Determinant of matrices:"<<std::endl;

	std :: cout<<"The determinate of M6 matrix is: "<<M6.det()<<std::endl;
	std :: cout<<"The determinate of M7 matrix is: "<<M7.det()<<std::endl;
	std :: cout<<"The determinate of M8 matrix is: "<<M8.det()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Inverse of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Inverse of matrices:"<<std::endl;

	Matrix <double> M9;
	M9 = M8.inv(M7);
	std :: cout<<"The inverse of M7 matrix is:"<<std::endl;
	M9.display_matrix();

	//Explicit typecasting
	Matrix <double> M10(M7);

	M10 = M10 * M9;
	std :: cout<<"The M7 * inverse of M7 matrix is:"<<std::endl;	
	M10.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


/////////////////////////////////////////////////////////////////////////////////
////////	MATRICES OF TYPE FLOAT
/////////////////////////////////////////////////////////////////////////////////

	std::cout<<std::endl<<"////////////////////////////////////////////////////////////////"<<std::endl;
	std::cout<<"MATRICES OF TYPE FLOAT"<<std::endl;
	std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;

	// Creating matrices.
	//////////////////////////////////////////////////////////////////////
	Matrix <float> M11;
	Matrix <float> M12(SIZE, SIZE);
	Matrix <float> M13(M12);

	std:: cout<<"After creating three float matrices:"<<std::endl;
	std:: cout<<"M11:"<<std::endl;
	M11.display_matrix();
	std:: cout<<"M12:"<<std::endl;
	M12.display_matrix();
	std:: cout<<"M13:"<<std::endl;
	M13.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;

	// Resizing matrix
	//////////////////////////////////////////////////////////////////////
	M11.resize(SIZE, SIZE);

	std:: cout<<"After resizing, M11:"<<std::endl;
	M11.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Setting values
	//////////////////////////////////////////////////////////////////////
	M11.set_matrix(0.6, 1.123, 2.74, 3.2, 4.96, 5.2, 6.4, 7.1, 8.34);

	M12.set_row(0, 10.0, 1.2221, 12.01);
	M12.set_row(1, 13, 14, 15.444);
	M12.set_row(2, 26, 47.654, 3);

	M13.set_col(0, 0.1, 3.75, 6.2);
	for (int i=0; i<SIZE; i++){
		for (int j=1; j<SIZE; j++){
			M13.set_value(i, j, (i*SIZE+j));
		}
	}

	std:: cout<<"After setting the three float matrices:"<<std::endl;
	std:: cout<<"M11:"<<std::endl;
	M11.display_matrix();
	std:: cout<<"M12:"<<std::endl;
	M12.display_matrix();
	std:: cout<<"M13:"<<std::endl;
	M13.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Displaying Matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Different types of displays."<<std::endl;
	std:: cout<<"M11:"<<std::endl;
	M11.display_matrix();
	std:: cout<<"M12 0th row:"<<std::endl;
	M12.display_row(0);
	std:: cout<<"M12 1st column:"<<std::endl;
	M12.display_col(1);
	std:: cout<<"M13 1st column 1st row:"<<std::endl;
	std::cout<<M13.get_value(1,1)<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Row and column getter functions
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Row and column getter functions"<<std::endl;
	std:: cout<<"M11 row size = ";
	std::cout<<M11.get_row_size()<<std::endl;
	std:: cout<<"M11 column size = ";
	std::cout<<M11.get_col_size()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Matrix multiplication, addition and subtraction of 2 matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M12 = M11 + M12;
	M11 += M12;
	M12 = M12 - M13;
	M13 = M11 *M12;
	M12 *= M11;
	std:: cout<<"After performing operations on matrices:"<<std::endl;
	std:: cout<<"M11:"<<std::endl;
	M11.display_matrix();
	std:: cout<<"M12:"<<std::endl;
	M12.display_matrix();
	std:: cout<<"M13:"<<std::endl;
	M13.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;


	// Scalar multiplication, addition, subtraction and division
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M12 = M11 + (float) 2.4;
	M12 += (float) 3.8;
	M12 = M11 - (float) 2.12;
	M12 -= (float) 10.5;
	M12 = M11 * (float) 4.2;
	M12 *= (float) 3.87;
	M12 = M11 / (float) 1.1;
	M12 /= (float) 2.0;

	std:: cout<<"After performing scalar operations on matrices:"<<std::endl;
	std:: cout<<"M11:"<<std::endl;
	M11.display_matrix();
	std:: cout<<"M12:"<<std::endl;
	M12.display_matrix();
	std:: cout<<"M13:"<<std::endl;
	M13.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;



	// Determinant of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Determinant of matrices:"<<std::endl;

	std :: cout<<"The determinate of M11 matrix is: "<<M11.det()<<std::endl;
	std :: cout<<"The determinate of M12 matrix is: "<<M12.det()<<std::endl;
	std :: cout<<"The determinate of M13 matrix is: "<<M13.det()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Inverse of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Inverse of matrices:"<<std::endl;

	Matrix <double> M14;
	M14 = M13.inv(M12);
	std :: cout<<"The inverse of M12 matrix is:"<<std::endl;
	M14.display_matrix();

	//Explicit typecasting
	Matrix <double> M15(M12);

	M15 = M15 * M14;
	std :: cout<<"The M12 * inverse of M12 matrix is:"<<std::endl;	
	M15.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


/////////////////////////////////////////////////////////////////////////////////
////////	MATRICES OF TYPE DOUBLE
/////////////////////////////////////////////////////////////////////////////////

	std::cout<<std::endl<<"////////////////////////////////////////////////////////////////"<<std::endl;
	std::cout<<"MATRICES OF TYPE DOUBLE"<<std::endl;
	std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;

	// Creating matrices.
	//////////////////////////////////////////////////////////////////////
	Matrix <double> M16;
	Matrix <double> M17(SIZE, SIZE);
	Matrix <double> M18(M17);

	std:: cout<<"After creating three double matrices:"<<std::endl;
	std:: cout<<"M16:"<<std::endl;
	M16.display_matrix();
	std:: cout<<"M17:"<<std::endl;
	M17.display_matrix();
	std:: cout<<"M18:"<<std::endl;
	M18.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;

	// Resizing matrix
	//////////////////////////////////////////////////////////////////////
	M16.resize(SIZE, SIZE);

	std:: cout<<"After resizing, M16:"<<std::endl;
	M16.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Setting values
	//////////////////////////////////////////////////////////////////////
	M16.set_matrix(0.6, 1.123, 2.74, 3.2, 4.96, 5.2, 6.4, 7.1, 8.34);

	M17.set_row(0, 10.0, 1.2221, 12.01);
	M17.set_row(1, 13, 14, 15.444);
	M17.set_row(2, 26, 47.654, 3);

	M18.set_col(0, 0.1, 3.75, 6.2);
	for (int i=0; i<SIZE; i++){
		for (int j=1; j<SIZE; j++){
			M18.set_value(i, j, (i*SIZE+j));
		}
	}

	std:: cout<<"After setting the three double matrices:"<<std::endl;
	std:: cout<<"M16:"<<std::endl;
	M16.display_matrix();
	std:: cout<<"M17:"<<std::endl;
	M17.display_matrix();
	std:: cout<<"M18:"<<std::endl;
	M18.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Displaying Matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Different types of displays."<<std::endl;
	std:: cout<<"M16:"<<std::endl;
	M16.display_matrix();
	std:: cout<<"M17 0th row:"<<std::endl;
	M17.display_row(0);
	std:: cout<<"M17 1st column:"<<std::endl;
	M17.display_col(1);
	std:: cout<<"M18 1st column 1st row:"<<std::endl;
	std::cout<<M18.get_value(1,1)<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Row and column getter functions
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Row and column getter functions"<<std::endl;
	std:: cout<<"M16 row size = ";
	std::cout<<M16.get_row_size()<<std::endl;
	std:: cout<<"M16 column size = ";
	std::cout<<M16.get_col_size()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Matrix multiplication, addition and subtraction of 2 matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M17 = M16 + M17;
	M16 += M17;
	M17 = M17 - M18;
	M18 = M16 *M17;
	M17 *= M16;
	std:: cout<<"After performing operations on matrices:"<<std::endl;
	std:: cout<<"M16:"<<std::endl;
	M16.display_matrix();
	std:: cout<<"M17:"<<std::endl;
	M17.display_matrix();
	std:: cout<<"M18:"<<std::endl;
	M18.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;


	// Scalar multiplication, addition, subtraction and division
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M17 = M16 + 2.4;
	M17 += 3.8;
	M17 = M16 - 2.12;
	M17 -= 10.5;
	M17 = M16 * 4.2;
	M17 *= 3.87;
	M17 = M16 / 1.1;
	M17 /= 2.0;

	std:: cout<<"After performing scalar operations on matrices:"<<std::endl;
	std:: cout<<"M16:"<<std::endl;
	M16.display_matrix();
	std:: cout<<"M17:"<<std::endl;
	M17.display_matrix();
	std:: cout<<"M18:"<<std::endl;
	M18.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;



	// Determinant of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Determinant of matrices:"<<std::endl;

	std :: cout<<"The determinate of M16 matrix is: "<<M16.det()<<std::endl;
	std :: cout<<"The determinate of M17 matrix is: "<<M17.det()<<std::endl;
	std :: cout<<"The determinate of M18 matrix is: "<<M18.det()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Inverse of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Inverse of matrices:"<<std::endl;

	Matrix <double> M19;
	M19 = M18.inv(M17);
	std :: cout<<"The inverse of M17 matrix is:"<<std::endl;
	M19.display_matrix();

	//Explicit typecasting
	Matrix <double> M20(M17);

	M20 = M20 * M19;
	std :: cout<<"The M17 * inverse of M17 matrix is:"<<std::endl;	
	M20.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


/////////////////////////////////////////////////////////////////////////////////
////////	MATRICES OF TYPE COMPLEX
/////////////////////////////////////////////////////////////////////////////////

	std::cout<<std::endl<<"////////////////////////////////////////////////////////////////"<<std::endl;
	std::cout<<"MATRICES OF TYPE COMPLEX"<<std::endl;
	std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;

	// Creating matrices.
	//////////////////////////////////////////////////////////////////////
	Matrix <std::complex<int>> M21;
	Matrix <std::complex<int>> M22(SIZE, SIZE);
	Matrix <std::complex<int>> M23(M2);

	std:: cout<<"After creating three complex matrices:"<<std::endl;
	std:: cout<<"M21:"<<std::endl;
	M21.display_matrix();
	std:: cout<<"M22:"<<std::endl;
	M22.display_matrix();
	std:: cout<<"M23:"<<std::endl;
	M23.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;

	// Resizing matrix
	//////////////////////////////////////////////////////////////////////
	M21.resize(SIZE, SIZE);

	std:: cout<<"After resizing, M21:"<<std::endl;
	M21.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Setting values
	//////////////////////////////////////////////////////////////////////
	M21.set_matrix(std::complex<int>(2, 5), std::complex<int>(1, 7), 
		std::complex<int>(9, 2), std::complex<int>(6, 1), std::complex<int>(8, 3), 
		std::complex<int>(6, 1), std::complex<int>(0, 7), std::complex<int>(5, 6),
		std::complex<int>(3, 6));

	M22.set_row(0, std::complex<int>(10, 4), std::complex<int>(1, 42), std::complex<int>(67, 17));
	M22.set_row(1, std::complex<int>(17, 41), std::complex<int>(31, 4), std::complex<int>(6, 127));
	M22.set_row(2, std::complex<int>(2, 7), std::complex<int>(11, 6), std::complex<int>(2, 7));

	M23.set_col(0, std::complex<int>(21, 77), std::complex<int>(3, 2), std::complex<int>(23, 8));
	for (int i=0; i<SIZE; i++){
		for (int j=1; j<SIZE; j++){
			M23.set_value(i, j, std::complex<int>(i*SIZE+j, i*j));
		}
	}

	std:: cout<<"After setting the three double matrices:"<<std::endl;
	std:: cout<<"M21:"<<std::endl;
	M21.display_matrix();
	std:: cout<<"M22:"<<std::endl;
	M22.display_matrix();
	std:: cout<<"M23:"<<std::endl;
	M23.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	// Displaying Matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Different types of displays."<<std::endl;
	std:: cout<<"M21:"<<std::endl;
	M21.display_matrix();
	std:: cout<<"M22 0th row:"<<std::endl;
	M22.display_row(0);
	std:: cout<<"M22 1st column:"<<std::endl;
	M22.display_col(1);
	std:: cout<<"M23 1st column 1st row:"<<std::endl;
	std::cout<<M23.get_value(1,1)<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Row and column getter functions
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Row and column getter functions"<<std::endl;
	std:: cout<<"M21 row size = ";
	std::cout<<M21.get_row_size()<<std::endl;
	std:: cout<<"M21 column size = ";
	std::cout<<M21.get_col_size()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Matrix multiplication, addition and subtraction of 2 matrices
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M22 = M21 + M22;
	M21 += M22;
	M22 = M22 - M23;
	M23 = M21 *M22;
	M22 *= M21;
	std:: cout<<"After performing operations on matrices:"<<std::endl;
	std:: cout<<"M21:"<<std::endl;
	M21.display_matrix();
	std:: cout<<"M22:"<<std::endl;
	M22.display_matrix();
	std:: cout<<"M23:"<<std::endl;
	M23.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;


	// Scalar multiplication, addition, subtraction and division
	//////////////////////////////////////////////////////////////////////

	std:: cout<<"Matrix multiplication, addition and subtraction of 2 matrices"<<std::endl;
	M22 = M21 + std::complex<int>(2, 4);
	M22 += std::complex<int>(3, 8);
	M22 = M21 - std::complex<int>(2, 12);
	M22 -= std::complex<int>(10, -5);
	M22 = M21 * std::complex<int>(4, -2);
	M22 *= std::complex<int>(-3, 87);
	M22 = M21 / std::complex<int>(1, -4);
	M22 /= std::complex<int>(2, 0);

	std:: cout<<"After performing scalar operations on matrices:"<<std::endl;
	std:: cout<<"M21:"<<std::endl;
	M21.display_matrix();
	std:: cout<<"M22:"<<std::endl;
	M22.display_matrix();
	std:: cout<<"M23:"<<std::endl;
	M23.display_matrix();	
	std::cout<<"*******************************************************************"<<std::endl;



	// Determinant of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Determinant of matrices:"<<std::endl;

	std :: cout<<"The determinate of M21 matrix is: "<<M21.det()<<std::endl;
	std :: cout<<"The determinate of M22 matrix is: "<<M22.det()<<std::endl;
	std :: cout<<"The determinate of M23 matrix is: "<<M23.det()<<std::endl;
	std::cout<<"*******************************************************************"<<std::endl;


	// Inverse of matrices
	//////////////////////////////////////////////////////////////////////
	std:: cout<<"Inverse of matrices:"<<std::endl;

	Matrix <std::complex<double>> M24;
	M24 = M23.inv(M22, 1);
	std :: cout<<"The inverse of M22 matrix is:"<<std::endl;
	M24.display_matrix();

	//Explicit typecasting
	Matrix <std::complex<double>> M25(M22);

	M25 = M25 * M24;
	std :: cout<<"The M22 * inverse of M22 matrix is:"<<std::endl;	
	M25.display_matrix();
	std::cout<<"*******************************************************************"<<std::endl;


	return 0;
}