#pragma once
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       

/*
class for matrix and vector arithmatic.
Available operation:
1. matrix*matrix
2. matrix*vector
3. matrix+matrix
4. vector+vector
5. matrix*scalar
6. vector* scalar
Developed by: Dev Poudel toyou.dev@gmail.com

*/

namespace dpoudel
{
	using namespace std;

	//Vector class for 
	template <class T>
	class VectorXd
	{
		public:
		//Set vector size
		VectorXd(int s)
		{	size=s;
			v_values=vector<T>(size);
		}

		//Initialize the vector. Initialization is random numbers
		void Initialize()
		{
			for(int i=0;i<size;i++)
				v_values[i]=rand() % 101 + 1;
		}

		//overloading += operator for vector addition
		VectorXd<T> & operator+=(VectorXd<T>& rhs)
		{
			if(size!=rhs.size)
			{
				cout<<"Illegal operation !! Size of vectors must be same";

				system("pause");
				exit(0);
			}
			for(int i=0;i<size;i++)
				v_values[i]=v_values[i]+rhs.v_values[i];
			return *this;
		}
	
		//overloading << operator for displaying vectors
		friend ostream &operator<<(ostream &out, VectorXd<T> &v)     //output
		{	out<<endl<<"----------------"<<endl;
			for(int i=0;i<v.size;i++)
				out<<v.v_values[i]<<endl<<endl;
			return out;
		}

		//vector scalar product
		VectorXd<T> & operator*=(const T& rhs)
		{
			for(int i=0;i<size;i++)
				v_values[i]=v_values[i]*rhs;
			return *this;
		}

		public: vector<T> v_values;
				int size;
	};


	//Matrix class for any size Rows*Columns
	template<class T>
	class Matrix
	{
		public:
		//initialize rows and columns and allocate memory
		Matrix(int rws, int cols)
		{
			// init m_values to appropriate rows and cols
			rows=rws;
			columns=cols;
			//matrix of rows*cols
			m_values=vector<vector<T>>(rows, std::vector<T>(cols));
		}

		//initialize the matrix elements
		void Initialize()
		{   
			srand (time(NULL));
  			for(int i=0;i<rows;i++)
				for(int j=0;j<columns;j++)
					m_values[i][j]=rand() % 101 + 1;;
		}

		//overloading << operator for displaying matrix elements
		friend ostream &operator<<(ostream &out, Matrix<T> &m)  
		{
			out<<endl<<"------------"<<endl;
			for(int i=0;i<m.rows;i++)
				{  for(int j=0;j<m.columns;j++)
				out<<m.m_values[i][j]<<" ";
				out<<endl;
			}
			return out;
		}
   
		//matrix addition 
		Matrix<T>& operator+=(const Matrix<T>& rhs)
		{
			if(rows!=rhs.rows || columns!=rhs.columns)
			{
				cout<<" Matrix addition error...Illeal operation!!! two matrices must have same size";
				system("pause");
				exit(0);
			}
			// add this matrix to the rhs matrix
			for(int i=0; i<this->rows; ++i)
			for(int  j=0; j<this->columns; ++j)
				m_values[i][j]= m_values[i][j]+rhs.m_values[i][j];

			return *this;
		}
   
		//overloading * operator for matrix multiplication(matrix*matrix)
		Matrix<T> operator*(const Matrix<T>& rhs)
		{
			if(columns!=rhs.rows)
			{	cout<<"Matrix multiplication error !!!Columns of first matrix should be equal to rows of second matrix";
				system("pause");
				exit(0);
			}

		Matrix<T> result(rows,rhs.columns);
   		/* Initializing elements of matrix result to 0.*/
		for(int i=0; i<result.rows; ++i)
		for(int j=0; j<result.columns; ++j)
		{
			result.m_values[i][j]=0;
		}

		for(int i=0; i<this->rows; ++i)
			for(int  j=0; j<rhs.columns; ++j)
			for(int k=0; k<this->columns; ++k)
			{
				result.m_values[i][j]+=m_values[i][k]*rhs.m_values[k][j];
			}
		
			return result;
		}


		//matrix*vector product
		VectorXd<T> operator *(VectorXd<T> &vec)
		{
			if(columns!=vec.size)
			{
				cout<<" Matrix vector multiplication error!!Illegal operation !! Size of matrix columns should be equal to vector size";

				system("pause");
				exit(0);
			}
			VectorXd<T> result(rows);

			for (int i=0;i<rows;i++)
			{
				for (int j=0;j<columns;j++)
				{
					result.v_values[i]+=(m_values[i][j]*vec.v_values[j]);
				}
			}
	
			return result;
		}



		//Scalar matrix multiplication
		Matrix<T> operator*(const T& rhs)
		{
			Matrix<T> result(rows,columns);
    
			for(int i=0; i<this->rows; ++i)
				for(int  j=0; j<columns; ++j)
       
				{
					result.m_values[i][j]=m_values[i][j]*rhs;
				}

			return result;
		}


	private:
		// two dimensional dynamic array of type T values
		std::vector< std::vector< T > > m_values; 
		int rows;
		int columns;
	};

}