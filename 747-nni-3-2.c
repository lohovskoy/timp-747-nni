#include <stdio.h>
#include<stdlib.h>

struct node {  //инициализация двусвязанного списка
 	int value;
	struct node *next;
	struct node *prev;
} node;

struct list{		//инициализация двусвязанного списка
	struct node* f;
	struct node* l;	
} list;

int isEmpty(struct list* spisok) //метод проверки на пустоту
{
	return spisok->f==NULL && spisok->l==NULL;
}

struct node* find(struct list* spisok,int k)
{
	struct node *m=spisok->f;
	while(m->value!=k){
		if(m->next!=NULL){
			m=m->next;
		}else{
			return 0;
		}
	}
	return m;
}

struct node* find_invers(struct list* spisok,int k) //поиск с конца
{
	struct node *m=spisok->l;
	while(m->value!=k){
		if(m->prev!=NULL){
			m=m->prev;
		}else{
			return 0;
		}
	}
	return m;
}

void init(struct list* spisok,int value) //метод инициализации списка
{
	struct node* m;
	m = (struct node*)malloc(sizeof(struct node));
	m->value=value;
	m->next=NULL;
	m->prev=NULL;
	spisok->f = m;
	spisok->l = m;
}

int push_back(struct list* spisok, int x) // вставка назад
{
	if(isEmpty(spisok)==1)
		init (spisok,x);
	else
	{
		struct node *m = (struct node*)malloc(sizeof(struct node));
		m->value=x;
		m->prev=spisok->l;
		m->next=NULL;
		spisok->l=m;
		m->prev->next=m;
	}
	return 0;
}

int push_front(struct list* spisok,int x) //вставка вперед
{
	if(isEmpty(spisok)==1)
		init (spisok,x);
	else
	{
 struct node *m = (struct node*)malloc(sizeof(struct node));
		m->value=x;
		m->prev=NULL;
		m->next=spisok->f;
		spisok->f=m;
		m->next->prev=m;
	}
	return 0;
}

int clear(struct list* spisok) // опустошение списка
{
	if(isEmpty(spisok)==1)
	{
		struct node *m=spisok->f;
		struct node *e=NULL;
		while(m!=NULL)
		{
			e=m->next;
			free(m);
			m=e;
		}
		spisok->f=NULL;
		spisok->l=NULL;
	}
}

void _remove(struct list* spisok, struct node *m){ //сдвиг
	if(m!=NULL){
		if (m==spisok->f && m==spisok->l) {
			clear(spisok);
			return;
		}
		if (m==spisok->f)
		{
			spisok->f=m->next;
			m->next->prev=NULL;
		}
		else if(m==spisok->l)
		{
			spisok->l=m->prev;
			m->prev->next=NULL;
		}
		else if (m!=spisok->f && m!=spisok->l)
		{
			m->next->prev=m->prev;
			m->prev->next=m->next;
		}
		free(m);
	}
}

int removeLast(struct list* spisok,int g)  //удаление последнего элемента
{
	struct node* elem = find_invers(spisok,g);
	if (elem!=NULL){
		_remove(spisok,elem);
		return 0;
	}
	return -1;
}

int removeFirst(struct list* spisok, int x)// удаление первого элемента
{
	struct node* elem = find(spisok,x);
	if (elem!=NULL){
		_remove(spisok,elem);
		return 0;
	}
	return -1;
}

int insertAfter	(struct list* spisok,int num, int data)//вставка после определенного элемента
{
	struct node* m = spisok->f;
	for (int i = 1;i<num;i++)
	{
		m=m->next;
		if(m==NULL) 
			return -1;
	}
	struct node *e = malloc(sizeof(node));
	e->value=data;
	e->next=m->next;
	e->prev=m;
	m->next->prev=e;
	m->next=e;  
	return 0;   
}

int insertBefore(struct list* spisok,int num, int data)// вставка перед определенным элементом
{
	struct node* m = spisok->f;
	for (int i = 1;i<num;i++)
	{
		m=m->next;
		if(m==NULL) 
			return -1;
	}
	struct node *e = malloc(sizeof(node));
	e->value=data;
	e->prev=m->prev;
	e->next=m;
	m->prev=e;
	e->prev->next=e;      
	return 0; 
}

void print(struct list* spisok)// вывод списка
{
	struct node* m=spisok->f;
	while(m->next!=NULL)
	{
		printf("%d ", m->value);
		m=m->next;
	}
	printf("%d\n", m->value);
}

void print_invers(struct list* spisok)// вывод списка с конца
{
	struct node* m=spisok->l;
	while(m->prev!=NULL)
	{
		printf("%d ", m->value);
		m=m->prev;
	}
	printf("%d\n", m->value);	
}



int main()
{
	int f,a;
    int k[3];
    int m;
    int t;
	int j,x;
	int u,y;
	int z;
	int r;
	struct list* struc=(struct list*)malloc(sizeof(struct list));	
	scanf("%d",&f);
	for (int i=0;i<f;i++)
	{
		scanf("%d",&a);
		push_back(struc,a);
	}
	print(struc);
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(struc,k[i])!=NULL)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	scanf("%d",&m);
	push_back(struc,m);
	print_invers(struc);
	scanf("%d",&t);
	push_front(struc,t);
	print(struc);
	scanf("%d%d",&j,&x);
	insertAfter(struc,j,x);
	print_invers(struc);
	scanf("%d%d",&u,&y);
	insertBefore(struc,u,y);
	print(struc);
	scanf("%d",&z);
	removeFirst(struc,z);
	print_invers(struc);
	scanf("%d",&r);
	removeLast(struc,r);
	print(struc);
	clear(struc);
	return 0;
}  
