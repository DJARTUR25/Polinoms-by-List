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
		TMonom pm, qm, rm;
		this->Reset();
		while (1) {
			pm = GetMonom();
			qm = TP.GetMonom();
			if (pm.Index > qm.Index) {
				InsCurr(qm);
				TP.GoNext();
			}
			else if (pm.Index > qm.Index) {
				GoNext();
				TP.GoNext();
			}
			else {
				if (pm.Index == -1)
					break;
				pm.Coeff += qm.Coeff;
				if (pm.Index != 0) {
					GoNext();
					TP.GoNext();
				}
				else {
					DelCurr();
					TP.GoNext();
				}
			}
		}
		return *this;
	}

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

	/*friend ostream& operator<< (ostream& os, TPolinom& TP) {

	}*/
};

