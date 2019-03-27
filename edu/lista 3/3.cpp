#include <iostream>

using namespace std;

struct lnode {
    int key;
    lnode *next;
    lnode(int n=0, lnode *l = NULL) : key(n), next(l) {};
};

void print(lnode *L) {
    while (L != NULL)
    {
        cout << L->key << "  ";
        L = L->next;
    }
    cout << endl;
}

void insertion_sort(lnode *&L) {

    if (L && L->next) {
        lnode* sortedL = NULL;
        lnode* unsortedL = L;

        while (unsortedL) {
            lnode* value = unsortedL;
            unsortedL = unsortedL ->next;

            if (!sortedL || value->key <= sortedL->key) {
                value ->next = sortedL;
                sortedL = value;
            } else {

                lnode* curSorted = sortedL;

                while (curSorted) {
                    if (!curSorted ->next || value ->key < curSorted ->next ->key) {
                        value ->next = curSorted ->next;
                        curSorted ->next = value;
                        break;
                    }

                    curSorted = curSorted->next;
                }
            }
        }

        L = sortedL;
    }
}

int main() {
    lnode *l = NULL;

	l = new lnode(7, l);
	l = new lnode(5, l);
    l = new lnode(2, l);
	l = new lnode(3, l);
    l = new lnode(2, l);
	l = new lnode(1, l);
	l = new lnode(9, l);
    cout << "Lista przed posortowaniem:\n ";
    print(l);
    insertion_sort(l);
    cout << "Lista po posortowaniu:\n ";
    print(l);

    return 0;
}
