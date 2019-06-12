// avl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


struct node {
	int value;
	node* left;
	node* right;
	node* parent;
};

node * insert(node* rt, int value) {
	if (rt == NULL) {
		rt = new node;
		rt->value = value;
		rt->left = NULL;
		rt->right = NULL;
		rt->parent = NULL;
	}
	else if (value > rt->value) {
		rt->right =  insert(rt->right, value);
		rt->left->parent = rt;
	}
	else {
		rt->left = insert(rt->left, value);
		rt->right->parent = rt;
	}
	return rt;
}

node * search(node*rt, int value) {
	if (rt == NULL || rt->value == value) return rt;
	if (rt->value < value) return search(rt->right, value);
	if (rt->value > value) return search(rt->left, value);
}


node * minsearch(node* rt) {
	if (!rt) return rt;
	while (rt->left != NULL) {
		rt = rt->left;
	}
	return rt;
}

node * maxsearch(node* rt) {
	if (!rt) return rt;
	while (rt->right != NULL) {
		rt = rt->right;
	}
	return rt;
}

void printt(node* rt) {
	//inorder
	if (rt == NULL) return;
	printt(rt->left);
	printf("%d ", rt->value);
	printt(rt->right);
}

node * succ(node*rt) {
	if (rt == NULL) return rt;

	if (rt->right != NULL) {
		return minsearch(rt->right);
	}
	//rt = rt->parent;
	while ( rt->parent && rt != rt->parent->left) {
		rt = rt->parent;
	}
	return rt->parent;

}

node * pred(node *rt) {
	if (!rt) return rt;
	if (rt->left != NULL) return maxsearch(rt->left);

	//rt = rt->parent;
	while (rt->parent && rt != rt->parent->right) {
		rt = rt->parent;
	}
	return rt->parent;
}



node* delete(node* rt, int value) {
	if (rt == null) return rt;

	if (rt->value == value) {
		if (!rt->left && !rt->right) {
			rt = NULL;			
		}
		else if (rt->left && !rt->right) {

		}
	}

}



int main()
{
	int i, j, k, l;
	node *root = NULL;

	insert(root, 5);

	return 0;
}
