
#include <iostream>
using namespace std;


#include "BinaryTree.h"
#include "LinkedList.h"
#include "SingleList.h"

Tree::Trees tournament;

void Game(char Commands[][20], int n) {
    int i, j, p1, p2, k;

    Tree::Elem* temp;
    for (k = 0; k < 2; k++) {
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                temp = new Tree::Elem;
                if (k == 0) {
                    strcpy_s(temp->Name, Commands[i]);
                    strcpy_s(temp->Opponent, Commands[j]);
                }
                else {
                    strcpy_s(temp->Name, Commands[j]);
                    strcpy_s(temp->Opponent, Commands[i]);
                }

                p1 = rand() % 6;
                p2 = rand() % 6;

                if (p1 > p2) {
                    temp->ownerPoints = 3;
                    temp->oppPoints = 0;
                }
                else if (p1 == p2) {
                    temp->ownerPoints = 1;
                    temp->oppPoints = 1;
                }
                else {
                    temp->ownerPoints = 0;
                    temp->oppPoints = 3;
                }
                sprintf_s(temp->Match, " %d : %d ", p1, p2);
                tournament.Insert(temp);
            }
        }
    }
}

void TestLinkedList() {
    List::LinkedList a;
    a.push_front(1);
    a.push_front(2);
    a.push_back(3);
    a.insert(1, 4);
    a.show();
    a.erase(1);
    a.pop_back();
    a.pop_front();
    a.show();
}

void TestSingleList(){
    List::SingleList* a = nullptr;
    List::List b;
    b.Add(1, a);
    b.Add(2, a);
    b.Add(3, a);
    b.Print();
    cout << b.GetCount() << endl;
    cout << b.GetFirst() << endl;
    cout << b.GetLast() << endl;
    b.Clear();
    b.Print();



}

int main()
{
    const int n = 4;
    char Commands[4][20]{
        "A",
        "B",
        "C",
        "D"
    };
    Game(Commands, n);
    tournament.Print(tournament.GetRoot());

    cout << "\n\n";
    TestLinkedList();
    cout << "\n\n";
    TestSingleList();
}

