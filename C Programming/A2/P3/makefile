OBJS = main.o sinc.o 
CFLAGS = -Wall -O2
sinc.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $? -lm
clean:
	rm $(OBJS) sinc.exe
 
