#include <stdio.h>
#include<stdlib.h>

struct node { 
 	int c;
	struct node *next;
} node;

struct list{		
	struct node* first;	
} list;

int isEmpty(struct list* struc)
{
	return struc->first==NULL;
}

struct node* find(struct list* struc,int value)
{
	struct node *g=struc->first;
	while(g->c!=value){
		if(g->next!=NULL)
			g=g->next;
		else
			return 0;
	}
	return g;
}

void init(struct list* struc,int value)
{
	struct node* g;
	g = (struct node*)malloc(sizeof(struct node));
	g->c=value;
	g->next=NULL;
	struc->first = g;
}

int push_back(struct list* struc, int x)
{
	if(isEmpty(struc)==1)
		init (struc,x);
	else
	{
		struct node* g = (struct node*)malloc(sizeof(struct node));
		g->c=x;
		g->next=NULL;
		struct node* te = struc->first;
		while(te->next!=NULL)
			te=te->next;
		te->next=g;
	}
	return 0;
}

int push_front(struct list* struc,int x) 
{
	if(isEmpty(struc)==1)
		init (struc,x);
	else
	{
		struct node *g = (struct node*)malloc(sizeof(struct node));
		g->c=x;
		g->next=struc->first;
		struc->first=g;
	}
	return 0;
}

int clear(struct list* struc)
{
	if(isEmpty(struc)==1)
	{
		struct node *g=struc->first;
		struct node *te=NULL;
		while(g!=NULL)
		{
			te=g->next;
			free(g);
			g=te;
		}
		struc->first=NULL;
	}
}

void _remove(struct list* struc, struct node *g){
	if(g!=NULL){
		if (g==struc->first)
			struc->first=g->next;
		else
		{
			struct node *te = (struct node*)malloc(sizeof(struct node));
			te=struc->first;
			while(te->next!=g)
				te=te->next;
			te->next = g->next;
		}
		free(g);
	}
}

int removeFirst(struct list* struc, int x)
{
	struct node* element = find(struc,x);
	if (element!=NULL){
		_remove(struc,element);
		return 0;
	}
	return -1;
}

int insertAfter	(struct list* struc,int num, int value)
{
	struct node *te = malloc(sizeof(node));
	te->c=value;

	struct node* g = struc->first;
	struct node* prev_t = struc->first;
	
	for (int i = 1;i<num+1;i++)
	{
		prev_t=g;
		g=g->next;
		if(g==NULL) 
			return -1;
	}
	prev_t->next=te;
	te->next=g;
	return 0;   
}

void print(struct list* struc)
{
	struct node* g=struc->first;
	while(g->next!=NULL)
	{
		printf("%d ", g->c);
		g=g->next;
	}
	printf("%d\n", g->c);
}

int main()
{
	int a,y,k[3],m,t,j,x,z;
    struct list* list=(struct list*)malloc(sizeof(struct list));	
	scanf("%d",&a);
	for (int i=0;i<a;i++)
	{
		scanf("%d",&y);
		push_back(list,y);
	}
	print(list);
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(list,k[i])!=NULL)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	scanf("%d",&m);
	push_back(list,m);
	print(list);
	scanf("%d",&t);
	push_front(list,t);
	print(list);
	scanf("%d%d",&j,&x);
	insertAfter(list,j,x);
	print(list);
	scanf("%d",&z);
	removeFirst(list,z);
	print(list);
	clear(list);
	return 0;
}
