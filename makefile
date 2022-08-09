Server_new: open62541.o Server_new.o
		gcc open62541.o Server_new.o -o Server_new
open62541.o: open62541.c
		gcc -c -std=c99 open62541.c -o open62541.o
Server_new.o: Server_new.c
		gcc -c Server_new.c
clean:
		rm *.o Server_new
run:
		./Server_new
