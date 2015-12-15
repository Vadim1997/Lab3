#include<iostream>
#include<iomanip>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<locale>
using namespace std;
struct Node {
	int value;
	Node *left;
	Node *right;
};
void InsertTree(Node **aNode, int data) {
	if (!(*aNode)) {
		(*aNode) = new Node;
		(*aNode)->value = data;
		(*aNode)->left = NULL;
		(*aNode)->right = NULL;
	}
	else {
		if (data < (*aNode)->value) InsertTree(&(*aNode)->left, data);
		else InsertTree(&(*aNode)->right, data);
	}
	return;
}
void PrintTree(Node *aNode) {
	if (aNode) {
		PrintTree(aNode->left);
		cout << aNode->value << " ";
		PrintTree(aNode->right);
	}
	return;
}
void Del(Node **r, Node **q)
{
	Node *s;
	if (!(*r)->right)
	{
		(*q)->value = (*r)->value;
		*q = *r;
		s = *r; *r = (*r)->left; delete s;
	}
	else  Del(&((*r)->right), q);
}
void Delete(Node **p, int data)
{
	Node *q;
	if (!p) cout << "Äåðåâî íå çíàéäåíî!" << endl;
	else
		if (data<(*p)->value) Delete(&((*p)->left), data);
		else
			if (data>(*p)->value) Delete(&((*p)->right), data);
			else
			{
				q = *p;
				if (!q->right)
				{
					*p = q->left; delete q;
				}
				else
					if (!q->left) { *p = q->right; delete q; }
					else  Del(&(q->left), &q);
			}
	return;
}
int gMax(Node *aNode, int maximum) {
	if (aNode == NULL) {
		return maximum;
	}
	return max(gMax(aNode->left, aNode->value),
		gMax(aNode->right, aNode->value));
}

int gMin(Node *aNode, int minimum) {
	if (aNode == NULL) {
		return minimum;
	}
	return min(gMin(aNode->left, aNode->value),
		gMin(aNode->right, aNode->value));
}

int gSum(Node *aNode, int max, int min) {
	return max + min;
}


int main()//головна програма
{
	setlocale(LC_ALL, "Russian");
	Node *root = new Node;
	root = NULL;
	InsertTree(&root, 24);
	InsertTree(&root, 5);
	InsertTree(&root, 7);
	InsertTree(&root, 56);
	InsertTree(&root, 49);
	InsertTree(&root, 32);
	cout << "Åëåìåíòè áiíàðíîãî äåðåâà" << endl;
	PrintTree(root);
	cout << endl;
	cout << "Max åëåìåíò = " << gMax(root, -100) << endl;
	cout << "Min åëåìåíò = " << gMin(root, 100) << endl;
	cout << "Ñóìà çàäàíèõ åëåìåíòiâ(max i min) = " << gSum(root, gMax(root, -100), gMin(root, 100)) << endl;
	Delete(&root, 24);
	Delete(&root, 5);
	Delete(&root, 7);
	Delete(&root, 56);
	Delete(&root, 49);
	Delete(&root, 32);
	return 0;
}
