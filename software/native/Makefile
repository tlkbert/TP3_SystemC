CC=gcc
INCLUDE=-I. -I../../
CFLAGS=$(INCLUDE)

main.o: ../main.c  ../../address_map.h ../../hardware/offsets/*.h
	$(CC) -c ../main.c $(CFLAGS)
	
.PHONY: clean realclean
clean:
	$(RM) main.o

realclean: clean
	-$(RM) *~

