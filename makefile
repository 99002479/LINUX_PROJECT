all:	m_send	m_receive	s_send	s_receive

m_send:	mutex_send.c
	gcc mutex_send.c -o mutex_send -lpthread

m_receive:	mutex_receive.c
	gcc mutex_receive.c -o mutex_receive -lpthread

s_send:	sem_send.c
	gcc sem_send.c -o sem_send -lpthread

s_receive:	sem_receive.c 
	gcc sem_receive.c -o sem_receive -lpthread

