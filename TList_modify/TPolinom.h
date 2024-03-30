#pragma once
#include "TList.h"
#include "TMonom.h"
#include "THeadList.h"

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

	/*friend ostream& operator<< (ostream& os, TPolinom& TP) {

	}*/
};

