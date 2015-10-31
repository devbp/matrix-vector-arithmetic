// atlatec.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include"TMatrix.h"
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	//test samples
	dpoudel::Matrix<float> m1(4,3);
	dpoudel::Matrix<float> m2(3,4);
	dpoudel::Matrix<float> m3(4,4);
	m1.Initialize();
	m2.Initialize();			
	cout<<"Matrix m1"<<m1;
	cout<<"Matrix m2"<<m2;
	//matrix *scalar product
	m3=m1*0.1;
	cout<<"scalar product of matrix m3=m1*0.1"<<m3<<endl;
	//matrix addition
	m3+=m1;
	cout<<"Matrix addition m3+=m1"<<m3<<endl;
	//matrix multiplication
	m3=m1*m2;
	cout<<"m3=m1*m2;"<<m3<<endl;
    dpoudel::VectorXd<float>v1(4);
	v1.Initialize();
	cout<<"vector v1"<<v1<<endl;
	//vector addition
	v1+=v1;
	cout<<"vector addition v1+=v1"<<v1<<endl;
	//vector scalar product
	v1*=0.1;
	cout<<" Vector scalar multiplication v1*=0.1"<<v1<<endl;
	//matrix vector production
	v1=m3*v1;
	cout<<"v1=m3*v1"<<v1<<endl;
	system("pause");
	return 0;

}

