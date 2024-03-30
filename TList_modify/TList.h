#pragma once
#include <iostream>
#include <math.h>

using namespace std;

template <class T>
struct TNode {
	T val;
	TNode* pNext;
};

template <class T>
class TList
{
protected:
	TNode<T>* pFirst;		//indicator on first item (u need only this one in List, but for convenience we need the following)
	TNode<T>* pLast;	    //indicator on last item
	TNode<T>* pStop;		//indicator in last item which indicates in nowhere (for now)
	TNode<T>* pPr;			//indicator in previous item
	TNode<T>* pCurr;		//indicator in current item
	int pos, len;			//position and count of items in list
public: 
	TList() {						//designer
		pFirst = nullptr; 
		pStop = nullptr;
		pLast = pStop;
		pPr = pStop;
		pCurr = pFirst;
		pos = -1;
		len = 0;
	}

	TList(const TList<T>& l) {		//designer by copy
		TNode<T>* tmp = l.pFirst, *curr;
	//pFirst = pLast = nullptr;
		while (tmp != nullptr) {
			curr = new TNode<T>;
			curr->val = tmp->val;
			if (pFirst == nullptr) {
				pFirst = curr;
				pLast = curr;
			}
			else {
				pLast->pNext = curr;
				pLast = curr;
			}
			tmp = tmp->pNext;
		}
		len = l.len;
		pos = -1;
		pStop = nullptr;
	}

	void DelList() {					//deleting the list
		TNode<T>* tmp = pFirst;
		while (pFirst != pStop) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}

	~TList() { DelList(); }				//destructor

	void Reset() {						//jump to first item
		pCurr = pFirst;
		pPr = pStop;
		pos = 0;
	}

	void GoNext() {						//jump to next item
		if (pCurr != pStop) {
			pPr = pCurr;
			pCurr = pCurr->pNext;
			pos++;
		}
		else
			throw ("The end of list!\n");
	}

	bool IsEnd() {						//checking that the item is last
		return (pStop == pCurr);
	}

	void InsFirst(T _val) {				//insert before the first one
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pFirst;
		pFirst = tmp;
		len++;
	}

	void InsLast(T _val) {				//insert after the last one
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pStop;
		pLast->pNext = tmp;
		pLast = tmp;
		len++;
	}

	void InsCurr(T _val) {				//insert before the cuurent one
		if (pCurr == pFirst) InsFirst(_val);
		else {
			TNode<T>* tmp = new TNode<T>;
			tmp->val = _val;
			pPr->pNext = tmp;
			tmp->pNext = pCurr;
			pPr = tmp;
			len++;
			pos++;
		}
	}

	void DelFirst() {					//deleting the first item
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		pPr = nullptr;
		delete tmp;
		len--;
	}

	void DelCurr() {					//deleting the current item
		if (pCurr != pStop) {
			if (pCurr == pFirst)
				DelFirst();
		}
		TNode<T>* tmp = pCurr;
		pCurr = pCurr->pNext;
		pPr->pNext = pCurr;
		delete tmp;
		len--;
	}

	void SetPos(int _pos) {				//move pCurr to item with the received position
		int pos = _pos;
		pCurr = pFirst;
		for (int i = 0; i < pos; i++) {
			pPr = pCurr;
			pCurr = pCurr->pNext;
		}
	}

	T GetCurr() {						//get value of current element
		return pCurr->val; 
	}

};

/*
struct TMonom {
	double Coeff;				//the monome coefficient
	int Index;					//index (powers)
public:
	TMonom() {
		Coeff = 0;
		Index = 1;
	}

	TMonom(int a, int b) {
		Coeff = a;
		Index = b;
	}

	bool operator == (TMonom& TM) {
		if (TM.Coeff == Coeff) {
			if (TM.Index == Index)
				return 1;
		}
		return 0;
	}

	bool operator != (TMonom& TM) {
		if (*this == TM) return 0;
		else return 1;
	}
};
*/

/*template <class T>
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

	void InsFirst(T elem) override {
		TList<T>::InsFirst(elem);
		pHead->pNext = pFirst;
	}

	void DelFirst() override {
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}

	void InsLast(T elem) override {
		TList<T>::InsLast(elem);
		pLast->pNext = pHead;
	}

	void DelLast() override{
		TList<T>::DelLast();
		pLast->pNext = pHead;
	}

	void InsCurr(T elem) override{
		TList<T>::InsCurr(elem);
	}

	void DelCurr() override{
		TList<T>::DelCurr();
	}
}; */