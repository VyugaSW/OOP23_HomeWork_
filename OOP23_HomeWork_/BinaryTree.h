#pragma once
#include <iostream>
using namespace std;

namespace Tree {


	struct Elem {
		int ownerPoints;
		int oppPoints;
		char Match[10];
		char Name[20];
		char Opponent[20];

		Elem* left, * right, * parent;
	};

	class Trees {
		Elem* root;
	public:
		Trees() { root = nullptr; }
		~Trees() { Del(); }

		void Print(Elem* node);
		Elem* Search(Elem* node, char* key);
		Elem* Min(Elem* node);
		Elem* Max(Elem* node);
		Elem* Next(Elem* node);
		Elem* Prev(Elem* node);
		void Insert(Elem* node);
		void Del(Elem* node = 0);
		Elem* GetRoot();
	};

	void Trees::Print(Elem* node) {
		if (node != nullptr) {
			Print(node->left);
			cout << node->Name << endl
				<< node->Match << endl
				<< node->Opponent << endl;
			Print(node->right);
		}
	}
	Elem* Trees::Search(Elem* node, char* k) {
		while (node != nullptr && strcmp(k, node->Name) != 0) {
			if (strcmp(k, node->Name) < 0) node = node->left;
			else node = node->right;
		}
		return node;
	}
	Elem* Trees::Min(Elem* node) {
		if (node != nullptr)
			while (node->left != nullptr)
				node = node->left;
		return node;
	}
	Elem* Trees::Max(Elem* node) {
		if (node != nullptr)
			while (node->right != nullptr)
				node = node->right;
		return node;
	}
	Elem* Trees::Next(Elem* node) {
		Elem* y = nullptr;
		if (node != nullptr) {
			if (node->right != nullptr) return Min(node->right);

			y = node->parent;
			while (y != 0 && node == y->right)
			{
				node = y;
				y = y->parent;
			}
		}
		return y;
	}
	Elem* Trees::Prev(Elem* node) {
		Elem* y = nullptr;
		if (node != nullptr) {
			if (node->left != nullptr) return Min(node->left);

			y = node->parent;
			while (y != 0 && node == y->left)
			{
				node = y;
				y = y->parent;
			}
		}
		return y;
	}
	Elem* Trees::GetRoot() { return root; }
	void Trees::Insert(Elem* node) {
		node->left = nullptr;
		node->right = nullptr;

		Elem* y = nullptr;
		Elem* z = root;

		while (z != nullptr) {
			y = z;
			if (strcmp(node->Name, z->Name) < 0) z = z->left;
			else z = z->right;
		}
		node->parent = y;
		if (y == nullptr) root = node;
		else if (strcmp(node->Name, y->Name) < 0) y->left = node;
		else y->right = node;
	}
	void Trees::Del(Elem* node) {
		if (node != nullptr) {
			Elem* y, * z;

			if (node->left == nullptr || node->right == nullptr) y = node;
			else y = Next(node);

			if (y->left != 0) z = y->left;
			else z = y->right;

			if (z != nullptr) z->parent = y->parent;

			if (y->parent == nullptr) root = z;
			else if (y == y->parent->left) y->parent->left = z;
			else y->parent->right = z;

			if (y != node) {
				strcpy_s(node->Name, y->Name);
				strcpy_s(node->Opponent, y->Opponent);
				strcpy_s(node->Match, y->Match);
				node->oppPoints = y->oppPoints;
				node->ownerPoints = y->ownerPoints;
			}
			delete y;
		}
		else
			while (root != 0)
				Del(root);
	}


}