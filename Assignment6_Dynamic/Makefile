polyapp: utils.o poly.o polyapp.o
	@gcc -o polyapp polyapp.o poly.o utils.o
utils.o: utils.c 
	@gcc -c utils.c
poly.o: poly.c utils.h
	@gcc -c poly.c
polyapp.o: polyapp.c poly.h utils.h
	@gcc -c polyapp.c

