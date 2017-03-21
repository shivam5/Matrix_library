
BOOST_AUTO_TEST_CASE(Determinant_of_matrix)
{
	Matrix <std::complex<int>> M1(3, 3);
	M1.set_matrix(2,8,1,7,2,0,122,38,15);
	BOOST_CHECK( M1.det() == -758 );

	Matrix <std::complex<int>> M2(2, 3);
	M2.set_matrix(2,8,1,7,2,0);

	std::cout<<"Determinant of non square complex matrix:"<<std::endl;
	BOOST_CHECK( M2.det() == 0 );
	std::cout<<std::endl;	
}


BOOST_AUTO_TEST_CASE(Inverse_of_matrix)
{
	Matrix <std::complex<int>> M1(3, 3);
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


	Matrix <std::complex<int>> M4(2, 3);
	M4.set_matrix(2,8,1,7,2,0);

	std::cout<<"Determinant of non square complex matrix:"<<std::endl;
	M2 = M4.inv(M4);
	std::cout<<std::endl;	

	//Calculating inverse for non singular matrix
	Matrix <std::complex<int>> M5(3, 3);
	M5.set_matrix(0,1,2,3,4,5,6,7,8);

	std::cout<<"Determinant of singular complex matrix:"<<std::endl;
	M2 = M5.inv(M5);
	std::cout<<std::endl;	

}


 
BOOST_AUTO_TEST_SUITE_END()

