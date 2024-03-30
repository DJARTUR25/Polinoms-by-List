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
		if (pFirst == nullptr) {
			pFirst = tmp;
			pFirst->pNext = pStop;
			pLast = pFirst;
			pCurr = pFirst;
			len++; pos++;
		}
		else {
			if (pFirst == pLast) {
				tmp->pNext = pFirst;
				pCurr = pFirst;
				pLast = pCurr;
				pFirst = tmp;
				pPr = pFirst;
				len++; pos++;
			}
			else {
				tmp->pNext = pFirst;
				pFirst = tmp;
				len++; pos++;
			}
		}
	}

	void InsLast(T _val) {				//insert after the last one
		if (len == 0) InsFirst(_val);
		else {
			TNode<T>* tmp = new TNode<T>;
			tmp->val = _val;
			tmp->pNext = pStop;
			pLast->pNext = tmp;
			pLast = tmp;
			len++;
		}
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
		if (len == 0)
			throw ("Empty list!\n");
		else {
			TNode<T>* tmp = pFirst;
			if (pCurr == pFirst) {
				pCurr = pCurr->pNext;
				pFirst = pFirst->pNext;
				delete tmp;
				len--;
			}
			else {
				if (pFirst == pPr) {
					pFirst = pFirst->pNext;
					delete tmp;
					pPr = nullptr;
					len--; pos--;

				}
				else {
					pFirst = pFirst->pNext;
					delete tmp;
					len--; pos--;
				}
			}
		}
	}

	void DelLast() {					//deleting the last item
		if (len == 0) 
			throw ("Empty list!\n");
		else {
			if (pLast == pFirst)
				DelFirst();
			else {
				if (pCurr == pLast)	{
					TNode<T>* tmp = pCurr;
					SetPos(pos - 1);
					delete tmp;
					pCurr->pNext = pStop;
					pLast = pCurr;
					len--;
				}
				else {
					int posPcur = pos;
					Reset();
					while (pos != len - 1)
						GoNext();
					pCurr->pNext = pStop;
					delete pLast;
					pLast = pCurr;
					SetPos(posPcur);
					len--;
				}
			}
		}
	}

	void DelCurr() {					//deleting the current item
		if (len == 0)
			throw ("Empty list!\n");
		if (pCurr == pFirst)
			DelFirst();
		else {
			if (pCurr == pLast)
				DelLast();
			else
				if (pCurr != pStop) {
					TNode<T>* tmp = pCurr;
					pCurr = pCurr->pNext;
					pPr->pNext = pCurr;
					delete tmp;
					len--;
				}

		}
	}


	void SetPos(int _pos) {				//move pCurr to item with the received position
		pos = _pos;
		pCurr = pFirst;
		for (int i = 0; i < pos; i++) {
			pPr = pCurr;
			pCurr = pCurr->pNext;
		}
	}

	T GetCurr() {						//get value of current element
		return pCurr->val; 
	}

	void Print() {
		if (pFirst == pStop) cout << "			List is EMPTY" << endl;
		else {
			cout << "			Your list: " << endl;
			int p = pos;
			if (pFirst == pLast)
				cout << pFirst->val;
			else {
				Reset();
				cout << pCurr->val;
				GoNext();
				while (!IsEnd()) {
					cout << "  --->  " << pCurr->val;
					GoNext();
				}
				SetPos(p);
			}
		}

		cout << endl << endl;
		cout << "		Length of the list = " << len << endl;
	}

};