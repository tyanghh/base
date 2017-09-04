#
# makefile for ccalc
#
MYINC=-I../util/include -I./ 

ALL_INC= -I./ $(MYINC)

OBJS += ccalc.o cmath.o lex.o parse.o 
HASH_OBJS += hash_map.o
MAP_OBJS += map.o
UNORDERED_OBJS += unordered_map.o

# rules
%.c: %.y
	bison -o $(@:%.o=%.d) $<

%.c: %.l
	flex -o$(@:%.o=%.d) -i $<

all: hash_map map unordered_map

# dependencies
ccalc: parse.c lex.c parse.h $(OBJS)
	@echo gcc -occalc $(OBJS)
	@gcc  -occalc $(OBJS)
	@echo ' '

hash_map: $(HASH_OBJS)
	g++ -o hash_map $(HASH_OBJS)

map: $(MAP_OBJS)
	g++ -o map $(MAP_OBJS)

unordered_map: $(UNORDERED_OBJS)
	g++ --std=gnu++0x -o unordered_map $(UNORDERED_OBJS)

# source
hash_map.o: hash_map.cpp

map.o: map.cpp

unordered_map.o: unordered_map.cpp
	g++ --std=gnu++0x -c unordered_map.cpp

ccalc.o: ccalc.c parse.h ccalc.h

cmath.o: cmath.c parse.h ccalc.h

lex.o: lex.c parse.h ccalc.h

parse.o: parse.c parse.h ccalc.h

parse.c: parse.y

lex.c: lex.l

	 
.SUFFIXES: .o .cpp .so .a
.c.o:
	$(GCC) $(ALL_INC)  $(CFLAGS) -c $^ -o $@

.cc.o:
	$(CXX) $(ALL_INC)  $(CFLAGS) -c $^ -o $@

.cpp.o:
	$(CXX) $(ALL_INC)  $(CFLAGS) -c $^ -o $@

.o.so:	
	g++ -Wall -shared -fPIC -o lib$@ $^ $(ALL_LIB)
	
.o.a:	
	$(AR) -crl lib$@ $^

.o:
	$(CXX) $(CFLAGS) -o $@ $^  $(ALL_LIB)

.PHONY:
clean:
	-rm -rf *.o

