#pragma once
#include "TList.h"

class TPolinom : public THeadList<TMonom>
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
		TMonom m(0, -1);
		pHead->val = m;
		for (TP.Reset(); !TP.IsEnd(); TP.GoNext()) {
			TMonom monom = TP.GetCurr();
			InsLast(monom);
		}
	}

	TPolinom& operator+ (TPolinom& TP);

	TPolinom& operator= (TPolinom& TP) {
		DelList();
		for (TP.Reset(); !TP.IsEnd(); TP.GoNext()) {
			TMonom monom = TP.GetCurr();
			InsLast(monom);
		}
		return *this;
	}

	void AddMonom(TMonom _m) {
		pCurr = pFirst;
		while (_m.Index < pCurr->val.Index) {
			GoNext();
		}
		if (pCurr->val == _m) {
			if (_m.Coeff + pCurr->val.Coeff == 0) DelCurr();
			else pCurr->val.Coeff = _m.Coeff + pCurr->val.Coeff;
		}

	}

	friend ostream& operator<< (ostream& os, TPolinom& TP) {

	}
};

