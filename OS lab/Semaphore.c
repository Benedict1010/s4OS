#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int mutex=1,full=0,empty=MAX,x=0; 
int main()
{ 
	int n; 
	int buffer[MAX];
	void producer(); 
	void consumer(); 
	int wait(int); 
	int signal(int); 
	printf("\n1.Producer\n2.Consumer\n3.Exit\n"); 
	
	while(1) { 
		printf("\nEnter your choice\n"); 
		scanf("%d",&n); 
	switch(n) {
		case 1:
		if((mutex==1)&&(empty!=0)) 
		producer(); 
		else
		printf("Buffer is full\n"); 
		break; 

		case 2:
		if((mutex==1)&&(full!=0))
		consumer();
		else
		printf("Buffer is empty\n");
		break;
	
		case 3:
		exit(0);
		break;
		}
	}
}

int wait(int s) {
	return(--s);
}
	
int signal(int s) {
	return(++s);
}
	
void producer() {
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\nProducer produces the item: %d",x);
	mutex=signal(mutex);
}

void consumer() {
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes item: %d",x);
	x--;
	mutex=signal(mutex);
}
