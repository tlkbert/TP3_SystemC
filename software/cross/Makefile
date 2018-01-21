ifndef CROSS_COMPILE
CROSS_COMPILE=microblaze-xilinx-linux-gnu-
endif

TARGET_CC = $(CROSS_COMPILE)gcc
TARGET_LD = $(CROSS_COMPILE)ld
TARGET_OBJDUMP = $(CROSS_COMPILE)objdump
TARGET_READELF = $(CROSS_COMPILE)readelf
HOST_CC = gcc
HOST_LD = ld
HOST_OBJDUMP = objdump
HOST_READELF = readelf

INCLUDE = -I. -I../..
CFLAGS=$(INCLUDE)

OBJS = main.o boot.o it.o
EXEC = a.out

# Disassembly of the generated executable.
dump.dis: $(EXEC)
	$(TARGET_OBJDUMP) -d $< > $@

# Summary of the sections and their size.
sections.txt: $(EXEC)
	$(TARGET_READELF) -S $< > $@


$(EXEC): $(OBJS)
	@$(TARGET_LD) -T ldscript $^

main.o:: ../main.c hal.h 
	@$(TARGET_CC) -c $^ $(INCLUDE)
	@$(HOST_CC) -MM ../$*.c $(INCLUDE) > $*.d

%.o: %.s
	$(TARGET_CC) -c $< 

.PHONY: clean realclean
clean:
	-$(RM) $(OBJS) $(EXEC) dump.dis sections.txt

realclean: clean
	-$(RM) *~
