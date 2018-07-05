 # ---------------------------------------------INFORMATION--------------------------------------------
 # 	Project Name: Advanced Oriented Programming HW4
 #	Author: Kelvin Lee 李冠霖
 #	Version: 1.0
 #	Environment: Linux
 # 	Date: 2018/05/18  20:02
 # ===================================================================================================*/
SHELL := /bin/bash
CFLAGS := -g -Wall -std=c++14
CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXE = $(wildcard *.exe)

ARGS := test1.txt
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

main: $(OBJ)
	@echo 
	@echo \ \ \ [CC] \ \ \ \  $@
	@$(CC) $(CFLAGS) $(OBJ) -o $@	
	@echo

clean:
	@rm -f .depend res*

cleanobj:
	@rm -f *.o main

cleanall: clean cleanobj

#============================================= Optional =============================================
test:
	@./main test1.txt > res1
	@./main test2.txt > res2

compare:
	@diff res1 r1.txt -y; [ $$? -eq 1 ]
	@echo
	@echo "Press any key to continue"
	@read -n 1 -s -r
	@diff res2 r2.txt -y; [ $$? -eq 1 ]

debug:
	valgrind --leak-check=full ./$(TEST) $(ARGS) > /dev/null 2> res2
	valgrind -v --track-origins=yes --leak-check=full ./$(TEST) $(ARGS) > /dev/null 2> res3
