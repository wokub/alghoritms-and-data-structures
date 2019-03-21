#include <iostream>

struct lnode {
    int key;
    lnode *next;
};

int nty(int n, lnode * l) {
    if(!(l -> next) && n > 0) {  
        return 0;
    } else {
        if(n == 0) { return l->key; }
               
        nty(n-1, l->next);
    }   
}
  
int main() {
    lnode first;
    lnode second;
    lnode third;

    first.key = 1;
    second.key = 2;
    third.key = 3;

    first.next = NULL;
    second.next = &first;
    third.next = &second;

    std::cout << nty(2, &third) << std::endl;
    
    return 0;
}