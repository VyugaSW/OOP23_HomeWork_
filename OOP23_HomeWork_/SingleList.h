#pragma once
#include <iostream>

using namespace std;
namespace List {


	class SingleList {
		int a;
		SingleList* ptr;
		friend class List;
	};

	class List {
		SingleList* sList; // êîðåíü ñïèñêà
		int count = 0; // êîë-âî óçëîâ ñïèñêà
		SingleList* Prev(SingleList*);

	public:
		List() { sList = nullptr; }
		int GetCount() { return count; }
		bool IsEmpty() { return sList == nullptr; }

		int GetValue(SingleList* s) { return s->a; }
		void SetValue(SingleList* s, int val) { s->a = val; }

		SingleList* GetFirst() { return sList; }

		SingleList* GetLast();
		void Clear();
		SingleList* Next(SingleList*);
		SingleList* Add(int, SingleList*);
		SingleList* Delete(SingleList*);
		void Print();
		void Swap(SingleList*, SingleList*);
	};

	SingleList* List::Add(int n, SingleList* s = nullptr) {
		SingleList* elem = new SingleList();
		elem->a = n;
		count++;
		if (s == nullptr) {
			if (sList == nullptr) {
				elem->ptr = nullptr;
				sList = elem;
			}
			else {
				elem->ptr = sList;
				sList = elem;
			}
			return elem;
		}
		elem->ptr = s->ptr;
		sList->ptr = elem;
		return elem;
	}
	SingleList* List::Delete(SingleList* s) {
		if (s == nullptr) return nullptr;
		count--;

		if (s == sList) {
			sList = s->ptr;
			delete s;
			return sList;
		}

		SingleList* s2 = Prev(s);
		s2->ptr = s->ptr;
		delete s;
		return s2;
	}
	SingleList* List::Next(SingleList* s) {
		if (s->ptr == nullptr) return nullptr;
		return s->ptr;
	}
	SingleList* List::Prev(SingleList* s) {
		if (IsEmpty()) return nullptr;
		if (s == sList) return nullptr;
		SingleList* p = sList;
		while (p->ptr != s)
		{
			p = p->ptr;
		}
		return p;
	}
	SingleList* List::GetLast() {
		SingleList* s = sList;
		while (Next(s) != nullptr)
		{
			s = Next(s);
		}
		return s;
	}
	void List::Clear() {
		SingleList* s = sList;
		if (s == nullptr) return;
		do {
			SingleList* s2 = s;
			s = Next(s);
			delete s2;
		} while (s != nullptr);
		count = 0;
		sList = nullptr;
	}
	void List::Print() {
		if (IsEmpty()) { return; }
		SingleList* s = sList;
		do {
			cout << GetValue(s) << " ";
			s = Next(s);
		} while (s != nullptr);
		cout << endl;
	}
	void List::Swap(SingleList* s, SingleList* s2) {
		if (s == nullptr || s2 == nullptr) return;
		if (s == s2) return;
		if (s2->ptr == s) {
			SingleList* t = s;
			s = s2;
			s2 = t;
		}
		SingleList* prev1 = Prev(s);
		SingleList* prev2 = Prev(s2);
		SingleList* next1 = Next(s);
		SingleList* next2 = Next(s2);
		if (next1 == s2) {
			if (prev1 != nullptr) prev1->ptr = s2;
			else sList = s2;
			s2->ptr = s;
			s->ptr = next2;
			return;
		}
		if (prev1 != nullptr) prev1->ptr = s2;
		else sList = s2;
		if (prev2 != nullptr) prev2->ptr = s;
		else sList = s;

		s->ptr = next1;
		s2->ptr = next2;
	}


}