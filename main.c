#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "give.h"
#include "struct.h"

void signup(struct users**);
void login(struct users**, struct post**);
void usercheck(struct post **first);
void posting (struct users*,struct post***);
void info (struct users *,struct post *);
void find_user(struct users *,struct post *);
void like(struct users *,struct post *);
void delete (struct users *,struct post ***);

int main()
{
	struct users *first=NULL;
	struct post *pfirst=NULL;
	int loap=1;
	while(loap)
	{
		char *command=word();
		if(strcmp(command,"signup")==0)
		{
			signup(&first);
		}
		else if(strcmp(command,"login")==0)
		{
			login(&first,&pfirst);
		}
		else 
		{
			printf("\neror\n");
		}
		free(command);
	}
}
void signup (struct users** first)
{
	
	struct users *nodep=*first,*pnode=*first;
	struct users *node=(struct users*)malloc(sizeof(struct users));
	char *s_name=word();
	int leave=0;	
	while(pnode!=NULL)
	{
		if(strcmp(pnode->name,s_name)==0)
		{
		printf("\nname has used\n");
		leave=1;
		}
	pnode=pnode->next;
	}
	if(leave!=1)
	{
	if(*first==NULL)
	*first=node;
	else
	{
		while(nodep->next!=NULL)
		{
			nodep=nodep->next;
		}
	nodep->next=node;
	}
	node->name=s_name;
	node->pass=word();
	node->next=NULL;
	printf("\nsignup completed!\n");
	}
}
void login (struct users **first,struct post **pfirst)
{
	int fin=0;
	char *lname=word();
	char *lpass=word();
	struct users *node;
	struct users *user;
	node=*first;
	while(node!=NULL)
	{
		if(strcmp(lname,node->name)==0)
		if(strcmp(lpass,node->pass)==0)
		{
		user=node;
		fin=1;
		}
	node=node->next;
	}
	if(fin==0)
	printf("\nnot found\n");
	else
	{
		printf("\nlog in succesufully :)\n");
		int condition=1;
		while(condition)
	{		
		char *command=word();
		if(strcmp(command,"post")==0)
		{
		posting(user,&pfirst);
		}
		else if(strcmp(command,"like")==0)
		{
		like(*first,*pfirst);
		}
		else if(strcmp(command,"info")==0)
		{
		info(user,*pfirst);
		}
		else if(strcmp(command,"find_user")==0)
		{
		find_user(*first,*pfirst);
		}
		else if(strcmp(command,"delete")==0)
		{
		delete(user,&pfirst);
		}
		else if(strcmp(command,"logout")==0)
		{
		condition=0;
		}
		else 
		{
			printf("\neror\n");
		}
		free(command);
	}
	}
}
void posting (struct users *user,struct post*** pfirst)
{
	int count=2;
	struct post *newpost;
	struct post *node=**pfirst;
	newpost=(struct post*)malloc(sizeof(struct post));
	newpost->next=NULL;
	if(**pfirst==NULL)
	{
	newpost->name=user->name;
	newpost->text=postgive();
	newpost->like=0;
	newpost->post_id=1;
	**pfirst=newpost;
	}
	else
	{
	{
		while(node->next!=NULL)
		{
			node=node->next;
			count++;
		}
	node->next=newpost;
	}
	newpost->name=user->name;
	newpost->text=postgive();
	newpost->post_id=count;
	newpost->like=0;
	}
}
void info (struct users *user,struct post *firstp)
{
	printf("\nname:%s\n",user->name);
	printf("pass:%s\n",user->pass);
	struct post *node=firstp;
	while(node!=NULL)
	{
		if(strcmp(node->name,user->name)==0)
		{
			if(node->text!=NULL)
			{
			printf("text:%s\n",node->text);
			printf("like:%d\n",node->like);
			printf("post_id:%d\n",node->post_id);
			}
		}
	node=node->next;
	}
}
void find_user (struct users *first,struct post *firstp)
{
	int find=1;
	char *name=word();
	struct users *node=first;
	struct post *postnode=firstp;
	while(node!=NULL)
	{
		if(strcmp(node->name,name)==0)
		{   
			find=0;
			printf("\nname:%s\n",name);
			while(postnode!=NULL)
			{
				if(strcmp(postnode->name,node->name)==0)
				{
					printf("text:%s\n",postnode->text);
					printf("like:%d\n",postnode->like);
					printf("post_id:%d\n",postnode->post_id);
				}
			postnode=postnode->next;
			}
		}
		node=node->next;
	}
	if (find==1)
	printf("\nuser not found\n");
	free(name);
}
void like(struct users *first,struct post *firstp)
{
	int done=0;
	char *name=word();
	int postnum;
	scanf("%d",&postnum);
	struct users *node=first;
	struct post *postnode=firstp;
	while(node!=NULL)
	{
		if(strcmp(node->name,name)==0)
		{
			while(postnode!=NULL)
			{
				if(postnum==postnode->post_id)
				{
					(postnode->like)+=1;
					printf("\nliked\n");
					done=1;
				}
			postnode=postnode->next;
			}
		}
	node=node->next;
	}
	if(done!=1)
	printf("\neror\n");
	free(name);
}
/*void delete (struct users *user,struct post ***firstp)
{
	int postnum;
	scanf("%d",&postnum);
	struct post *postnode1;
	postnode1=**firstp;
	struct post *postnode2;
	postnode2=postnode1->next;
	if(postnum==1)
	{
		if(strcmp(postnode1->name,user->name)==0)
		{
		**firstp=postnode2;
		free(postnode1->text);
		free(postnode1);
		printf("\ndeleted\n");
		}
	}
	else
	{
		while (postnode2!=NULL)
		{
			if(strcmp(postnode2->name,user->name)==0)
			{
			if(postnum==postnode2->post_id)
			{
			postnode1->next=postnode2->next;
			free(postnode2->text);
			free(postnode2);
			printf("\ndeleted\n");
			}
			}
			printf("\n1\n");
			postnode1=postnode1->next;
			postnode2=postnode2->next;
		}
	}
}*/
void delete (struct users *user,struct post ***firstp)
{
	int postnum;
	scanf("%d",&postnum);
	struct post *postnode1,*postnode2;
	postnode1=**firstp;
	postnode2=postnode1->next;
	if(postnum==postnode1->post_id)
	{
		if(!strcmp(postnode1->name,user->name))
		{
		**firstp=postnode2;
		free(postnode1->text);
		free(postnode1);
		}
	}
	else
	{
	while (postnode2!=NULL)
	{
			if(postnode2->post_id==postnum)
			{
				if(!strcmp(postnode2->name,user->name))
				{
				postnode1->next=postnode2->next;
				free(postnode2->text);
				free(postnode2);
				}
			}
		postnode1=postnode1->next;
		postnode2=postnode2->next;
		}
	}
}
