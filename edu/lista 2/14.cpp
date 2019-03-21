#include <iostream>
#include <stack>

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

void inorder_do(node* t, void f(node* x)) {
	
    if (!t) { return;}
    
    bool done = false;
	node* temp = t;
	std::stack<node*> s;
	
	while (!done) {
		if (temp != NULL) {
			s.push(temp);
			temp = temp ->left;
		} else {
			if (!s.empty()) {
				temp = s.top();
				s.pop();
				
				f(temp);
				temp = temp->right;
			} else
				done = true;
		}
	} 
}

void print(node * t) {
    node *temp = t;

    if(temp) {
        cout << temp ->x << endl;   
    }
}

int main() {
    node *root = new node(0);

    insert(root, 4);
    insert(root, 6);
    insert(root, 3);
    insert(root, 9);

    inorder_do(root, [](node* x) {print(x);} );
    return 0;
}