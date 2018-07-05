 # ---------------------------------------------INFORMATION--------------------------------------------
 # 	Project Name: Advanced Oriented Programming HW5
 #	Author: Kelvin Lee 李冠霖
 #	Version: 1.0
 #	Environment: Linux
 # 	Date: 2018/06/02  21:12
 # ===================================================================================================*/
SHELL := /bin/bash
CFLAGS := -g -Wall -std=c++11
CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXE = $(wildcard *.exe)

TEST := main

.PHONY: clean cleanobj cleanall dep main

all: dep main

dep: 
	@touch .depend
	@echo creating dependency file...
	@for n in $(SRC); do \
		$(CC) $(CFLAGS) -E -MM $$n >> .depend; \
	done;
-include .depend

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJ) Form trace
	
Form:
	@echo
	@echo \ \ \ [CC] \ \ \ \  $@
	@$(CC) $(CFLAGS) $@.o -o $@.exe
	@echo

Vector:
	@echo
	@echo \ \ \ [CC] \ \ \ \  $@
	@$(CC) $(CFLAGS) $@.o Trace.o main.o -o $@.exe
	@echo

trace:
	@echo
	@echo \ \ \ [CC] \ \ \ \  Vector
	@$(CC) $(CFLAGS) Vector.cpp Trace.cpp main.cpp -o Vector.exe -D __TRACE__
	@echo

clean:
	@rm -f .depend res*

cleanobj:
	@rm -f *.o $(EXE)

cleanall: clean cleanobj

#============================================= Optional =============================================
test:


debug:
	valgrind --leak-check=full ./$(TEST) > /dev/null 2> res2
	valgrind -v --track-origins=yes --leak-check=full ./$(TEST) > /dev/null 2> res3
