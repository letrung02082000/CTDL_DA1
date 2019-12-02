#include "vector.h"
#include "matrix.cpp"
void main()
{
	cout << "Do an CTDL-GT" << endl;
	cout << "Chon phuong an de bat dau: \n";
	cout << "a: Su dung cong cu vecto.\n";
	cout << "b: Su dung cong cu matrix.\n";
	cout << "c: Ket thuc chuong trinh.\n";
	cout << "Hay lua chon: "; char choice;
	cin >> choice;
	
	switch (choice)
	{
	default: break;
	case('a'):
		{
		vector vt1, vt2, cong;
		float alpha = 1;
		cout << "Nhap toa do vector thu 1:" << endl;
		cin >> vt1;
		cout << "Nhap toa do vector thu 2:" << endl;
		cin >> vt2;
		cong = vt1 + vt2;
		cout << cong << endl;
		//Nhan
		vector nhan;
		cout << "Nhap toa do vector: " << endl;
		cin >> nhan;
		cout << "Nhap so Alpha: ";
		cin >> alpha;
		nhan.multiply(alpha);
		cout << "Ket qua:";
		cout << nhan << endl;
		break;
		}
	case ('b'):
		{
		int **m1, a, b;
		cout << "Nhap so chieu cua ma tran 1: \n";
		cin >> a ;
		cin >> b;
		Matrix x;
		x.Create_Matrix(m1, a, b);
		x.Display(m1, a, b);
		x.Inverse_Matrix(m1, x.Matrix_determinant(m1, a), a);
		cout << "Dinh thuc cua ma tran vua nhap: " << x.Matrix_determinant(m1,a) << endl; 
		cout << "Hang cua ma tran vua nhap: " << x.rankOfMatrix(m1, a, b) << endl; 
		
				
		cout << "Nhap so chieu cua ma tran 2: \n";
		int **m2, c, d;
		cin >> c >> d;
		Matrix y;
		y.Create_Matrix(m2, c, d);
		y.Display(m2, c, d);
		y.Inverse_Matrix(m1, x.Matrix_determinant(m2, c), c);
		cout << "Dinh thuc cua ma tran vua nhap: " << y.Matrix_determinant(m2, c) << endl;
		cout << "Hang cua ma tran vua nhap: " << y.rankOfMatrix(m2, c, d) << endl;

		int **m3;
		m3 = y.Multiply_Matrix(a, b, d, m1, m2);
		cout << "Phep nhan 2 ma tran tren: \n";
		display_mat(m3, a, d);

		break;
		}
	}


}
