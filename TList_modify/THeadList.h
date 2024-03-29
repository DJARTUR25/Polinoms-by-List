/*#pragma once

#include "TList.h"
#include "TMonom.h"
#include <iostream>
using namespace std;

template <class T>
class THeadList :public TList<T> {
protected:
	TNode <T>* pHead;			// head (the zero element)
public:
	THeadList() {				// designer
		pHead = new TNode<T>;
		pHead = nullptr;
		pHead->pNext = pHead;
		pStop = pHead;
		pFirst = pHead;
		pPr = pHead;
		pCurr = pHead;
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
		pHead->pNext = pFirst;
	}

	void DelFirst() {
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}

	void InsLast(T elem) {
		TList<T>::InsLast(elem);
		pLast->pNext = pHead;
	}

	void DelLast() {
		TList<T>::DelLast();
		pLast->pNext = pHead;
	}

	void InsCurr(T elem) {
		TList<T>::InsCurr(elem);
	}

	void DelCurr() {
		TList<T>::DelCurr();
	}
};

*/