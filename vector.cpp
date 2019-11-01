#include"vector.h"

void vector::setVector(int i, float value){
	v[i] = value;
}

float vector::getVector(int i){
	return v[i];
}

vector::vector(){
	for (int i = 0; i < n;)	{
		v[i] = 0;
	}
}
/*
vector vector::add(vector other){
	vector c;
	for (int i = 0; i < n; i++){
		c.v[i] += v[i] + other.v[i];
	}
	return c;
}

vector vector::multiply(float alpha){
	vector c;
	for (int i = 0; i < n; i++){
		c.v[i] += alpha*v[i];
	}
	return c;
}
*/
ostream& operator<< (ostream& writer, vector &vt){
	writer << "(";
	for (int i = 0; i < vt.n; i++){
		writer << vt.v[i];
		if (i < (vt.n - 1))
			writer << ", ";
	}
	writer << ")";
	return writer;
}
istream& operator>>(istream& reader, vector &vt){
	cout << "Nhap so phan tu cua vector: ";
	reader >> vt.n;
	for (int i = 0; i < vt.n; i++){
		cout << "Nhap phan tu thu " << i + 1 << " cua vector: ";
		reader >> vt.v[i];
	}
	return reader;
}

vector vector::operator+(const vector& vt)
{
	if (n != vt.n)
	{
		cout << "Khong thuc hien duoc phep cong." << endl;
	}
	else
	{
		vector c;
		c.n = vt.n;
		for (int i = 0; i < vt.n; i++)

		{
			c.v[i] = v[i] + vt.v[i];
		}
		return c;
	}
}

void vector::multiply(const float alpha){
	for (int i = 0; i < n; i++){
		v[i] = v[i] * alpha;
	}
}