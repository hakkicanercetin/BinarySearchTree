
#include <iostream>

using namespace std;

struct  btree
{
	int data;
	btree* left;
	btree* right;

};

btree* ekle(btree* t, int x)
{
	if (t == NULL)
	{
		t = new btree;
		t->data = x;
		t->left = NULL;
		t->right = NULL;
	}
	else
	{
		if (t->data < x)
			t->right = ekle(t->right, x);
		else
			t->left = ekle(t->left, x);
	}
	return t;
}

int elemansay(btree* t)
{
	if (t == NULL)
		return 0;
	else
		return elemansay(t->right) + 1 + elemansay(t->left);
}

int max(btree* t)
{
	if (t == NULL)
		return 0;
	else
		while (t->right != NULL)
			t = t->right;
	return t->data;
}

int min(btree* t)
{
	if (t == NULL)
		return 0;
	else
		while (t->left != NULL)
			t = t->left;
	return t->data;
}

btree* arama(btree* t, int x)
{
	if (t != NULL)
	{
		if (t->data == x)
			return t;
		else
		{
			if (t->data < x)
				arama(t->right, x);
			else
				arama(t->left, x);
		}
	}
	else
		return NULL;
}

btree* del(btree* t, int x)
{
	if (t == NULL)
		return NULL;
	if (t->data == x)
	{
		if (t->right == NULL && t->left == NULL)
			return NULL;
		if (t->left == NULL)
		{
			t->data = min(t->right);
			t->right = del(t->right, t->data);
			return t;
		}
		t->data = max(t->left);
		t->left = del(t->left, t->data);
		return t;
	}
	if (t->data < x)
	{
		t->right = del(t->right, x);
		return t;
	}
	t->left = del(t->left, x);
	return t;
}

btree* yazdir(btree* t)
{
	if (t == NULL)
		return 0;
	else
	{
		cout << t->data << " ";
		yazdir(t->left);
		yazdir(t->right);
	}
	return 0;
}




int main()
{
	btree* tree;
	tree = new btree;
	tree = NULL;
	tree = ekle(tree, 12);
	tree = ekle(tree, 20);
	ekle(tree, 30);
	ekle(tree, 9);
	ekle(tree, 15);
	ekle(tree, 8);
	ekle(tree, 10);
	ekle(tree, 45);
	ekle(tree, 5);
	ekle(tree, 22);
	ekle(tree, 11);
	yazdir(tree);
	cout << "\nEleman Sayisi:\t" << elemansay(tree);
	cout << "\nMaksimum eleman:" << max(tree);
	cout << "\nMinimum eleman:\t" << min(tree);
	cout << endl;
	int x;
	cout << "Bir sayý giriniz : ";
	cin >> x;
	btree* ar;
	ar = arama(tree, x);
	if (ar == NULL)
		cout << "\nEleman yok!";
	else
		cout << "\nEleman var: " << ar->data << " Siliniyor...";
	del(tree, x);
	cout << endl;
	yazdir(tree);
	cout << endl;
	system("pause");
	return 0;
}

