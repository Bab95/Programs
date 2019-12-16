void my_inorder(Node *root, Node **first, Node **second, Node **current, Node **previous) {
	if (root == NULL) {
		return;
	}
	/*if(first&&second){
	return;
	}*/
	my_inorder(root->left, first, second, current, previous);
	*previous = *current;
	*current = root;
	if ((*current)&&(*previous)) {
		if ((*current)->data<(*previous)->data) {
			if (*first==NULL) {
				*first = *previous;
			}
			else if (*second==NULL) {
				*second = *current;
			}

			/**second = *first;
			*first = *previous;*/
		}
	}
	my_inorder(root->right, first, second, current, previous);
}
struct Node *correctBST(struct Node* root)
{
	Node *first, *previous, *current, *second;
	first = NULL;
	second = NULL;
	current = NULL;
	previous = NULL;
	my_inorder(root, &first, &second, &current, &previous);
	/*if (first) {
		cout << first->data << endl;
	}
	if (second) {
		cout << second->data << endl;
	}*/
	int tmp = (first)->data;
	(first)->data = (second)->data;
	(second)->data = tmp;
	return root;
}
