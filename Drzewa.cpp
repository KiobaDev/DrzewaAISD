#include <iostream>
using namespace std;

int main()
{

}

//DRZEWA BINARNE

//Przyjmując następującą definicję wierzchołka drzewa binarnego rozwiąż podane zadania.
struct node {
	int data;
	node* left;
	node* right;
};

//Zad. 1. Napisz funkcję bool search(node * tree, int x) sprawdzającą, czy dany element, x,
//znajduje się w drzewie binarnym.

bool search(node* tree, int x)
{
	if (tree->data == x) 
	{
		return true;
	}
	else if (tree->left) 
	{
		if (search(tree->left, x))
		return true;
	}
	else if (tree->right) 
	{
		if (search(tree->right, x))
		return true;
	}
	return false;
}

//Zad. 2. Napisz funkcje wyznaczające: liczbę wierzchołków drzewa binarnego, liczbę liści,
//liczbę prawych potomków, wysokość drzewa.

int node_count(node* tree)
{
	int x = 1;
	if (tree->left)
	{
		x += node_count(tree->left);
	}
	else if (tree->right) 
	{
		x += node_count(tree->right);
	}
	return x;
}

int leaves_count(node* tree)
{
	int x = 0;
	if (tree->left)
	{
		x += leaves_count(tree->left);
	}
	else if (tree->right)
	{
		x += leaves_count(tree->right);
	}
	else if (!tree->left && !tree->right) 
	{
		++x;
	}
	return x;
}

int right_children_count(node* tree)
{
	int x = 0;
	if (tree->left)
	{
		x += right_children_count(tree->left);
	}
	if (tree->right)
	{
		++x;
		x += right_children_count(tree->right);
	}
	return x;
}

int tree_height(node* tree)
{
	int l = 0, p = 0;
	if (tree->left)
	{
		++l;
		l += tree_height(tree->left);
	}
	else if (tree->right)
	{
		++p;
		p += tree_height(tree->right);
	}

	else if (l > p)
	{
		return p;
	}
		return p;
}

//Zad. 3. Napisz funkcję sprawdzającą, czy drzewo binarne jest zbalansowane 
//(różnica wysokości lewego i prawego poddrzewa każdego wierzchołka wynosi 
//zero lub jeden).

bool is_balanced(node* tree)
{
	int l = tree_height(tree->left);
	int p = tree_height(tree->right);

	if (l - p >= -1 && l - p <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Zad.4 Napisz funkcję sprawdzającą, czy drzewo binarne jest drzewem BST(ang.binary
//search tree), czyli czy zachodzi następująca własność.Niech x będzie wierzchołkiem drzewa.Jeśli y jest wierzchołkiem znajdującym się w lewym poddrzewie
//wierzchołka x, to data(x) > data(y).Jeśli y jest wierzchołkiem znajdującym się
//w prawym poddrzewie wierzchołka x, to data(x) < data(y).

bool is_BST(node* tree)
{
	bool x = true;
	if (tree->left)
	{
		if (tree->left->data > tree->data)
		{
			return false;
		}
		else
		{
			x = is_BST(tree->left);
		}
	}
	if (tree->right)
	{
		if (tree->right->data < tree->data) 
		{
			return false;
		}
		else 
		{
			x = is_BST(tree->right);
		}
	}
	return x;
}

//Zad. 5. Napisz procedurę usuwającą wszystkie liście podanego drzewa binarnego.

void delete_leaves(node* tree)
{
	if (tree != NULL)
	{
		if (tree->right == NULL && tree->left == NULL)
		{
			delete tree;
		}
		else
		{
			delete_leaves(tree->right);
			delete_leaves(tree->left);
		}
	}
}

//Zad. 6. Zastosuj procedury preorder(), inorder(), postorder() do 
//poniższego drzewa, zakładając, że odwiedzenie wierzchołka p wiąże 
//z następującym działaniem:

void A(node* node)
{
	if (node->left != 0 && node->data - node->left->data < 2)
	{
		node->left->data += 2;
	}
}

void B(node* node)
{
	if (node->left == 0)
	{
		node->right = 0;
	}
}

//Zad. 7. Pokaż drzewo dla którego metody preorder i inorder generują ten sam ciąg

//Zad. 8. Napisz funkcję tworzącą „odbicie lustrzane” podanego drzewa binarnego
node* mirror_tree(node* tree)
{
	node* temporary = new node{ tree->data, nullptr, nullptr };
	if (tree->left)
	{
		temporary->right = mirror_tree(tree->left);
	}
	else if (tree->right) 
	{
		temporary->left = mirror_tree(tree->right);
	}
	return temporary;
}

//Zad. 9. Napisz procedurę, która drukuje drzewo jak pokazano poniżej dla drzewa z rys. 1.1
void print_tree(node* tree, int depth, char prefix)
{
	for (int i = 0; i < depth; ++i)
		cout << prefix;
		cout << tree->data <<endl;
		++depth;
	if (tree->left)
	{
		print_tree(tree->left, depth, prefix);
	}
	else if (tree->right)
	{
		print_tree(tree->right, depth, prefix);
	}
}

//Zad. 10. Strukturę drzewiastą zdefiniowano nastepująco:
struct node_calc {
	char op;
	int number;
	node_calc* left;
	node_calc* right;
};

int eval(node_calc* tree)
{
	if (tree->op == '-')
	{
		return eval(tree->left) - eval(tree->right);
	}
		if (tree->op == '+')
		{
			return eval(tree->left) + eval(tree->right);
		}
			if (tree->op == '/') 
			{
				return eval(tree->left) / eval(tree->right);
			}
		if (tree->op == '*') 
		{
			return eval(tree->left) * eval(tree->right);
		}
	if (tree->op == 0) 
	{
		return tree->number;
	}
}

//Zad. 11. Dana jest tablica a = [a1, a2, . . . , an] o długości n = 2k −1, dla całkowitego k > 0.
//Napisz funkcję tworzącą drzewo jak pokazano w poniższych przykładach :
//• a1 →{ a1 },
//• a1, a2, a3 →{ a2, {a1}, {a3} },
//• a1, a2, a3, a4, a5, a6, a7 →{ a4, {a2, {a1}, {a3}}, {a6, {a5}, {a7}} }

node * create_perfect_tree(int* a, const int k)
{
	int x = (pow(2, k) - 1) / 2;
	node* newN = new node{ a[x], nullptr, nullptr };
	if (k > 1)
	{
	newN->left = create_perfect_tree(a, k - 1);
	newN->right = create_perfect_tree(a + x + 1, k - 1);
	}
	return newN;
}

//DRZEWA BST

//Zad. 1. Naucz się algorytmu usuwania wierzchołków z drzewa poszukiwań binarnych opisanego
//w książce „Wprowadzenie do algorytmów” Cormena, Leisersona i Rivesta.

//Usuwanie klucza
//Usuwanie węzła jest procedurą bardziej skomplikowaną niż jego wstawianie.Podczas wykonywania procedury należy rozważyć trzy przypadki :
//w przypadku, gdy usuwany węzeł nie ma synów(jest liściem) usunięcie przebiega bez reorganizacji drzewa – wskaźnik do węzła w jego ojcu zastępowany jest wskaźnikiem do węzła pustego
//w przypadku, gdy usuwany węzeł ma jednego syna to dany węzeł usuwamy a jego syna podstawiamy w miejsce usuniętego węzła
//w przypadku, gdy usuwany węzeł ma dwóch synów to po jego usunięciu wstawiamy w jego miejsce węzeł, który jest jego następnikiem(który nie ma lewego syna).


//Zad. 2. Napisz program rekonstruujący dane drzewo BST do postaci zupełnego drzewa BST,
//czyli takiego w którym liście znajdują się na dwóch sąsiednich poziomach w drzewie.

int reconstruction(node* tree, int* a)
{
	int x;
	if (tree == NULL) {
		return 0;
	}
	x = reconstruction(tree->left, a);
		a[x] = tree->data;
		x++;
		x += reconstruction(tree->right, a + x);
	return x;
}

//Zad. 3. Napisz funkcję SZUKAJ sprawdzającą, czy podany klucz znajduje się w drzewie BST

bool search(node* tree, int x)
{
	if (tree == NULL) 
	{
		return false;
	}
	else if (tree->data == x) 
	{
		return true;
	}
	else {
		if (tree->data > x) 
		{
			search(tree->left, x);
		}
		else if (tree->data < x) 
		{
			search(tree->right, x);
		}
	}
	return false;
}

//Zad. 4. Przyjmijmy, że w drzewie BST znajdują się liczby od 1 do 1000 i chcemy wyszukać liczbę
//363. Które z poniższych ciągów wierzchołków nie mogą zostać sprawdzone w procedurze SZUKAJ ?

	//a) 2, 252, 401, 398, 330, 344, 397, 363.
	//b) 924, 220, 911, 244, 898, 258, 362, 363.
	//c) 925, 202, 911, 240, 912, 245, 363.				NIE MOZE ZOSTAC SPRAWDZONY	x	
	//d) 2, 399, 387, 219, 266, 382, 381, 278, 363.
	//e) 935, 278, 347, 621, 299, 392, 358, 363.	    NIE MOZE ZOSTAC SPRAWDZONY  x
	

//Zad. 5. Dla każdego z następujących ciągów kluczy narysuj drzewo BST uzyskane przez wstawienie
//kluczy, jeden po drugim, w danym porządku, do początkowo pustego drzewa.
/*
	a) 1, 2, 3, 4, 5, 6, 7.

			1
			 \
			  2
			   \
				3
				 \
				  4
				   \
					5
					 \
					  6
					   \
						7
	b) 4, 2, 1, 3, 6, 5, 7.

				  4
				/  \
			   2    6
			  /\    /\
			 1 	3  5  7


	c) 1, 6, 7, 2, 4, 3, 5.
				  1
				   \
					6
					/\
				   2  7
					\
					 4
					/ \
				   3   5
	*/


//Zad. 6. Dla każdego drzewa BST uzyskanego w zadaniu 5. narysuj drzewo po usunięciu korzenia.
	/*

a)
   2
    \
	 3
	  \
	   4
		\
		 5
		  \
		   6
			\
			 7

b)
			 5
			/ \
		   2   6
		  / \    \
	     1   3    7

c)
			6
		   / \
		  2   7
		   \
            4
           / \
          3   5
*/