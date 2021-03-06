## Badges
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/72cceab773124daf9fdc91433df56ebf)](https://app.codacy.com/gh/99002479/LINUX_PROJECT?utm_source=github.com&utm_medium=referral&utm_content=99002479/LINUX_PROJECT&utm_campaign=Badge_Grade)
![C/C++ CI](https://github.com/99002479/LINUX_PROJECT/workflows/C/C++%20CI/badge.svg)
![cppcheck-action](https://github.com/99002479/LINUX_PROJECT/workflows/cppcheck-action/badge.svg)

# LINUX MINIPROJECT

The aim of the project is to create a bus tracking system in the bus stand in which the input of how many buses coming inside the bus stand at a particular time frame (1 hour) is given and send to the receiver. We are using a structure as a data type which holds the message type and no.of buses. This object is input through the mutex_send.c/sem_send.c and reaches the mutex_receive.c/sem_receive.c through IPC. This IPC is used in Mutex and Semaphore methods and the objects gets locked and unlocked during the critical section of the execution.

## Mutex with Message Queue : Refer to mutex_send.c and mutex_receive.c

    pthread_mutex_lock(&lock); is used for locking.
    pthread_mutex_unlock(&lock); is used for unlocking.
    pthread_mutex_destroy(&lock); is used for destroying.
    
## Semaphore with Message Queue : Refer to sem_send.c and sem_receive.c

    sem_wait(&s) for lock/wait.
    sem_post(&s) for releasing the lock.
    sem_destroy(&s) for destroying.

**********************************************************************************************************************************************************************
## IMPLEMENTATION

### MUTEX
1) Goto the bus_mutex folder	-	cd bus_mutex
2) Run the makefile		-	make
3) Run the sender object file 	- 	./mutex_send
4) Give 5 inputs.
5) Run the receiver object file - 	./mutex_receive
6) O/P will be displayed.

### SEMAPHORE
1) Goto the bus_sem folder	-	cd bus_sem
2) Run the makefile 		- 	make
3) Run the sender object file	-> 	./sem_send
4) Give 5 inputs
5) Run the receiver object file -> 	./sem_receive
6) O/P will be displayed.

**********************************************************************************************************************************************************************
