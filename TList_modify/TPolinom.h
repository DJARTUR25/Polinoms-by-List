#pragma once
#include "TList.h"
#include "TMonom.h"
#include "THeadList.h"
#include <vector>

class TPolinom :public THeadList<TMonom>
{
public:
	TPolinom(int monoms[][2] = NULL, int km = 0) {
		TMonom tmp(0, 1);
		pHead->val = tmp;
		for (int i = 0; i < km; i++) {
			TMonom monom((double)monoms[i][0], monoms[i][1]);
			InsLast(monom);
		}
	}

	TPolinom(TPolinom& TP) {
		TMonom tmp(0, -1);
		pHead->val = tmp;
		for (TP.Reset(); !TP.IsEnd(); TP.GoNext()) {
			TMonom monom = TP.GetCurr();
			InsLast(monom);
		}
	}

	TMonom GetMonom() {
		TMonom monom = GetCurr();
		return monom;
	}

	TPolinom& operator+ (TPolinom& TP) {
		TPolinom res(*this);
		res.Reset();
		TP.Reset();
		while (res.pCurr != res.pStop && TP.pCurr != TP.pStop)
		{
			if (res.GetCurr().GetIndex() < TP.GetCurr().GetIndex())
			{
				res.InsCurr(TP.GetCurr());
				TP.GoNext();
			}
			else
				if (res.GetCurr().GetIndex() > TP.GetCurr().GetIndex())
				{
					res.GoNext();
				}
				else
				{
					res.pCurr->val.SetCoeff(TP.pCurr->val.GetCoeff() + res.pCurr->val.GetCoeff());
					if (res.pCurr->val.GetCoeff() != 0)
					{
						TP.GoNext();
						res.GoNext();
					}
					else
					{
						res.DelCurr();
						TP.GoNext();
					}
				}

		}
		return res;
	}

	TPolinom& operator= (TPolinom& TP) {
		DelList();
		for (TP.Reset(); !TP.IsEnd(); TP.GoNext()) {
			TMonom monom = TP.GetCurr();
			InsLast(monom);
		}
		return *this;
	}

	TPolinom& operator* (double _Const) {
		TPolinom res(*this);
		if (_Const == 0) res.DelList();
		else {
			res.Reset();
			while (!res.IsEnd()) {
				res.pCurr->val.SetCoeff(res.pCurr->val.GetCoeff() * (_Const));
				res.GoNext();
			}
		}
		return res;
	}

	TPolinom operator- (TPolinom& TP) {
		return (*this + TP * (-1));
	}

	friend ostream& operator<< (ostream& os, TPolinom& TP)
	{
		TP.Reset();
		int x, y, z;
		TMonom TM = TP.GetCurr(); 
		double idx = TM.GetIndex();
		
		x = TP.GetCurr().GetIndex() / 100;
		y = TP.GetCurr().GetIndex() % 100 / 10;
		z = TP.GetCurr().GetIndex() % 10;
		os << TP.GetCurr().GetCoeff() << "(x^" << x << "y^" << y << "z^" << z << ")";
		TP.GoNext();
		while (!TP.IsEnd())
		{
			x = TP.GetCurr().GetIndex() / 100;
			y = TP.GetCurr().GetIndex() % 100 / 10;
			z = TP.GetCurr().GetIndex() % 10;
			if (TP.GetCurr().GetCoeff() > 0)
				os << "+";

			os << TP.GetCurr().GetCoeff() << "(x^" << x << "y^" << y << "z^" << z << ")";
			TP.GoNext();
		}
		return os;
	}

	void AddMonom(TMonom _m) {
		if (pCurr == nullptr)
			InsFirst(_m);
		pCurr = pFirst;
		while (_m.GetIndex() < pCurr->val.GetIndex())
			GoNext();
		if (pCurr->val == _m)
		{
			if (pCurr->val.GetCoeff() + _m.GetCoeff() == 0)
				DelCurr();
			else
				pCurr->val.SetCoeff(_m.GetCoeff());
		}
		else
			InsCurr(_m);
	}

	void AddPolinom() {
		cout << "			Enter your polynomial." << endl;
		cout << "			First, enter the coefficient, and then the index of the monome you are entering." << endl;
		cout << "			To complete the input, enter 0" << endl;

		int Coeff, Index;
		cin >> Coeff >> Index;
		if (Index < 100) throw ("Wrong index!");
		while (Index != 0) {
			TMonom new_monom(Coeff, Index);
			AddMonom(new_monom);
			cin >> Coeff >> Index;
			if ((Coeff == 0) || (Index == 0)) 
				break;
			if (Index < 100) throw ("Wrong index!");
		}
	}

	void Print(vector<TPolinom> v, int CurrPos) {
		cout << "			Your polynomial vector: " << endl;
		for (int i = 0; i < CurrPos; i++) {
			cout << "|" << i + 1 << "| " << v[i] << endl;
		}
	}
};

