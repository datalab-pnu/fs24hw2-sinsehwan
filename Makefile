CC=g++
all=main
OBJS = main.o student.o courseRegistration.o

%.o : %.cpp
	$(CC) -c -o $@ $<
main : $(OBJS)
	$(CC) -o main $(OBJS)
clean:
	rm -f main $(OBJS)
