#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node {
    int data;
	struct node* next;
	struct node* prev;
} Node_t;

Node_t* getNode(int data) {
    Node_t *ptr = (Node_t*)malloc(sizeof(Node_t));
	assert(ptr != NULL);
	ptr->data = data;
	ptr->prev = NULL;
	ptr->next = NULL;
	return ptr;
}

static Node_t* createLinkedListWithArray(int* array,int size,Node_t **tail) {
    if(size <=0) return NULL;
	Node_t* root = NULL;
	Node_t* tempNode = NULL;
    for(int i=0;i<size;i++) {
		if(i == 0) {
		    tempNode = getNode(array[i]);
			root = tempNode;
		} else {
			tempNode->next = getNode(array[i]);
			tempNode = tempNode->next;
		}
		*tail = tempNode;
	}
    return root;
}

class list {
	private: int size;
	private: Node_t* head;
	private: Node_t* tail;
	private: static Node_t* getNode(int data);
	private: static Node_t* createLinkedListWithArray1(int* array,int size,Node_t **tail);
	public :
	list(int* array,int numofElements);
	list();
	int sizeOfList();
	void insert(int data);
};
list::list() {
	size = 0;
	head = tail = NULL;
}
list::list(int* array, int numofElements) {
	size = numofElements;
	head = createLinkedListWithArray(array,numofElements,&tail);
	if(size <= 0) return;
	int i = 0;
	head = getNode(array[i]);
	Node_t* tempNode = head;
	for(i =1;i<size;i++) {
		tempNode->next = getNode(array[i]);
		tempNode = tempNode->next;
	}
	tail = tempNode;
}

Node_t* list::createLinkedListWithArray1(int* array,int size,Node_t **tail) {
    if(size <=0) return NULL;
	Node_t* root = NULL;
	Node_t* tempNode = NULL;
    for(int i=0;i<size;i++) {
		if(i == 0) {
		    tempNode = getNode(array[i]);
			root = tempNode;
		} else {
			tempNode->next = getNode(array[i]);
			tempNode = tempNode->next;
		}
		*tail = tempNode;
	}
    return root;
}

int list::sizeOfList() {
	return size;
}

Node_t* list::getNode(int data) {
    Node_t *ptr = (Node_t*)malloc(sizeof(Node_t));
	assert(ptr != NULL);
	ptr->data = data;
	ptr->prev = NULL;
	ptr->next = NULL;
	return ptr;
}

void printLinkedList(Node_t* root) {
	static int i = 0;
	i++;
	printf("value of i %d\n",i);
	if(i>8) return;
	if(root == NULL) return;
	    printf("%d\n",root->data);
	return printLinkedList(root->next);
}

void printLinkedListStraigt(Node_t* root) {
	if(root == NULL) return;
	    printf("%d\n",root->data);
	return printLinkedListStraigt(root->next);
}

bool isListSimilar(Node_t* firstList,Node_t* secondList) {
	if(firstList == secondList) {
		if(firstList == NULL) {
		    return true;
		}
	}
	
	bool ret = isListSimilar(firstList->next,secondList->next);
	if(ret == false) return false;
	if((firstList->data != secondList->data)) {
		return false;
	}
	return true;
}

Node_t* dupliCateList(Node_t* root,Node_t** tail) {
	//Node_t* tail = NULL;
	if(root == NULL) return NULL;
	Node_t* secondRoot= getNode(root->data);
	secondRoot->next = dupliCateList(root->next,tail);
	if(secondRoot->next != NULL) {
		secondRoot->next->prev = secondRoot;
	} else {
		*tail = secondRoot;
	}
	return secondRoot;  // Retruning head of list
	//return tail;
}

int main() {
	//int array[5] = {1,3,201,65,80};
	int array[9] = {1,2,3,4,5,4,3,2,1};
	int isPlandrome = 0;
	Node_t *tail = NULL;
	Node_t* root = createLinkedListWithArray(array,sizeof(array)/sizeof(array[0]),&tail);
	Node_t* tempNode = root;
	printLinkedListStraigt(tempNode);
	Node_t* duplicate = dupliCateList(root,&tail);
	bool isListSame = isListSimilar(root,duplicate);
	printf("\n 1st List   = \n");
	printLinkedListStraigt(root);
	printf("\n 2nd list List   = \n");
	printLinkedListStraigt(duplicate);
	
	printf("\n Is List same  = %d\n",isListSame);

return 0;
}