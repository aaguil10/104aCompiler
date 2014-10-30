# $Id: Makefile,v 1.8 2014-10-07 17:37:02-07 - - $

GPP   = g++ -g -O0 -Wall -Wextra -std=gnu++11
GRIND = valgrind --leak-check=full --show-reachable=yes
LSOURCES = scanner.l
YSOURCES = parser.y
CLGEN = yylex.cpp
HYGEN = yyparse.h
CYGEN = yyparse.cpp
LREPORT = yylex.output
YREPORT = yyparse.output

all : oc

oc : ${CLGEN} ${HYGEN} ${CYGEN} main.o stringset.o cppstrtok.o auxlib.o \
     astree.o lyutils.o
	${GPP} main.o stringset.o cppstrtok.o auxlib.o astree.o \
               lyutils.o -o oc

%.o : %.cpp
	${GPP} -c $<

ci :
	git add .
	git commit
	#cid + Makefile stringset.h stringset.cpp main.cpp

spotless : clean
	- rm oc
	- rm yylex.cpp
	- rm yyparse.cpp
	- rm yyparse.h
	- rm yylex.output
	- rm yyparse.output

clean :
	-rm stringset.o main.o cppstrtok.o auxlib.o astree.o lyutils.o
	#rm *.oc
	#rm *.oc.err
	#rm *.oc.out
	#rm *.str

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

## Build the scanner.
${CLGEN} : ${LSOURCES}
	flex --outfile=${CLGEN} ${LSOURCES} 2>${LREPORT}
	- grep -v '^  ' ${LREPORT}

## Build the parser.
${CYGEN} ${HYGEN} : ${YSOURCES}
	bison --defines=${HYGEN} --output=${CYGEN} ${YSOURCES}



# Depencencies.
main.o: main.cpp stringset.h
stringset.o: stringset.cpp stringset.h
auxlib.o: auxlib.cpp auxlib.h
cppstrtok.o: cppstrtok.cpp cppstrtok.h auxlib.h
astree.o: astree.h astree.cpp
lyutils.o: lyutils.h lyutils.cpp
