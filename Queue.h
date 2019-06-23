#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdbool.h>
#define MAXQUEUE 99

typedef struct PLAYER{
	char first_name[20];
	char last_name[20];
	double bat_avg;
	double Slugging_percentage;
	int Run_Bat_In;
	int Home_Run;
}Item;

typedef struct node{
	Item player;
	struct node * next;
}Node;

typedef struct queue{
	Node * front;
	Node * rear;
	int items;
}Queue;

void InitializeQueue(Queue * pq);
bool QueueIsFull(const Queue * pq);
bool QueueIsEmpty(const Queue * pq);
int QueueItemCount(const Queue * pq);
bool AddItem(Item player,Queue * pq);
bool Deleteitem(Item * tempitem,Queue * pq);
void EmptyTheQueue(Queue * pq);
void eatline(void);
void traverse(const Queue * pq);
void CopyToNode(Item item,Node *pq);
void  CopyToItem(Node * pn,Item *pi);
void traverse_score(const Queue * pq);
#endif
