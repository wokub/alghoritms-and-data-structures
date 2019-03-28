#include <iostream>
#include <queue>

class node {
    public:
    	int x;
    	node *left;
    	node *right;

    	node(int x0, node *l = nullptr, node *r = nullptr)
        	: x(x0), left(l), right(r) {}
};

void insert(node *&t, int x) {
    node **t1 = &t;
	
    while (*t1) {
        if (x < (*t1) ->x)
            t1 = &(( *t1 ) ->left);
        else
            t1 = &(( *t1 ) ->right);
    }
    *t1 = new node(x);
}

int poziom(node* root, int klucz, int level = 1) {

    while (root != nullptr && root ->x != klucz) {
	level++;
		
	if (klucz < root ->x) {
	    root = root ->left;
	} else {
            root = root ->right;
	}
    }
	
    if(root == nullptr) {
        return 0;
    } else 
	return level;
}

int main() {
    node* root = new node(5);
    insert(root, 1);
    insert(root, 8);
    insert(root, 3);
    insert(root, 0);
    insert(root, 9);

    std::cout << "Poziom 5: " << poziom(root, 5) << std::endl;
    std::cout << "Poziom 1: " << poziom(root, 1) << std::endl;
    std::cout << "Poziom 8: " << poziom(root, 8) << std::endl;
    std::cout << "Poziom 3: " << poziom(root, 3) << std::endl;
    std::cout << "Poziom 0: " << poziom(root, 0) << std::endl;
    std::cout << "Poziom 9: " << poziom(root, 9) << std::endl;
    std::cout << "Poziom 7: " << poziom(root, 7) << std::endl;
}
