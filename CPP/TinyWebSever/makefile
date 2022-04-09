CC = g++

LIB = -pthread

all: webserver

webserver: webServer.c locker.h thread_pool.h task.h macro.h
	$(CC) -o a.out webServer.c locker.h thread_pool.h task.h macro.h $(LIB)
	cp a.out /home/aiden/workSpace/webServer/
clean:
	rm -f *.o *~ *.out /home/aiden/workSpace/webServer/a.out