#include <iostream>
#include <string>
using namespace std;

class Node{
	private:
	Node* left;
	Node* right;
	int data;
	
	public:
	Node(int);
	~Node();
	void insert(int);
	void delet(int);
	void search(int);
	void traverse(int);
};

Node::Node(int value){ 
	this->data=value;
	this->left=NULL;
	this->right=NULL;
}
	
void Node::insert(int value){
	if(value > this->data){
		if(this->right==NULL){
			Node* _new = new Node(value);
			this->right=_new;
		}
		else{this->right->insert(value);}
	}
	else if(value < this->data){
		if(this->left==NULL){
			Node* _new = new Node(value);
			this->left=_new;
		}
		else{this->left->insert(value);}
	}
}

void Node::delet(int value){ //incomplete
	if(this->data==value){
		cout << "deleted" << endl;
	}
}

void Node::traverse(int option){
	switch(option){
		case 1: //inorder
			cout << this->data << endl;
			if (this->left!=NULL) this->left->traverse(1);
			if (this->right!=NULL) this->right->traverse(1);
			break;
		case 2: //preorder
			if (this->left!=NULL) this->left->traverse(2);
			cout << this->data << endl;
			if (this->right!=NULL) this->right->traverse(2);
			break;
		case 3: //postorder
			if (this->left!=NULL) this->left->traverse(3);
			if (this->right!=NULL) this->right->traverse(3);
			cout << this->data << endl;
			break;
		default: 
			cout << "wrong input" << endl;
			break;
	}
}

void Node::search(int value){
	if(this->data==value) cout << "found " << value << endl;
	if(this->data < value) {this->right->search(value);}
	if(this->data > value) {this->left->search(value);}
}

int main() {
	Node* root = new Node(7);
	for(int i=1; i<10; i++){root->insert(i);}
	cout << "inorder traversal" << endl; root->traverse(1);
	cout << "preorder traversal" << endl; root->traverse(2);
	cout << "postorder traversal" << endl; root->traverse(3);
	root->search(5); 
	root->delet(5);
	return 0;
}
