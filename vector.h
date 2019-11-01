#pragma once
#include<iostream>
using namespace std;
#define max 100

class vector
{
private:
	int n;
	float v[max];
public:
	void setVector(int i, float value);
	float getVector(int i);
	friend ostream& operator<< (ostream& writer, vector &vt);
	friend istream& operator>>(istream& reader, vector &vt);
public:
	vector();
public:
	vector operator+(const vector& vt);
	//vector operator=(const vector& vt);
	//vector operator*(const vector& vt);
	void multiply(const float alpha);
};
