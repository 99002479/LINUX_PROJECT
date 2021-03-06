// BUS TRACKING SYSTEM
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>

sem_t s; 
int time1=1, time2=2;

struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message;

void* s_receiver(void* arg) 
{ 
	key_t key; 
	int msgid;

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 
	message.mesg_type = 1; 

	//wait 
	sem_wait(&s); 

	// msgrcv to receive message 
	msgrcv(msgid, &message, sizeof(message), 1, 0); 

	// display the message 
	printf("The no. buses entering the bus stand from %d to %d: %s\n",time1, time2, message.mesg_text); 
	time1++;
	time2++;

	sem_post(&s); 
} 


int main() 
{ 
	sem_init(&s, 0, 1); 
	pthread_t t1,t2,t3,t4,t5; 
	pthread_create(&t1,NULL,s_receiver,NULL); 
	pthread_create(&t2,NULL,s_receiver,NULL);
	pthread_create(&t3,NULL,s_receiver,NULL);
	pthread_create(&t4,NULL,s_receiver,NULL);
	pthread_create(&t5,NULL,s_receiver,NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	sem_destroy(&s); 
	return 0; 
} 

