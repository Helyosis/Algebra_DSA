#include "btree.h"
#include <iostream>
#include <queue>

using namespace std;

/*************** PRIVATNE METODE ****************/

node* btree::create_new_node(string element) 
{
	node* new_node = new node;
	new_node->element = element;
	new_node->left_child = nullptr;
	new_node->right_child = nullptr;
	
	return new_node;
}

/*************** JAVNE METODE ****************/

btree::btree(string element) 
{
	root_node = create_new_node(element);
}

void btree::insert_left(node* parent, string element) 
{
	parent->left_child = create_new_node(element);
}

void btree::insert_right(node* parent, string element) 
{
	parent->right_child = create_new_node(element);
}

node* btree::root() 
{
	return root_node;
}

node* btree::get_left_child(node* parent) 
{
	return parent->left_child;
}

node* btree::get_right_child(node* parent) 
{
	return parent->right_child;
}

void btree::inorder(node* current) {
	if (current != nullptr) {
		inorder(current->left_child);
		cout << current->element;
		inorder(current->right_child);
	}
}

void btree::preorder(node* current) {
	if (current != nullptr) {
		cout << current->element;
		preorder(current->left_child);
		preorder(current->right_child);
	}
}

void btree::postorder(node* current) {
	if (current != nullptr) {
		postorder(current->left_child);
		postorder(current->right_child);
		cout << current->element;

	}
}

void btree::bfs(node* current) {
	queue<node*> q;
	q.push(current);

	while (!q.empty()) {
		node* n = q.front(); q.pop();
		cout << n->element;
		if (n->left_child != nullptr)
			q.push(n->left_child);

		if (n->right_child != nullptr)
			q.push(n->right_child);
	}
}

void btree::print(node* current, int depth) {
	if (current == nullptr) {
		return;
	}
	
	for (int i = 4; i < depth; ++i) cout << " ";
	if (depth > 0) cout << "|---";
	cout << current->element << endl;

	print(current->left_child, depth + 4);
	print(current->right_child, depth + 4);
}