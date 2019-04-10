#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_STRING	256
#define QUANTITYOFNODES	1000
#define HASHTABLESIZE 	10

typedef struct 	el
{
	char 		name[SIZE_OF_STRING];
	struct el 	*next;
}				node;

node *hashTable[QUANTITYOFNODES];
int hashTableSize = HASHTABLESIZE;

int 	stringToKey(char str[])
{
	int c,s = 0;

	for(int i = 0; i < strlen(str); i++)
	{
		c = str[i];
		s = s + c;
	}
	return (s);
}

// void	presentation(void)
// {

// }

int 	searchNode(char nName[])
{
	int ascii = stringToKey(nName);
	int key = ascii % hashTableSize;

	node *n;

	for(n = hashTable[key]; n != NULL; n = n->next)
	{
		if (strcmp(n->name, nName) == 0)
			return key;
	}
	return -1;
}



void	addNode()
{
	int ascii, key;
	node *n, *nl;

	n = (node *)malloc(sizeof(node));
	n->next = NULL;

	printf("%s", "Node Name:");
	scanf("%s", n->name);

	// printf("[%lu]\n", strlen(n->name));
	ascii = stringToKey(n->name);
	key = ascii % hashTableSize;
	if (hashTable[key] == NULL)
	{
		hashTable[key] = n;
	}
	else
	{
		for (nl = hashTable[key]; nl->next != NULL; nl=nl->next)
			;
			nl->next = n;
	}
}

void	printfList(node *n)
{
	node *nl;

	for(nl = n; nl != NULL; nl = nl->next)
		printf("[%s] ", nl->name);
}

void	deleteNode(char nName[])
{
	printf("%s\n", "Delete node...");

	int ascii = stringToKey(nName);
	int key = ascii %hashTableSize;

	node *n, nl;
	
	if (strcmp(hashTable[key]->name, nName) == 0)
	{
		n = hashTable[key];
		hashTable[key] = hashTable[key]->next;
		free(n); /* and all its attributes */
		return ;
	}

	for (n = hashTable[key]; n->next != NULL; n = n->next)
	{
		nl = *(n->next);
		if (strcmp(nl.name, nName) == 0)
		{
			n->next = (nl.next);
			// free(nl); /* and all its attributes */
			break ;
		}
	}
}

void	printHashTable()
{
	for (int i = 0; i < hashTableSize; i++)
	{
		printf("\nHashTable[%d]: ", i);
		printfList(hashTable[i]);
	}
}

int 	main(void)
{
	// init;
	for (int i = 0; i < hashTableSize; i++)
	{
		hashTable[i] = NULL;
	}
	//////////
	int key = 0; int action = 1;

	// presentation();

	char nName[SIZE_OF_STRING];

	while (42) //use enum instead;
	{
		scanf("%d", &action);

		// printf("%d\n", action);

		if (action != 1 && action != 2 &&action != 3 && action != 4 )
		{
			break ;
		}

		if (action == 1)
			addNode();
		if (action == 2)
		{
			printf("%s\n", "Node name:");
			scanf("%s", nName);
			key = searchNode(nName);
			if (key == -1)
				printf("%s\n", "Node doesn`t exist");
			else
			{
				printf("%s\n", "Node exist in:");
				printf("hashTable[%d]: \n", key);
				printfList(hashTable[key]);
			}
		}
		if (action == 3)
		{
			printf("%s\n", "Node name:");
			scanf("%s", nName);
			if (key == -1)
				printf("%s\n", "Node doesn`t exist");
			else
				deleteNode(nName);
		}
		if (action == 4)
			printHashTable();
		printf("\n%s\n", "Choose action:");
	}
}