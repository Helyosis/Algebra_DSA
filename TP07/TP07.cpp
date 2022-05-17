#include "btree.h"
#include <iostream>

btree Task01() {
    btree a("a");

    a.insert_left(a.root(), "b");
    a.insert_right(a.root(), "c");

    node* c = a.get_right_child(a.root());
    a.insert_right(c, "d");

    node* d = c->right_child;
    a.insert_left(d, "e");
    a.insert_right(d, "f");

    node* e = d->left_child;
    a.insert_left(e, "g");
    a.insert_right(e, "h");

    node* f = d->right_child;
    a.insert_right(f, "i");

    return a;
}

void Task02() {
    btree a = Task01();
    a.inorder(a.root());
}

void Task03() {
    btree a = Task01();
    a.preorder(a.root());
}

void Task04() {
    btree a = Task01();
    a.postorder(a.root());
}

void Task06() {
    btree a = Task01();
    a.bfs(a.root());
}

void Task07() {
    btree a = Task01();
    a.print(a.root());
}

void Task09() {
    btree perfect_tree("7");

    node* n = perfect_tree.root();
    perfect_tree.insert_left(n, "6");

    n = n->left_child;
    perfect_tree.insert_left(n, "5");

    n = n->left_child;
    perfect_tree.insert_left(n, "4");

    n = n->left_child;
    perfect_tree.insert_left(n, "3");

    n = n->left_child;
    perfect_tree.insert_left(n, "2");

    n = n->left_child;
    perfect_tree.insert_left(n, "1");

    perfect_tree.postorder(perfect_tree.root());
}

int main()
{
    Task09();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
