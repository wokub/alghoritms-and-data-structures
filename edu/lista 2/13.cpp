#include <iostream>

using namespace std;

struct node {
    int x;
    node* left;
    node* right;

    node(int _val, node* _l = NULL, node* _r = NULL)
        :x(_val), left(_l), right(_r)
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

void inorder_do(node * t, void f(node *)) {
    node *temp = t;

    if(temp) {					// jeśli false, zakończ rekurencję
        inorder_do(temp ->left, f);		// przejście rekurencyjne przez lewe poddrzewo
        f(temp);				// węzeł wskazany przez temp
        inorder_do(temp ->right, f);		// przejście rekurencyjne przez prawe poddrzewo
    }
}

void print(node *t) {
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
