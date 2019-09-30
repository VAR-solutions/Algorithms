#include "Matrix.h"
#include <iostream>

template 
	<typename T>

void fillMatrix(Matrix<T> &m)
{
	int i, j;
	for(i=0;i < m.numRows(); i++)
		m[i][0] = T();
	for(j = 0; j < m.numCols(); j++)
		m[0][j] = T();
	for(i = 1; i < m.numRows(); i++)
		for( j = 1; j < m.numCols(); j++)
		{
			m[i][j] = T(i * j);
		}
}

void test_int_matrix()
{
	cout << "Testing INT Matrix...\n" << endl;
	Matrix<int> m(10,5);
	fillMatrix(m);
	cout << m << "Done\n" << endl;
}

void test_double_matrix()
{
	cout << "Testing DOUBLE Matrix...\n" << endl;
	Matrix < double > M(8, 10);
	fillMatrix(M);
	cout << M << "Done\n" << endl;
}

template
	<typename Type>
void generate_exception(Matrix <Type> &m)
{
	//insert a for loop that cause the exception
	cout << "Generating Exception..." << endl;
	cout << "It will try to access rows 0-15 and cols 0-15\n";
	for(int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			m[i][j];
		}
		cout << endl;
	}
}		

void test_double_matrix_exceptions()
{
	//PUT YOUR TRY/CATCH AROUND THE INSTRUCTIONS BELOW
	try
	{
		cout << "Starting Double Matrix Exception...\n";
		cout << "Matrix <double> M(8,10);\n\n";
		Matrix < double > M (8,10);
		fillMatrix( M );
		cout << M;
		generate_exception( M );	
	}
	catch ( const IndexOutOfBoundsException & e)
	{
		cout << "\nERROR: Index out of bounds." << endl;
	}
	cout << "Done\n" << endl;
}

void test_int_matrix_exceptions()
{
	//PUT YOUR TRY/CATCH AROUND THE INSTRUCTIONS BELOW
	try
	{
		cout << "Starting Int Matrix Exception...\n";
		cout <<"Matrix <int> m(10,10);\n\n";
		Matrix < int > m (10,10);
		fillMatrix( m );
		cout << m;
		generate_exception( m );
	}
	catch ( const IndexOutOfBoundsException & e)
	{
		cout << "\nERROR: Index out of bounds." << endl;
	}
	cout << "Done\n" << endl;
}

int main()
{
	for (int i = 1; i <= 3; ++i)
	{
		cout << "Test " << i << "\n" << endl;
		test_int_matrix();
		test_double_matrix();
		test_int_matrix_exceptions();
		test_double_matrix_exceptions();
		
	}
	return 0;
}
