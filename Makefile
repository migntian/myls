.PHONY : clean

myls : myls.o
	gcc -g $^ -o $@
%.o : %.c
	gcc -c $^ -o $@
clean :
	rm *.o myls 
