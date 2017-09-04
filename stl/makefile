#
# makefile for ccalc
#




MYINC=-I./util/include -I./ 

ALL_INC= -I./ $(MYINC)


INIT_OBJ_S += init.o

	 
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




all: init 


init: $(INIT_OBJ_S)
	g++ -o $@ $(INIT_OBJ_S)


.PHONY:
clean:
	-rm -rf *.o




