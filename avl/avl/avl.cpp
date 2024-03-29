// avl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
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
		rt->right->parent = rt;
	}
	else {
		rt->left = insert(rt->left, value);
		rt->left->parent = rt;
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



node* del(node* rt, int value) {
	if (rt == NULL) return rt;
	
	if (rt->value > value) {
		return del(rt->left, value);
	}
	else if (rt->value < value) {
		return del(rt->right, value);
	}
	else{
		if (!rt->left && !rt->right) {
			rt = NULL;			
		}
		else if (rt->left && !rt->right) {
			rt->left->parent = rt->parent;
			rt = rt->left;
			//(rt->parent->right == rt) ? (rt->parent->right = rt->left) : (rt->parent->left = rt->left);
		}
		else if (rt->right && !rt->left) {
			rt->right->parent = rt->parent;
			rt = rt->right;
			//(rt->parent->right == rt) ? (rt->parent->right = rt->right) : (rt->parent->left = rt->right);
		}
		else {
			node* sc = succ(rt);
			rt->value = sc->value;
			del(rt->right, rt->value);
		}
	}
	
	return rt;
}



int main()
{
	int i, j, k, l;
	node *root = NULL;

	while (1) {
		scanf("%d", &i);
		if (i == -1) {
			break;
		}
		if (i == 0) {
			scanf("%d", &j);
			root = insert(root, j);
			printt(root);
			printf("\n");
		}
		if (i == 1) {
			scanf("%d", &j);
			root = search(root, j);
			printf(" %d\n ", root->value);
		}
		if (i == 2) {
			scanf("%d", &j);
			root = succ(search(root, j));
			printf("%d \n", root->value);
		}
		if (i == 3) {
			scanf("%d", &j);
			root = pred(search(root, j));
			printf("%d \n", root->value);
		}
		if (i == 4) {
			scanf("%d", &j);
			del(root, j);
			printt(root);
			printf("\n");
		}
	}

	return 0;
}
