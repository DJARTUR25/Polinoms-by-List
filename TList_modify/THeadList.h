#pragma once

#include "TList.h"
#include "TMonom.h"
#include <iostream>

using namespace std;

template <class T>
class THeadList:public TList<T> {
protected:
	TNode <T>* pHead;			// head (the zero element)
public:
	THeadList() {				// designer
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pStop = pLast = pFirst = pPr = pCurr = nullptr;
		len = 0;
		pos = -1;
	}

	THeadList(const THeadList<T>& HL) {		//designer by copy
		pHead = nullptr;
		TNode<T>* tmp = HL.pFirst;
		TNode<T>* tmp2;
		while (tmp != nullptr) {
			tmp2 = new TNode<T>;
			tmp2->val = tmp->val;
			if (HL.pHead == HL.pHead)
				pFirst = pLast = pStop = pHead = tmp2;
			else {
				pLast->pNext = tmp2;
				pLast = tmp2;
				pHead->pNext = pFirst;
			}
			tmp = tmp->pNext;
		}
		len = HL.len;
		pos = -1;
		pStop = pHead;
	}

	~THeadList() {
		TList<T>::DelList();
		delete pHead;
	}

	void InsFirst(T elem) {
		TList<T>::InsFirst(elem);
		pLast->pNext = pHead;
		pHead->pNext = pFirst;
		pStop = pHead;
	}

	void DelFirst() {
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}

	void InsLast(T elem) {
		TList<T>::InsLast(elem);
		pLast->pNext = pHead;
		pStop = pHead;
		pHead->pNext = pFirst;
	}

	void DelLast() {
		TList<T>::DelLast();
		pLast->pNext = pHead;
		pStop = pHead;
		pHead->pNext = pFirst;
	}

	void InsCurr(T elem) {
		TList<T>::InsCurr(elem);
		pHead->pNext = pFirst;
	}

	void DelCurr() {
		TList<T>::DelCurr();
		if (pCurr == pFirst) pHead->pNext = pFirst;
	}

	void PrintHeadList() {
		if (pFirst == pStop) cout << "		The headlist is EMPTY!\n";
		else {
			cout << "		Your headlist: " << endl;
			int p = pos;
			if (pFirst != pLast) {
				Reset();
				cout << pFirst->val;
				GoNext();
				while (!IsEnd()) {
					cout << "  --->  " << pCurr->val;
					GoNext();
				}
				SetPos(p);
			}
			else {
				cout << pFirst->val;
			}
		}
		cout << endl << endl;
		cout << "		Lenhtg of your headlist is: " << len << endl;
		if (pCurr != nullptr)
			cout << "		Current item is: " << pCurr->val << " , its position is: " << pos << endl;
	}
};
