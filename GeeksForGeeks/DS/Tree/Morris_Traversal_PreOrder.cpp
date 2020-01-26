// { Driver Code Starts
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <map>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};
