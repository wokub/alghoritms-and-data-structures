#include <iostream>

using namespace std;

struct lnode {
    int key;
    lnode *next;

    lnode(int n=0, lnode *l = NULL) : key(n), next(l) {};
};

void insertion_sort(lnode *&L) {

    if (L && L->next) {
        lnode* sorted = NULL;
        lnode* unsorted = L;

        while (unsorted) {
            lnode* val = unsorted; 
            unsorted = unsorted ->next;

            if (!sorted || val ->key <= sorted ->key) {
                val ->next = sorted;
                sorted = val;
            } else {
                lnode* current = sorted;

                while (current) {
                    if (!current ->next || val ->key < current ->next ->key) {
                        val ->next = current ->next;
                        current ->next = val;                        
                        break;
                    }
                    current = current ->next;
                }
            }
        }
        
        L = sorted;
    }
}

void print(lnode *L) {

    while (L != NULL) {
        cout << L ->key << "  ";

        L = L ->next;
    }

    cout << endl;
}

int main() {
    	lnode *l = NULL;

    	l = new lnode(3, l);
	l = new lnode(2, l);
        l = new lnode(1, l);
    	l = new lnode(3, l);
        l = new lnode(2, l);
        l = new lnode(1, l);
        l = new lnode(0, l);

	insertion_sort(l);
    	print(l);

    	return 0;
}
