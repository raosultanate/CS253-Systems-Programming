# Author(s)
# 02/02/20 Daniel Rao............................................................jrc
#
#------------------------------------------------------------------------------

#-------Define names of all the object files in this project
	OBJS = sed253.o substitute.o copy.o delete.o

#-------Define the name of the resulting released product
	EXE = sed253

#-------Define options passed by make to the compiler
	CFLAGS = -Wall -std=c99

#-------Define target "all" for building the executable(s)
all:	rules.d $(EXE)

rules.d: Makefile $(wildcard *.c) $(wildcard *.h)
	gcc -MM $(wildcard *.c) >rules.d

#-------Include the rules for rebuilding each *.o file
-include rules.d

#-------Rule for linking the executable product
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

#-------Rule for cleaning build and emacs artifacts
clean:
	rm -f $(OBJS) $(EXE) *.d  *~
