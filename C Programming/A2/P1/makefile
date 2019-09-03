OBJS = main.o checkresult.o gendata.o linsolve.o
CFLAGS = -Wall -O3
linsolve.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $? -lm
clean:
	rm $(OBJS) linsolve.exe
