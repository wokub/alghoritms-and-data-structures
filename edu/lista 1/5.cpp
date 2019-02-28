#include <iostream>

struct lnode {
    int key;
    lnode *next;

    lnode(int value, lnode *l = nullptr) {
        key = value;
        next = l;
    }
};

int nty(int n, lnode *l) {
    int m = 1;
    while (l != nullptr) {  // unikamy exception
        if (m != n){
            m++;
            l = (*l).next;    // zwracamy next
        }
        else
            return (*l).key;  // zwracamy key, znajduj¹cy siê w struct lnode
    }
    return 0;
}

int main() {

    lnode trzy(3);
    lnode dwa(2, &trzy);
    lnode jeden(1, &dwa);

    std::cout << nty(1, &jeden) << std::endl;
    std::cout << nty(2, &jeden) << std::endl;

}
