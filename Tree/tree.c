#include <stdio.h>
#include <stdlib.h>

struct tree{
	int data;
	struct tree *right;
	struct tree *left;
};

struct tree* newNode (int data);
struct tree* insert (struct tree *p, int newData);
struct tree* delete (struct tree *p, int key);
int treeMin (struct tree *p);
int treeMax (struct tree *p);
int findSuc (struct tree *p, int key);
int findPred (struct tree *p, int key);
int treeSuc (struct tree *p);
int treePred (struct tree *p);
int inorder (struct tree *p);
int preorder (struct tree *p);
int postorder (struct tree *p);

void main (void)
{
	int sec, key, suc, pred, min, max;
	struct tree *root; 
	root = NULL;

 	while(1)
	{
		printf("\n---------------------------------------------------------------\n");
		printf("\nPlease, choose binary tree operations with numbers. \n\n");
		printf("1. Add tree.\n");
		printf("2. Sub tree.\n");
		printf("3. Minimum value of tree.\n");
		printf("4. Maximum value of tree.\n");
		printf("5. Succesor value of number.\n");
		printf("6. Predecessor value of number.\n");
		printf("7. Succesor value of tree.\n");
		printf("8. Predecessor value of tree.\n");
		printf("9. Display Inorder.\n");
		printf("10. Display Preorder.\n");
		printf("11. Display Postorder.\n");
		printf("12. Exit\n");
		printf("\n---------------------------------------------------------------\n\n");
		
		scanf("%d", &sec);

		switch(sec)
		{
			case 1:
				printf("\n Please, enter the number to insert on tree. \n");
				scanf("%d",&key);
				if (root == NULL)
					root = insert(root, key);
				else
					insert(root, key);
				break;
			case 2:
				printf("\nPlease, enter the number to delete on tree. \n");
				scanf("%d",&key);
				delete(root, key);
				break;
			case 3:
				printf("\nMinimum value of tree. \n");
				min = treeMin(root);
				printf("\nMinimum value is %d\n", min);
				break;
			case 4:
				printf("\nMaximum value of tree. \n");
				max = treeMax(root);
				printf("\nMaximum value is %d\n", max);
				break;
			case 5:
				printf("\nPlease, enter the number to find succesor.\n");
				scanf("%d",&key);
				suc =  findSuc(root, key);
				printf("Succesor value of number,%d, is %d\n",key, suc);
				break;
			case 6:
				printf("\n Please, enter the number to find predecessor.\n");
				scanf("%d",&key);
				pred = findPred(root, key);
				printf("Predecessor value of number,%d, is %d\n",key, pred);
				break;
			case 7:
				printf("\nSuccesor value of tree.\n");
				suc = treeSuc(root);
				printf("%d\n", suc);
				break;
			case 8:
				printf("\nPredecessor value of tree.\n");
				pred = treePred(root);
				printf("%d\n",pred);
				break;
			case 9:
				printf("\nDisplay tree as inorder.\n");
				inorder(root);
				break;
			case 10:
				printf("\nDisplay tree as preorder.\n");
				preorder(root);
				break;
			case 11:
				printf("\nDisplay tree as postorder.\n");
				postorder(root);
				break;
			case 12:
				exit(1);
			default:
				printf("\nWarning !!!: Selection is not between 1 and 12.\n");
				printf("\nPlease, enter again.\n");
				break;
		}		

	}

}

struct tree* newNode (int data)
{
	struct tree *temp;
	temp = (struct tree*) malloc(sizeof(struct tree));
	
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

struct tree* insert (struct tree *p, int newData)
{
	if(p != NULL)
	{
		if (newData < p->data)
			p->left = insert(p->left, newData);
		else
			p->right = insert(p->right, newData);
	}
	else
		return newNode(newData);
}

struct tree* delete (struct tree *p, int key)
{
	if (p == NULL)
		return p;
	if (p->data > key)
		p->left = delete(p->left, key);
	else if (p->data < key)
		p->right = delete(p->right, key);
	else
	{
		struct tree *temp;

		if (p->left == NULL)
		{
			temp = p->right;
			free(p);
			return temp;
		}		
		else if (p->right == NULL)
		{
			temp = p->left;
			free(p);
			return temp;
		}

		p->data = treeMin(p->right); 
		p->right = delete(p->right, p->data);
	}

	return p;
}

/* Find Minimum Value of Binary Tree */
int treeMin (struct tree *p)
{
	if (p ==  NULL)
		return 0;
	while (p->left != NULL)
		p = p->left;

	return (p->data);
}

/* Find Maximum Value of Binary Tree */
int treeMax (struct tree *p)
{
	if (p == NULL)
		return 0;
	while (p->right != NULL)
		p = p->right;
	return (p->data);
}


/*Find Succesor of Key */
int findSuc (struct tree *p, int key)
{
	int suc, temp;

	if (p->data == key)
	{
		if (p->right != NULL)
			suc = treeMin(p->right);
		else
			return 0;
	}
	else if (p->data > key)
	{
		suc = p->data;
		temp = findSuc(p->left, key);
		if ( temp != 0)
			suc = temp;
	}
	else 
		suc = findSuc(p->right, key);

	return suc;
}

/*Find Predecessor of Key */
int findPred (struct tree *p, int key)
{
	int pred, temp;

	if (p->data == key)
	{
		if(p->left != NULL)
			pred = treeMax(p->left);
		else 
			return 0;
	}
	else if (p->data < key)
	{
		pred = p->data;
		temp = findPred(p->right, key);
		if(temp != 0)
			pred = temp;
	}
	else 
		pred = findPred(p->left, key);

	return pred;
}

/*Find Tree Succesor*/
int treeSuc (struct tree *p)
{
	if (p == NULL || p->right == NULL)
		return 0;
	return treeMin(p->right);
}

/*Find Tree Predecessor*/
int treePred (struct tree *p)
{
	if (p == NULL || p->left == NULL)
		return 0;
	return treeMax(p->left);
}

/* Inorder Tree Walk (LDR) */
int inorder (struct tree *p)
{
	if(p != NULL)
	{
		inorder(p->left);
		printf("%d ", p->data);
		inorder(p->right);
	}
	return 1;
}

/* Preorder Tree Walk (DLR) */
int preorder (struct tree *p)
{
	if(p != NULL)
	{
		printf("%d ", p->data);
		preorder(p->left);
		preorder(p->right);
	}
	return 1;
}

/* Postorder Tree Walk (LRD) */
int postorder (struct tree *p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ",p->data);
	}
	return 1;
}
