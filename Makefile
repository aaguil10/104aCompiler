# $Id: Makefile,v 1.8 2014-10-07 17:37:02-07 - - $

GPP   = g++ -g -O0 -Wall -Wextra -std=gnu++11
GRIND = valgrind --leak-check=full --show-reachable=yes

all : oc

oc : main.o stringset.o cppstrtok.o auxlib.o
	${GPP} main.o stringset.o cppstrtok.o auxlib.o -o oc

%.o : %.cpp
	${GPP} -c $<

ci :
	git add .
	git commit
	#cid + Makefile stringset.h stringset.cpp main.cpp

spotless : clean
	- rm oc

clean :
	-rm stringset.o main.o cppstrtok.o auxlib.o
	rm *.oc
	rm *.oc.err
	rm *.oc.out
	rm *.str

test : oc
	#${GRIND} oc * * * >test.out 2>test.err
	./oc -ly -@ Set_debugflags -D OCLIB_OH oc-programs/03-test3.oc 


lis : test
	mkpspdf Listing.ps stringset.h stringset.cpp main.cpp \
	        Makefile test.out test.err

submit : main.cpp stringset.cpp stringset.h auxlib.cpp auxlib.h \
         cppstrtok.cpp cppstrtok.h Makefile oclib.c oclib.oh README
	submit cmps104a-wm.f14 asg1 main.cpp stringset.cpp \
        stringset.h auxlib.cpp auxlib.h cppstrtok.cpp cppstrtok.h \
        Makefile oclib.c oclib.oh README
# Depencencies.
main.o: main.cpp stringset.h
stringset.o: stringset.cpp stringset.h
auxlib.o: auxlib.cpp auxlib.h
cppstrtok.o: cppstrtok.cpp cppstrtok.h auxlib.h

