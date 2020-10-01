#include<bits/stdc++.h>
using namespace std;

struct node {
    int val, pri, size;
    node* l, *r;
    node(int v) { val = v; pri = rand(); size = 1; }
    
};

int size(node* t) {return t?t->size:0;}
void upd(node* &t) { if (t) t->size = size(t->l) + size(t->r) + 1; }
void inorder (node* &t) {
    if (!t) return;
    inorder(t->l);
    printf("%d ", t->val);
    inorder(t->r);
}

void merge (node* &t, node* a, node* b) {
    if (!a) return void(t = b);
    if (!b) return void(t = a);
    if (a->pri > b->pri) merge(a->r, a->r, b), t = a;
    else merge(b->l, b->l, a), t = b;
    upd(t);
}

void split(node* &l, node* &r, node* t, int val) { // <= val at l
    if (!t) return void(l = r = NULL);
    if (t->val <= val) split(t->r, r, t->r, val), l = t;
    else split(l, t->l, t->l, val), r = t;
    upd(t);
}

void splitat(node* &l, node* &r, node* t, int pos) { // first pos elements at l
    if (!t) return void(l = r = NULL);
    if (size(t->l) < pos) splitat(t->r, r, t->r, pos-size(t->l)-1), l = t;
    else splitat(l, t->l ,t->l, pos), r = t;
    upd(t);
}

int kth (node *&t, int k) {
    if (!t) return -1;
    if (size(t->l) == k-1) return t->val;
    if (size(t->l) < k-1) return kth(t->r, k-size(t->l)-1);
    else return kth(t->l, k); 
}

bool found;
int find (node *t, int key) {
    if (!t) return 0;
    if (t->val == key) found = true;
    if (t->val <= key) return size(t->l)+1+find(t->r, key);
    else return find(t->l, key);
}

void insert (node *&t, node *n) {
    if (!t) return void(t = n);
    if (n->pri > t->pri) split(n->l, n->r, t, n->val), t=n;
    else if (t->val <= n->val) insert(t->r, n);
    else insert(t->l, n);
    upd(t);
}

void erase (node *&t, int val) {
    if (!t) return;
    if (t->val == val) merge(t, t->l, t->r);
    else if (t->val <= val) erase(t->r, val);
    else erase(t->l, val);
    upd(t);
}

int main(){
    srand(time(NULL));
    node* treap = NULL;
    return 0;
}