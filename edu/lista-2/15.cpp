#include <iostream>

using namespace std;

struct node {
    int x;
    node* left;
    node* right;
    node* parent;

    node(int _x, node* _l = NULL, node* _r = NULL, node* _p = NULL)
        :x(_x), left(_l), right(_r), parent(_p)
    {}
};

void insert(node *& t, int x) {
	node **t1 = &t;

	while(*t1) {
		if(x < (*t1) ->x) {
			t1 = &((*t1) ->left);
        } else
			t1 = &((*t1) ->right);
    }

	*t1 = new node(x);
}

int height(node* t) {
	int l = t ->left ? height(t ->left) : 0;
	int r = t ->right ? height(t ->right) : 0;
	
    return (l > r) ? (l + 1) : (r + 1); 
}

int main() {
    node *root = new node(0);

    insert(root, 4);
    insert(root, 6);
    insert(root, 3);
    insert(root, 9);

    cout << "Glebokosc: " << height(root) << endl;    

    return 0;
}