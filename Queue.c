#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitializeQueue(Queue * pq)
{
	pq->front=pq->rear=NULL;
	pq->items=0;
}
bool QueueIsFull(const Queue * pq)
{
	return pq->items==MAXQUEUE;
}
bool QueueIsEmpty(const Queue * pq)
{
	return pq->items==0;
}
int QueueItemCount(const Queue * pq)
{
	return pq->items;
}
bool AddItem(Item player,Queue * pq)
{
	Node * pnew;
	if(QueueIsFull(pq))
		return false;
	pnew=(Node *)malloc(sizeof(Node));
	if(pnew==NULL)
	{
		fprintf(stderr,"Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(player,pnew);
	pnew->next=NULL;
	if(QueueIsEmpty(pq))
		pq->front=pnew;
	else
		pq->rear->next=pnew;
	pq->rear=pnew;
	pq->items++;
	if(QueueIsFull(pq))
		pnew->next=pq->front;
	return true;
}
bool Deleteitem(Item * tempitem,Queue * pq)
{
	Node * pt;
	if(QueueIsEmpty(pq))
		return false;
	CopyToItem(pq->front,tempitem);
	pt=pq->front;
	pq->front=pq->front->next;
	free(pt);
	pq->items--;
	if(pq->items==0)
	  pq->rear=NULL;
  return true;
}

void EmptyTheQueue(Queue * pq)
{
	Item dummy;
	while(!QueueIsEmpty(pq))
	  Deleteitem(&dummy,pq);
}

void eatline(void)
{

	while(getchar()!='\n')
		continue;		
}
void traverse(const Queue * pq)
{
	Node * pt;
	int count=0;
	pt=pq->front;
	for(;count<=pq->items;count++)
	{
		printf("%s %s %f %f \n",pt->player.first_name,pt->player.last_name,pt->player.bat_avg,pt->player.Slugging_percentage);
		pt=pt->next;
	}
}
void traverse_score(const Queue * pq)
{
	Node * pt;
	int count=0;
	pt=pq->front;
	for(;count<=pq->items;count++)
	{
		printf("%s %s %.3f %.3f %d %d \n",pt->player.first_name,pt->player.last_name,pt->player.bat_avg,pt->player.Slugging_percentage,pt->player.Run_Bat_In,pt->player.Home_Run);
		pt=pt->next;
	}
}
 void CopyToNode(Item item,Node * pq)
{
	pq->player=item;
} 
void  CopyToItem(Node * pn,Item * pi)
{
	*pi=pn->player;
}
