#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test

#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "../include/matrix.h"
#include <typeinfo>
#include <string>
#include <limits.h>
#include <cmath>

#define SIZE 3


BOOST_AUTO_TEST_SUITE(Basic_Operations)
 
BOOST_AUTO_TEST_CASE(Constructors)
{
	Matrix <int> M1;
	Matrix <double> M2(SIZE, SIZE);
	Matrix <std::complex<double>> M3(M2);

	BOOST_CHECK( (M1.get_row_size() == 0) && (M1.get_col_size() == 0) );
	BOOST_CHECK( (M2.get_row_size() == SIZE) && (M2.get_col_size() == SIZE) );
	BOOST_CHECK( (M3.get_row_size() == SIZE) && (M3.get_col_size() == SIZE) );

	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			BOOST_CHECK( M2.get_value(i,j) == M3.get_value(i,j) );
		}
	}
}


BOOST_AUTO_TEST_CASE(Resizing)
{
	Matrix <int> M1;
	M1.resize(SIZE, SIZE);
	BOOST_CHECK( (M1.get_row_size() == SIZE) && (M1.get_col_size() == SIZE) );

	Matrix <std::complex<double>> M2;
	M2.resize(SIZE, SIZE);
	BOOST_CHECK( (M2.get_row_size() == SIZE) && (M2.get_col_size() == SIZE) );

}


BOOST_AUTO_TEST_CASE(Setting_Values)
{

	Matrix <int> M1(SIZE, SIZE);
	Matrix <float> M2(SIZE, SIZE);
	Matrix <std::complex<int>> M3(M2);

	BOOST_CHECK ( M1.set_matrix(0, 1, 2, 3, 4, 5, 6, 7, 8) == true );

	M2.set_row(0, 10.22, 11, 12.0);
	M2.set_row(1, 13, 14, 15.111);
	M2.set_row(2, 26, 47.0, 3);

	M3.set_col(0, std::complex<int>(0, 0), std::complex<int>(3, 6), std::complex<int>(6, 12));

	for (int i=0; i<SIZE; i++){
		for (int j=1; j<SIZE; j++){
			M3.set_value(i, j, std::complex<int>((i*SIZE+j), (i*SIZE+j)*2));
		}
	}
	
	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			BOOST_CHECK( M1.get_value(i,j) == (i*SIZE+j) );
		}
	}

	BOOST_CHECK( M2.get_value(0,0) == (float) 10.22 );
	BOOST_CHECK( M2.get_value(0,1) == (float) 11 );
	BOOST_CHECK( M2.get_value(0,2) == (float) 12.0 );
	BOOST_CHECK( M2.get_value(1,0) == (float) 13 );
	BOOST_CHECK( M2.get_value(1,1) == (float) 14 );
	BOOST_CHECK( M2.get_value(1,2) == (float) 15.111 );
	BOOST_CHECK( M2.get_value(2,0) == (float) 26 );
	BOOST_CHECK( M2.get_value(2,1) == (float) 47.0 );
	BOOST_CHECK( M2.get_value(2,2) == (float) 3 );


	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			BOOST_CHECK( M3.get_value(i,j) == std::complex<int>((i*SIZE+j), (i*SIZE+j)*2) );
		}
	}

	std::cout<<"Setting matrix, giving parameters less than matrix dimension:"<<std::endl;
	BOOST_CHECK( M2.set_matrix(2, 1, 2, 3, 4) == false ) ;
	std::cout<<std::endl;

	std::cout<<"Setting matrix, giving parameters more than matrix dimension:"<<std::endl;
	BOOST_CHECK( M2.set_matrix(2, 1, 2, 3, 4) == false ) ;
	std::cout<<std::endl;

	std::cout<<"Setting row, giving parameters less than matrix dimension:"<<std::endl;
	BOOST_CHECK( M2.set_row(2, 1, 2) == false ) ;
	std::cout<<std::endl;

	std::cout<<"Setting row, giving parameters more than matrix dimension:"<<std::endl;
	BOOST_CHECK( M2.set_row(2, 1, 2, 3, 4) == false ) ;
	std::cout<<std::endl;

	std::cout<<"Setting column, giving parameters less than matrix dimension:"<<std::endl;
	BOOST_CHECK( M2.set_col(2, 1, 2) == false ) ;
	std::cout<<std::endl;

	std::cout<<"Setting column, giving parameters more than matrix dimension:"<<std::endl;
	BOOST_CHECK( M2.set_col(2, 1, 2, 3, 4) == false ) ;
	std::cout<<std::endl;	
}

BOOST_AUTO_TEST_SUITE_END()


/////////////////////////////////////////////////////////////////////////////////
////////	MATRICES OF TYPE INTEGER
/////////////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Iteger_matrices)


BOOST_AUTO_TEST_CASE(Matrix_Addition)
{
	Matrix <int> M1(SIZE, SIZE);
	Matrix <int> M2(SIZE, SIZE);

	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			M1.set_value(i, j, (i*SIZE+j));
			M2.set_value(i, j, (i*SIZE+j)*2);
		}
	}

	Matrix <int> M3(SIZE, SIZE);
	M3 = M1 + M2;
	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			BOOST_CHECK( M3.get_value(i,j) == (i*SIZE+j)*3 );
		}
	}

	M1 += M2;
	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			BOOST_CHECK( M1.get_value(i,j) == (i*SIZE+j)*3 );
		}
	}

	Matrix <int> M4(2,3);

	for (int i=0; i<2; i++){
		for (int j=0; j<3; j++)
			M4.set_value(i, j, (i*SIZE+j));
	}

	std::cout<<"Adding matrices of 2 different dimensions:"<<std::endl;
	M4 = M2 + M4;
	std::cout<<std::endl;

}

BOOST_AUTO_TEST_CASE(Matrix_Subtraction)
{
	Matrix <int> M1(SIZE, SIZE-1);
	Matrix <int> M2(SIZE, SIZE-1);

	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE-1; j++){
			M1.set_value(i, j, (i*SIZE+j));
			M2.set_value(i, j, (i*SIZE+j)*2);
		}
	}

	Matrix <int> M3(SIZE, SIZE-1);
	M3 = M1 - M2;
	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE-1; j++){
			BOOST_CHECK( M3.get_value(i,j) == (i*SIZE+j)*(-1) );
		}
	}

	M2 -= M1;
	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE-1; j++){
			BOOST_CHECK( M2.get_value(i,j) == (i*SIZE+j) );
		}
	}

	Matrix <int> M4(2,3);

	for (int i=0; i<2; i++){
		for (int j=0; j<3; j++)
			M4.set_value(i, j, (i*SIZE+j));
	}

	std::cout<<"Subtracting matrices of 2 different dimesnsions:"<<std::endl;
	M4 = M2 - M4;
	std::cout<<std::endl;	
}


BOOST_AUTO_TEST_CASE(Matrix_Multiplication)
{
	Matrix <int> M1(SIZE, SIZE);
	Matrix <int> M2(SIZE, SIZE);

	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			M1.set_value(i, j, (i*SIZE+j));
			M2.set_value(i, j, (i*SIZE+j)*2);
		}
	}

	Matrix <int> M3(SIZE, SIZE);
	M3 = M1 * M2;


	BOOST_CHECK( M3.get_value(0,0) == 30 );
	BOOST_CHECK( M3.get_value(0,1) == 36 );
	BOOST_CHECK( M3.get_value(0,2) == 42 );
	BOOST_CHECK( M3.get_value(1,0) == 84 );
	BOOST_CHECK( M3.get_value(1,1) == 108 );
	BOOST_CHECK( M3.get_value(1,2) == 132 );
	BOOST_CHECK( M3.get_value(2,0) == 138 );
	BOOST_CHECK( M3.get_value(2,1) == 180 );
	BOOST_CHECK( M3.get_value(2,2) == 222 );


	Matrix <int> M4(1, 2);
	Matrix <int> M5(2, 3);

	M4.set_value(0, 0, 2);
	M4.set_value(0, 1, 6);

	M5.set_value(0, 0, 9);
	M5.set_value(0, 1, 12);
	M5.set_value(0, 2, 68);
	M5.set_value(1, 0, 42);
	M5.set_value(1, 1, 8);
	M5.set_value(1, 2, 6);

	Matrix <int> M6(1,3);
	M6 = M4*M5;

	BOOST_CHECK( M6.get_value(0,0) == 270 );
	BOOST_CHECK( M6.get_value(0,1) == 72 );
	BOOST_CHECK( M6.get_value(0,2) == 172 );

	Matrix <int> M7(4,4);
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			M7.set_value(i, j, (i*SIZE+j));
	}

	std::cout<<"Multiplying matrices of incompatible dimesnsions:"<<std::endl;
	M7 = M2 * M7;
	std::cout<<std::endl;	

}


BOOST_AUTO_TEST_CASE(Scalar_Operations)
{
	Matrix <int> M1(3, 3);

	M1.set_matrix(2,8,1,7,2,0,122,38,15);
	BOOST_CHECK( M1.get_value(0,0) == 2 );
	BOOST_CHECK( M1.get_value(0,1) == 8 );
	BOOST_CHECK( M1.get_value(0,2) == 1 );
	BOOST_CHECK( M1.get_value(1,0) == 7 );
	BOOST_CHECK( M1.get_value(1,1) == 2 );
	BOOST_CHECK( M1.get_value(1,2) == 0 );
	BOOST_CHECK( M1.get_value(2,0) == 122 );
	BOOST_CHECK( M1.get_value(2,1) == 38 );
	BOOST_CHECK( M1.get_value(2,2) == 15 );

	M1 += 2;
	BOOST_CHECK( M1.get_value(0,0) == 4 );
	BOOST_CHECK( M1.get_value(0,1) == 10 );
	BOOST_CHECK( M1.get_value(0,2) == 3 );
	BOOST_CHECK( M1.get_value(1,0) == 9 );
	BOOST_CHECK( M1.get_value(1,1) == 4 );
	BOOST_CHECK( M1.get_value(1,2) == 2 );
	BOOST_CHECK( M1.get_value(2,0) == 124 );
	BOOST_CHECK( M1.get_value(2,1) == 40 );
	BOOST_CHECK( M1.get_value(2,2) == 17 );

	M1 = M1 + 3;
	BOOST_CHECK( M1.get_value(0,0) == 7 );
	BOOST_CHECK( M1.get_value(0,1) == 13 );
	BOOST_CHECK( M1.get_value(0,2) == 6 );
	BOOST_CHECK( M1.get_value(1,0) == 12 );
	BOOST_CHECK( M1.get_value(1,1) == 7 );
	BOOST_CHECK( M1.get_value(1,2) == 5 );
	BOOST_CHECK( M1.get_value(2,0) == 127 );
	BOOST_CHECK( M1.get_value(2,1) == 43 );
	BOOST_CHECK( M1.get_value(2,2) == 20 );

	M1 -= 3;
	BOOST_CHECK( M1.get_value(0,0) == 4 );
	BOOST_CHECK( M1.get_value(0,1) == 10 );
	BOOST_CHECK( M1.get_value(0,2) == 3 );
	BOOST_CHECK( M1.get_value(1,0) == 9 );
	BOOST_CHECK( M1.get_value(1,1) == 4 );
	BOOST_CHECK( M1.get_value(1,2) == 2 );
	BOOST_CHECK( M1.get_value(2,0) == 124 );
	BOOST_CHECK( M1.get_value(2,1) == 40 );
	BOOST_CHECK( M1.get_value(2,2) == 17 );

	M1 = M1 - 2;
	BOOST_CHECK( M1.get_value(0,0) == 2 );
	BOOST_CHECK( M1.get_value(0,1) == 8 );
	BOOST_CHECK( M1.get_value(0,2) == 1 );
	BOOST_CHECK( M1.get_value(1,0) == 7 );
	BOOST_CHECK( M1.get_value(1,1) == 2 );
	BOOST_CHECK( M1.get_value(1,2) == 0 );
	BOOST_CHECK( M1.get_value(2,0) == 122 );
	BOOST_CHECK( M1.get_value(2,1) == 38 );
	BOOST_CHECK( M1.get_value(2,2) == 15 );

	M1 *= 3;
	BOOST_CHECK( M1.get_value(0,0) == 6 );
	BOOST_CHECK( M1.get_value(0,1) == 24 );
	BOOST_CHECK( M1.get_value(0,2) == 3 );
	BOOST_CHECK( M1.get_value(1,0) == 21 );
	BOOST_CHECK( M1.get_value(1,1) == 6 );
	BOOST_CHECK( M1.get_value(1,2) == 0 );
	BOOST_CHECK( M1.get_value(2,0) == 366 );
	BOOST_CHECK( M1.get_value(2,1) == 114 );
	BOOST_CHECK( M1.get_value(2,2) == 45 );

	M1 = M1 * 2;
	BOOST_CHECK( M1.get_value(0,0) == 12 );
	BOOST_CHECK( M1.get_value(0,1) == 48 );
	BOOST_CHECK( M1.get_value(0,2) == 6 );
	BOOST_CHECK( M1.get_value(1,0) == 42 );
	BOOST_CHECK( M1.get_value(1,1) == 12 );
	BOOST_CHECK( M1.get_value(1,2) == 0 );
	BOOST_CHECK( M1.get_value(2,0) == 732 );
	BOOST_CHECK( M1.get_value(2,1) == 228 );
	BOOST_CHECK( M1.get_value(2,2) == 90 );

	M1 /= 2;
	BOOST_CHECK( M1.get_value(0,0) == 6 );
	BOOST_CHECK( M1.get_value(0,1) == 24 );
	BOOST_CHECK( M1.get_value(0,2) == 3 );
	BOOST_CHECK( M1.get_value(1,0) == 21 );
	BOOST_CHECK( M1.get_value(1,1) == 6 );
	BOOST_CHECK( M1.get_value(1,2) == 0 );
	BOOST_CHECK( M1.get_value(2,0) == 366 );
	BOOST_CHECK( M1.get_value(2,1) == 114 );
	BOOST_CHECK( M1.get_value(2,2) == 45 );

	M1 = M1 / 3;
	BOOST_CHECK( M1.get_value(0,0) == 2 );
	BOOST_CHECK( M1.get_value(0,1) == 8 );
	BOOST_CHECK( M1.get_value(0,2) == 1 );
	BOOST_CHECK( M1.get_value(1,0) == 7 );
	BOOST_CHECK( M1.get_value(1,1) == 2 );
	BOOST_CHECK( M1.get_value(1,2) == 0 );
	BOOST_CHECK( M1.get_value(2,0) == 122 );
	BOOST_CHECK( M1.get_value(2,1) == 38 );
	BOOST_CHECK( M1.get_value(2,2) == 15 );

}


BOOST_AUTO_TEST_CASE(Determinant_of_matrix)
{
	Matrix <int> M1(3, 3);
	M1.set_matrix(2,8,1,7,2,0,122,38,15);
	BOOST_CHECK( M1.det() == -758 );

	Matrix <int> M2(2, 3);
	M2.set_matrix(2,8,1,7,2,0);

	std::cout<<"Determinant of non square matrix:"<<std::endl;
	BOOST_CHECK( M2.det() == 0 );
	std::cout<<std::endl;	
}


BOOST_AUTO_TEST_CASE(Inverse_of_matrix)
{
	Matrix <int> M1(3, 3);
	M1.set_matrix(2,8,1,7,2,0,122,38,15);

	Matrix <double> M2;
	M2 = M1.inv(M1);

	Matrix <double> M3(M1);
	M3 = M3 * M2;

	double e = 1e-9;

	BOOST_CHECK( M3.get_value(0,0) >= 1-e && M3.get_value(0,0) <= 1+e );
	BOOST_CHECK( M3.get_value(0,1) >= -e && M3.get_value(0,1) <= e );
	BOOST_CHECK( M3.get_value(0,2) >= -e && M3.get_value(0,2) <= e );
	BOOST_CHECK( M3.get_value(1,0) >= -e && M3.get_value(1,0) <= e );
	BOOST_CHECK( M3.get_value(1,1) >= 1-e && M3.get_value(1,1) <= 1+e );
	BOOST_CHECK( M3.get_value(1,2) >= -e && M3.get_value(1,2) <= e );
	BOOST_CHECK( M3.get_value(2,0) >= -e && M3.get_value(2,0) <= e );
	BOOST_CHECK( M3.get_value(2,1) >= -e && M3.get_value(2,1) <= e );
	BOOST_CHECK( M3.get_value(2,2) >= 1-e && M3.get_value(2,2) <= 1+e );


	Matrix <int> M4(2, 3);
	M4.set_matrix(2,8,1,7,2,0);

	std::cout<<"Determinant of non square matrix:"<<std::endl;
	M2 = M4.inv(M4);
	std::cout<<std::endl;	

	//Calculating inverse for non singular matrix
	Matrix <int> M5(3, 3);
	M5.set_matrix(0,1,2,3,4,5,6,7,8);

	std::cout<<"Determinant of singular matrix:"<<std::endl;
	M2 = M5.inv(M5);
	std::cout<<std::endl;	

}


 
BOOST_AUTO_TEST_SUITE_END()





