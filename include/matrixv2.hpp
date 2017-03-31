#ifndef _MATRIX_
#define _MATRIX_

#include <vector>
#include <iostream>
#include <complex.h>
#include <array>
#include <numeric>

template <typename T>
class Expression {
public:
  inline const T& self(void) const {
    return *static_cast<const T*>(this);
  }
};

template<typename Tleft, typename Tright>
class binary_add_expression: public Expression<binary_add_expression<Tleft, Tright> > {
	public:
		const Tleft &left;
		const Tright &right;
	binary_add_expression(const Tleft& left, const Tright& right) : left(left), right(right) {
		if ( left.get_row_size()!=right.get_row_size() || left.get_col_size()!=right.get_col_size() ){
			std :: cerr << "Dimensions of the two matrices are not same for matrix addition. Exitting."<<std::endl;
			exit(-1);
		}
	}

	inline auto Eval(int i, int j) const {
		return left.Eval(i,j) + right.Eval(i,j);
	}
};


template<typename Tleft, typename scalar_type>
class scalar_add_expression: public Expression<scalar_add_expression<Tleft, scalar_type> > {
	public:
		const Tleft &left;
		const scalar_type &right;
	scalar_add_expression(const Tleft& left, const scalar_type& right) : left(left), right(right) {}

	inline auto Eval(int i, int j) const {
		return left.Eval(i,j) + right;
	}
};


template<typename Tleft, typename Tright>
class binary_sub_expression: public Expression<binary_sub_expression<Tleft, Tright> > {
	public:
		const Tleft &left;
		const Tright &right;
	binary_sub_expression(const Tleft& left, const Tright& right) : left(left), right(right) {
		if ( left.get_row_size()!=right.get_row_size() || left.get_col_size()!=right.get_col_size() ){
			std :: cerr << "Dimensions of the two matrices are not same for matrix subtraction. Exitting."<<std::endl;
			exit(-1);
		}		
	}

	inline auto Eval(int i, int j) const {
		return left.Eval(i,j) - right.Eval(i,j);
	}
};


template<typename Tleft, typename scalar_type>
class scalar_sub_expression: public Expression<scalar_sub_expression<Tleft, scalar_type> > {
	public:
		const Tleft &left;
		const scalar_type &right;
	scalar_sub_expression(const Tleft& left, const scalar_type& right) : left(left), right(right) {}

	inline auto Eval(int i, int j) const {
		return left.Eval(i,j) - right;
	}
};


template<typename Tleft, typename Tright>
class binary_mul_expression: public Expression<binary_mul_expression<Tleft, Tright> > {
	public:
		const Tleft &left;
		const Tright &right;
	binary_mul_expression(const Tleft& left, const Tright& right) : left(left), right(right) {
		if ( left.get_col_size()!=right.get_row_size() ){
			std :: cerr << "Dimensions of the two matrices are not compatible for matrix multiplication. Exitting."<<std::endl;
			exit(-1);
		}
	}

	inline auto Eval(int i, int j) const {
		auto y=right.get_value(0,0);
		auto x=y;
		x=0;
		for (int k=0; k<left.get_col_size(); k++){
			x += (left.Eval(i,k) * right.Eval(k,j));
		}
		return x;
	}
};


template<typename Tleft, typename scalar_type>
class scalar_mul_expression: public Expression<scalar_mul_expression<Tleft, scalar_type> > {
	public:
		const Tleft &left;
		const scalar_type &right;
	scalar_mul_expression(const Tleft& left, const scalar_type& right) : left(left), right(right) {}

	inline auto Eval(int i, int j) const {
		return left.Eval(i,j) * right;
	}
};


template<typename Tleft, typename scalar_type>
class scalar_div_expression: public Expression<scalar_div_expression<Tleft, scalar_type> > {
	public:
		const Tleft &left;
		const scalar_type &right;
	scalar_div_expression(const Tleft& left, const scalar_type& right) : left(left), right(right) {}

	inline auto Eval(int i, int j) const {
		return left.Eval(i,j) / right;
	}
};


template <class data_type>
class Matrix : public Expression <Matrix <data_type>>{ 
	private:
		typedef std::vector<data_type> row;
		typedef std::vector<row> matrix;
		matrix M;
		unsigned int row_size;
		unsigned int col_size;
		std::vector <data_type> vals;


	public: 

		// Constructor with no parameters
		Matrix();

		// Constructor with predefined row size and column size
		Matrix(const unsigned int r_size, const unsigned int c_size);

		// Copy constructor
		template <class e_type>
		Matrix (const Matrix <e_type> &obj);



		template<typename Tleft, typename Tright>
		inline Matrix& operator= (const binary_mul_expression<Tleft, Tright>& src_) {
			Tleft X(src_.left.get_row_size(), src_.right.get_col_size());

			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					X.set_value(i, j, src_.self().Eval(i,j));
				}	    	
			}

			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i, j, X.get_value(i,j));
				}	    	
			}
			
			return *this;
		}

		template<typename EType>
		inline Matrix& operator= (const Expression<EType>& src_) {
			const EType &src = src_.self();
			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i, j, src.Eval(i,j));
				}	    	
			}
			return *this;
		}

		template<typename EType>
		inline Matrix& operator+= (const Expression<EType>& src_) {
			const EType &src = src_.self();
			if ( row_size!=src.get_row_size() || col_size!=src.get_col_size() ){
				std :: cerr << "Dimensions of the two matrices are not same for matrix addition. Resultant = First_matrix."<<std::endl;
				return *this;
			}
			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i, j, get_value(i,j)+src.Eval(i,j));
				}	    	
			}
			return *this;
		}

		template<typename T,
		typename std::enable_if<std::is_same<data_type, T>::value>::type* = nullptr >
		inline Matrix& operator+= (const T &src) {
			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i, j, get_value(i,j)+src);
				}	    	
			}
			return *this;
		}


		template<typename EType>
		inline Matrix& operator-= (const Expression<EType>& src_) {
			const EType &src = src_.self();
			if ( row_size!=src.get_row_size() || col_size!=src.get_col_size() ){
				std :: cerr << "Dimensions of the two matrices are not same for matrix subtraction. Resultant = First_matrix."<<std::endl;
				return *this;
			}
			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i, j, get_value(i,j)-src.Eval(i,j));
				}	    	
			}
			return *this;
		}

		template<typename T,
		typename std::enable_if<std::is_same<data_type, T>::value>::type* = nullptr >
		inline Matrix& operator-= (const T &src) {
			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i, j, get_value(i,j)-src);
				}	    	
			}
			return *this;
		}


		template<typename EType>
		inline Matrix& operator*= (const Expression<EType>& src_) {
			const EType &src = src_.self();
			if ( col_size!=src.get_row_size() ){
				std :: cerr << "Dimensions of the two matrices are not compatible for matrix multiplication."<<std::endl;
				return *this;
			}

			EType X(row_size, src.get_col_size());

			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					auto x=get_value(0,0);
					x=0;
					for (int k=0; k<get_col_size(); k++){
						x += (get_value(i,k) * src.Eval(k,j));
					}
					X.set_value(i, j, x);
				}	    	
			}
			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i,j,X.get_value(i,j));
				}
			}			

			return *this;
		}

		template<typename T,
		typename std::enable_if<std::is_same<data_type, T>::value>::type* = nullptr >
		inline Matrix& operator*= (const T &src) {
			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i, j, get_value(i,j)*src);
				}	    	
			}
			return *this;
		}


		template<typename T,
		typename std::enable_if<std::is_same<data_type, T>::value>::type* = nullptr >
		inline Matrix& operator/= (const T &src) {
			for (int i = 0; i < row_size; i++) {
				for (int j=0; j<col_size; j++){
					set_value(i, j, get_value(i,j)/src);
				}	    	
			}
			return *this;
		}

		inline auto Eval(int i, int j) const {
			return get_value(i,j);
		}		

		// Helper functions
		void populate_vector() {}
		template <typename... Args>
		void populate_vector(data_type value, Args... args);

		template <typename... Args>
		bool set_matrix (data_type value, Args... args);

		template <typename... Args>
		bool set_row (const unsigned int row, data_type value, Args... args);

		template <typename... Args>
		bool set_col (const unsigned int col, data_type value, Args... args);

		void resize (const unsigned int r_size, const  unsigned int c_size);
		void display_matrix() const;
		void display_row(const unsigned int row);
		void display_col(const unsigned int col);

		void set_value(const unsigned int row, const unsigned int col, const data_type val);
		data_type get_value(const unsigned int row, const unsigned int col) const;

		unsigned int get_row_size() const;

		unsigned int get_col_size() const;



		data_type det ();
		// Helper functions
		data_type determinant (Matrix <data_type> &mat, int N);
		void cofactor_matrix (Matrix <data_type> &mat, Matrix <data_type> &cofactor, int p, int q, int N);

		template <typename d_type>
		Matrix <std::complex<double>>  inv (Matrix <std::complex<d_type>> &A, int a);
		// Helper functions
		template <typename d_type>		
		void  adjoint(Matrix <std::complex<d_type>> &A,Matrix <std::complex<d_type>> &adj);
		template <typename d_type>
		bool  inverse(Matrix <std::complex<d_type>> &A, Matrix <std::complex<double>> &inverse);

		Matrix <double> inv (Matrix <data_type> &A);
		// Helper functions
		void adjoint(Matrix <data_type> &A,Matrix <data_type> &adj);
		bool inverse(Matrix <data_type> &A, Matrix <double> &inverse);


		
}; 


template <class data_type> 
Matrix <data_type> :: Matrix(){	
	row_size = col_size = 0;
}

template <class data_type> 
Matrix <data_type> :: Matrix(const unsigned int r_size, const unsigned int c_size){
	row_size = r_size;
	col_size = c_size;
	
	M.resize(row_size);
	for (int i=0; i<row_size; i++)
		M[i].resize(col_size);
}

template <class data_type>
template <class e_type> 
Matrix <data_type> :: Matrix(const Matrix <e_type> &obj){
	row_size = obj.get_row_size();
	if (row_size > 0)
		col_size = obj.get_col_size();
	else
		col_size = 0;
	
	M.resize(row_size);

	for (int i=0; i<row_size; i++){
		M[i].resize(col_size);
		for (int j=0; j<col_size; j++)
			M[i][j] = obj.get_value(i, j);
	}
}

template <class data_type>
template <typename... Args>
void Matrix <data_type> :: populate_vector (data_type value, Args... args){
	vals.push_back(value);
	if( sizeof...(args)>0 )
		populate_vector (args... );
}

template <class data_type>
template <typename... Args>
bool Matrix <data_type> :: set_matrix (data_type value, Args... args){
	int n = sizeof...(args)+1;
	if ( n != (row_size*col_size) ){
		std :: cerr << "The number of arguments do not match with the dimensions of the matrix."<<std :: endl;
		return false;
	}

	vals.clear();
	populate_vector (value, args...);

	for (int i=0; i<row_size; i++){
		for (int j=0; j<col_size; j++)
			M[i][j] = vals[i*row_size+j];
	}
	return true;
}

template <class data_type>
template <typename... Args>
bool Matrix <data_type> :: set_row (const unsigned int row, data_type value, Args... args){
	int n = sizeof...(args)+1;
	if ( n != (row_size) ){
		std :: cerr << "The number of arguments do not match with the row size."<<std :: endl;
		return false;
	}

	if ( row >= col_size ){
		std :: cerr << "The column specified is out of bounds"<<std :: endl;
		return false;
	}

	vals.clear();
	populate_vector (value, args...);

	for (int i=0; i<row_size; i++)
		M[row][i] = vals[i];

	return true;
}

template <class data_type>
template <typename... Args>
bool Matrix <data_type> :: set_col (const unsigned int col, data_type value, Args... args){
	int n = sizeof...(args)+1;

	if ( n != (col_size) ){
		std :: cerr << "The number of arguments do not match with the column size."<<std :: endl;
		return false;
	}

	if ( col >= row_size ){
		std :: cerr << "The column specified is out of bounds"<<std :: endl;
		return false;
	}

	vals.clear();
	populate_vector (value, args...);

	for (int i=0; i<row_size; i++)
		M[i][col] = vals[i];
	return true;
}

template <class data_type> 
void Matrix <data_type> :: resize(const unsigned int r_size, const unsigned int c_size){
	row_size = r_size;
	col_size = c_size;
	
	M.resize(row_size);
	for (int i=0; i<row_size; i++)
		M[i].resize(col_size);
}

template <class data_type> 
void Matrix <data_type> :: display_matrix() const{
	for (int i=0; i<row_size; i++){
		for (int j=0; j<col_size; j++)
			std :: cout<<M[i][j]<<" ";
		std :: cout<<std :: endl;
	}	
	std :: cout<<std :: endl;
}

template <class data_type> 
void Matrix <data_type> :: display_row(const unsigned int row){
	for (int j=0; j<col_size; j++)
		std :: cout<<M[row][j]<<" ";
	std :: cout<<std :: endl<<std :: endl;
}

template <class data_type> 
void Matrix <data_type> :: display_col(const unsigned int col){
	for (int i=0; i<row_size; i++)
		std :: cout<<M[i][col]<<std :: endl;
	std :: cout<<std :: endl;
}

template <class data_type> 
void Matrix <data_type> :: set_value(const unsigned int row, const unsigned int col, const data_type val){
	M[row][col] = val;
}

template <class data_type> 
data_type Matrix <data_type> :: get_value(const unsigned int row, const unsigned int col) const{
	return M[row][col];
}

template <class data_type> 
unsigned int Matrix <data_type> :: get_row_size() const{
	return row_size;
}

template <class data_type> 
unsigned int Matrix <data_type> :: get_col_size() const{
	return col_size;
}


template <class data_type> 
data_type Matrix <data_type> :: det (){
	if ( row_size != col_size ){
		std :: cerr << "Square matrix required for calculating determinant. Returning 0."<<std::endl;
		return 0;
	}

	Matrix <data_type> mat( row_size, col_size);

	for (int i=0; i< row_size; i++){
		for (int j=0; j< col_size; j++)
			mat.set_value(i, j, M[i][j]);
	}	

	return determinant (mat, row_size);

}

template <class data_type> 
data_type Matrix <data_type> :: determinant (Matrix <data_type> &mat, int N){
    
    if (N == 1)
        return mat.get_value(0, 0);
    
    data_type det = 0;

	Matrix <data_type> cofactor(N, N);

    int sign_multiplier = 1;

    for (int i = 0; i < N; i++){
        cofactor_matrix(mat, cofactor, 0, i, N);
        det += (sign_multiplier * mat.get_value(0, i) * determinant(cofactor, N-1));
        sign_multiplier = -sign_multiplier;
    }
 
    return det;
}

template <class data_type> 
void Matrix <data_type> :: cofactor_matrix (Matrix <data_type> &mat, Matrix <data_type> &cofactor, int p, int q, int N){
	int i = 0, j = 0;
 
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){

            if (row != p && col != q){
            	cofactor.set_value(i, j, mat.get_value(row, col));
            	j++;
 
                if (j == N - 1){
                    j = 0;
                    i++;
                }
            }
        }
    }	

}

template <class data_type> 
template <typename d_type>
Matrix <std::complex<double>> Matrix <data_type> :: inv (Matrix <std::complex<d_type>> &A, int a){
	Matrix <std::complex<double>> inv(row_size, col_size);

	if ( A.get_col_size() != A.get_row_size() ){
		std :: cerr << "Square matrix required for calculating inverse. Returning 0 matrix."<<std::endl;
		return inv;
	}

	if (inverse(A, inv))
		return inv;

	Matrix <std::complex<double>> x(row_size, col_size);
	return x;

}

template <class data_type> 
template <typename d_type>
void Matrix <data_type> :: adjoint(Matrix <std::complex<d_type>> &A,Matrix <std::complex<d_type>> &adj){
	int N = adj.row_size;
    if (N == 1)
    {
        adj.set_value(0, 0, std::complex<int>(1, 0));
        return;
    }
 
    int sign = 1;
    Matrix <std::complex<d_type>> temp(N, N);
 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cofactor_matrix(A, temp, i, j, N);
            sign = ((i+j)%2==0)? 1: -1;
            adj.set_value(j, i, (sign)*(determinant(temp, N-1)));
        }
    }
}

template <class data_type> 
template <typename d_type>
bool Matrix <data_type> :: inverse(Matrix <std::complex<d_type>> &A, Matrix <std::complex<double>> &inverse){
	int N = A.row_size;
    data_type det = determinant(A, N);
    if (det == 0)
    {
        std::cout << "Singular matrix, can't find its inverse"<<std::endl;
        return false;
    }
 
    Matrix <std::complex<d_type>> adj(N, N);
    adjoint(A, adj);

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
        	double real = adj.get_value(i,j).real();
        	double imag = adj.get_value(i,j).imag();
        	std::complex<double> x = std::complex<double>(real, imag) ;

        	real = det.real();
        	imag = det.imag();
        	std::complex<double> y = std::complex<double>(real, imag) ;

        	x = x / y;
            inverse.set_value(i, j, x);
        }
    }
 
    return true;
}




template <class data_type> 
Matrix <double> Matrix <data_type> :: inv (Matrix <data_type> &A){
	Matrix <double> inv(row_size, col_size);

	if ( A.get_row_size() != A.get_col_size() ){
		std :: cerr << "Square matrix required for calculating inverse. Returning 0 matrix."<<std::endl;
		return inv;
	}

	if (inverse(A, inv))
		return inv;

	Matrix <double> x(row_size, col_size);
	return x;

}

template <class data_type> 
void Matrix <data_type> :: adjoint(Matrix <data_type> &A,Matrix <data_type> &adj){
	int N = adj.row_size;
    if (N == 1)
    {
        adj.set_value(0, 0, 1);
        return;
    }
 
    int sign = 1;
    Matrix <data_type> temp(N, N);
 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cofactor_matrix(A, temp, i, j, N);
            sign = ((i+j)%2==0)? 1: -1;
            adj.set_value(j, i, (sign)*(determinant(temp, N-1)));
        }
    }
}

template <class data_type> 
bool Matrix <data_type> :: inverse(Matrix <data_type> &A, Matrix <double> &inverse){
	int N = A.row_size;
    data_type det = determinant(A, N);
    if (det == 0)
    {
        std::cout << "Singular matrix, can't find its inverse"<<std::endl;
        return false;
    }
 
    Matrix <data_type> adj(N, N);
    adjoint(A, adj);

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            inverse.set_value(i, j, adj.get_value(i,j) / (double) det);
    }
 
    return true;
}


template<typename Tleft, typename Tright>
inline binary_add_expression<Tleft, Tright>
operator+(const Expression<Tleft> &left, const Expression<Tright> &right) {
	// if ( left.get_row_size()!=right.get_row_size() || left.get_col_size()!=right.get_col_size() ){
	// 	std :: cerr << "Dimensions of the two matrices are not same for matrix addition. Resultant = First_matrix."<<std::endl;
	// 	return left;
	// }
	return binary_add_expression<Tleft, Tright>(left.self(), right.self());
}

template<typename Tleft, typename scalar_type, 
typename std::enable_if<std::is_same<Tleft, Matrix<scalar_type>>::value>::type* = nullptr >
inline scalar_add_expression<Tleft, scalar_type>
operator+(const Expression<Tleft> &left, const scalar_type &right) {
	return scalar_add_expression<Tleft, scalar_type>(left.self(), right);
}

template<typename Tleft, typename Tright>
inline binary_sub_expression<Tleft, Tright>
operator-(const Expression<Tleft> &left, const Expression<Tright> &right) {
	return binary_sub_expression<Tleft, Tright>(left.self(), right.self());
}

template<typename Tleft, typename scalar_type, 
typename std::enable_if<std::is_same<Tleft, Matrix<scalar_type>>::value>::type* = nullptr >
inline scalar_sub_expression<Tleft, scalar_type>
operator-(const Expression<Tleft> &left, const scalar_type &right) {
	return scalar_sub_expression<Tleft, scalar_type>(left.self(), right);
}


template<typename Tleft, typename Tright>
inline binary_mul_expression<Tleft, Tright>
operator*(const Expression<Tleft> &left, const Expression<Tright> &right) {
	return binary_mul_expression<Tleft, Tright>(left.self(), right.self());
}

template<typename Tleft, typename scalar_type, 
typename std::enable_if<std::is_same<Tleft, Matrix<scalar_type>>::value>::type* = nullptr >
inline scalar_mul_expression<Tleft, scalar_type>
operator*(const Expression<Tleft> &left, const scalar_type &right) {
	return scalar_mul_expression<Tleft, scalar_type>(left.self(), right);
}


template<typename Tleft, typename scalar_type, 
typename std::enable_if<std::is_same<Tleft, Matrix<scalar_type>>::value>::type* = nullptr >
inline scalar_div_expression<Tleft, scalar_type>
operator/(const Expression<Tleft> &left, const scalar_type &right) {
	return scalar_div_expression<Tleft, scalar_type>(left.self(), right);
}




#endif