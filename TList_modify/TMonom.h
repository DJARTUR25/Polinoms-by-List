#pragma once

#include <iostream>
using namespace std;


class TMonom
{
private:
	double Coeff;
	int Index;
public:

	TMonom() {
		Coeff = 0;
		Index = 0;
	}

	void SetCoeff(double _cf) { Coeff = _cf; }

	void SetIndex(int _Index)	{ Index = _Index; }

	int GetIndex() { return Index; }

	double GetCoeff() { return Coeff; }

	TMonom(double _cf, int _Index)	{
		Coeff = _cf;
		Index = _Index;
	}

	void operator= (TMonom& monom) {
		Coeff = monom.Coeff;
		Index = monom.Index;
	}

	friend ostream& operator<< (ostream& os, TMonom mon) {
		os << mon.Coeff << endl;
		os << "			" << endl;
		os << mon.Index << "		";
		return os;
	}

	bool operator== (TMonom monom) {
		if ((Index == monom.Index) && (Coeff == monom.Coeff)) return 1;
		else return 0;
	}

};

