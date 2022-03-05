#include<stdio.h>
#define size 50
int Q[size],item,f=-1,r=-1;
int isempty();
int isfull();
void insert(int item);
int delete();
void display();
void main()
{
	int ch;
	printf("1.insert \n2.delete \n3.display queue \n4.exit");
	do
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the number to be inserted:");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:item=delete();
				if(item!=-1)
					printf("Item is %d",item);
				break;
			case 3:display();
				break;
			case 4:break;
			default:printf("Invalid choice");
		}
	}while(ch!=4);
}
int isempty()
{
	if (f==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(f==(r+1)%size)
		return 1;
	else
		return 0;
}
void insert(int item)
{
	if(isfull())
	{
		printf("Queue is full");
	}
	else
	{
		if(f==-1)
		{
			f=r=0;
		}
		else
		{
			r=(r+1)%size;
		}
		Q[r]=item;
	}
}
int delete()
{
	if(isempty())
	{
		printf("Queue is empty");
		return -1;
	}
	else
	{
		item=Q[f];
		if(f==r)
		{
			f=r=-1;
		}
		else
		{
			f=(f+1)%size;
		}
		return item;
	}
}
void display()
{
	int i;
	printf("Queue is:");
	for(i=f;i!=r;i=(i+1)%size)
		printf("%d \n",Q[i]);
	printf("%d \n",Q[r]);
}
