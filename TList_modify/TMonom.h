#pragma once

#include <iostream>
using namespace std;


class TMonom
{
private:
	double Coeff;
	int idx;

public:

	TMonom() {
		Coeff = 0;
		idx = 0;
	}

	void SetCoeff(double _cf) { Coeff = _cf; }

	void SetIndex(int _idx)	{ idx = _idx; }

	int GetIndex() { return idx; }

	double GetCoeff() { return Coeff; }

	TMonom(double _cf, int _idx)	{
		Coeff = _cf;
		idx = _idx;
	}

	void operator= (TMonom& monom) {
		Coeff = monom.Coeff;
		idx = monom.idx;
	}

	friend ostream& operator<< (ostream& os, TMonom mon) {
		os << mon.Coeff << endl;
		os << "			" << endl;
		os << mon.idx << "		";
		return os;
	}

	bool operator== (TMonom monom) {
		if ((idx == monom.idx) && (Coeff == monom.Coeff)) return 1;
		else return 0;
	}

};

