#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* word()
{
	char ch;
	int count=0;
	char *array=(char*)realloc(NULL,sizeof(char));
	ch=getche();
	do
	{
		array=(char*)realloc(array,sizeof(char)*(count+1));
		*(array+count)=ch;
		count++;
		ch=getche();
	}while(ch!=' ');
	array[count]='\0';
	return array;
}
char* postgive()
{
	char ch;
	char *string;
	ch=getchar();
	unsigned int counter=0;
	string=(char*)malloc(2);
	while(ch!=10)
	{	
		string=(char*)realloc(string,sizeof(char)*(counter+1));
		*(string+counter)=ch;
		counter++;
		ch=getchar();
	}
	string[counter]='\0';
	return string;
}

