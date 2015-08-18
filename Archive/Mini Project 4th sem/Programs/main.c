//Program to simulate the working of serial adder using circular linked list
//Authors: Musaddiq Faraz, Sameer Shaik, Shashi Kiran Reddy, Sujay
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	unsigned int data;
	struct node* link;
}number;
number* getnode()
{
	return (number*)malloc(sizeof(number));
}

inline void terminate()
{
	printf("INCORRECT ARGUMENTS\n");
	exit(0);
}

void create(number** num,char* str)
{
	int temp,i;
	number *temp1;
	
	temp1=getnode();
	temp1->data = strlen(str);
	*num=temp1;
	temp1->link=NULL;
	for(i=strlen(str)-1;i>=0;i--,temp1=temp1->link)
	{
		temp1->link=getnode();
		temp=str[i]-'0';
		temp1->link->data=temp;
		if(temp>9 || temp<0)
			terminate();
		temp1->link->link=NULL;		
	}
	for(temp1=*num;temp1->link;temp1=temp1->link);
	temp1->link=*num;
}

void display(number* num)
{
	number* temp;
	char *str = (char*) malloc (sizeof(char)*(num->data));
	int i;
	for(temp=num->link,i=0;temp!=num;temp=temp->link,i++)
		str[i]=(char)(temp->data+'0');
	str[i]='\0';
	for(i=strlen(str)-1;i>=0;i--)
		printf("%c",str[i]);
	printf("\n");
}
void addnext(number* sum,number* num)
{
	number *temp1,*temp2;
	int temp,carry=0;
	for(temp1=sum,temp2=num;temp1->link!=sum&&temp2->link!=num;temp1=temp1->link,temp2=temp2->link)
	{
		temp=temp1->link->data+temp2->link->data+carry;
		if(temp>=10)
			carry=1;
		else
			carry=0;
		temp1->link->data=temp%10;
	}
	if(temp1->link==sum)
	{
		while(temp2->link!=num)
		{
			temp1->link=getnode();
			temp1=temp1->link;
			temp2=temp2->link;
			temp=temp2->data+carry;
			if(temp>=10)
				carry=1;
			else
				carry=0;
			temp1->data=temp%10;
			
		}
		if(carry)
		{
			temp1->link=getnode();
			temp1=temp1->link;
			temp1->data=1;
		}
		temp1->link=sum;
	}
	else
	{
		while(temp1->link!=sum && carry)
		{
			temp1=temp1->link;
			temp=temp1->data+carry;
			if(temp>=10)
				carry=1;
			else
				carry=0;	
			temp1->data=temp%10;
		}
		if(carry)
		{
			temp1->link=getnode();
			temp1=temp1->link;
			temp1->data=1;
			temp1->link=sum;
		}
		
	}
	
		
}
void main(int argc,char* argv[])
{
	int i,max;
	struct timeval t;
	double start,end;
	number *summands,*sum;
	if(!(argc-1))
		terminate();
	create(&sum,argv[1]);
	create(&summands,argv[2]);
	gettimeofday(&t,NULL);
	start=t.tv_sec+(t.tv_usec/1000000.0);
	addnext(sum,summands);
	gettimeofday(&t,NULL);
	end=t.tv_sec+(t.tv_usec/1000000.0);
	display(sum);
	printf("%lf time\n",end-start);
			
	
}

