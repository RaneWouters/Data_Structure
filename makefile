TARGET = demo
CC = clang++
OBJS = demo.o
$(TARGET): $(OBJS)
	$(CC) $^ -o $@
%.o: %.cpp 
	$(CC) -c $<
clean:
	rm *.o demo
