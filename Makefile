CC= gcc
CFLAGS = -g
TARGET = p0
OBJS = tree.o main.o

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
tree.o: tree.h
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm *.o *.preorder *.postorder *.inorder $(TARGET)

