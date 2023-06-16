#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    node* currentListItem = head;

    int linkedListCount = 0;
    while(currentListItem != NULL)
    {

        linkedListCount++;
        currentListItem = currentListItem->next;

    }

    return linkedListCount;

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{

    int linkListLength = length(head);

    char* parsedCString = (char*)malloc(sizeof(char) * (linkListLength+1));

    for(int index = 0; index < linkListLength; ++index)
    {
        parsedCString[index] = head->letter;
        head = head->next;
    }

    parsedCString[linkListLength] = '\0';

    return parsedCString;

}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{

    unsigned short insertion = 0;

    node* currentLinkIndex = *pHead;
    while(!insertion)
    {

        if(currentLinkIndex == NULL)
        {

            currentLinkIndex = (node*)malloc(sizeof(node));
            currentLinkIndex->letter = c;
            currentLinkIndex->next = NULL;
            *pHead = currentLinkIndex;

            //Doubling up in a just in case scenario
            insertion = 1;
            break;

        }
        else if (currentLinkIndex->next == NULL)
        {

            currentLinkIndex->next = (node*)malloc(sizeof(node));
            currentLinkIndex->next->letter = c;
            currentLinkIndex->next->next = NULL;

            //Doubling up for a just in case
            insertion = 1;
            break;

        }
        else
        {

            currentLinkIndex = currentLinkIndex->next;

        }
    }


}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    if(*pHead != NULL)
    {
        node* tempHead = (*pHead)->next;

        while(*pHead != NULL)
        {

            free(*pHead);
            *pHead = tempHead;
            if((*pHead) != NULL)
                tempHead = (*pHead)->next;

        }
    }
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}