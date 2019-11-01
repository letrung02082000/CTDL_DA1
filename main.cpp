#include"vector.h"

int main()
{
	//Cong
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
	cout << "Nhap toa do vector:" << endl;
	cin >> nhan;
	cout << "Nhap so Alpha:";
	cin >> alpha;
	nhan.multiply(alpha);
	cout << "Ket qua:";
	cout << nhan << endl;
	system("pause");
	return 0;
}