CC = gcc
target1 = main
object1 = main.c

$(target1) : $(object1)
	$(CC) $(object1) -o $(target1) -Wall 

.PHONY : clean
clean :
	rm -rf $(target1)
