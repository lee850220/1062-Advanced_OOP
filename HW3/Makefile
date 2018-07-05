 # ---------------------------------------------INFORMATION--------------------------------------------
 # 	Project Name: Advanced Oriented Programming HW3
 #	Author: Kelvin Lee 李冠霖
 #	Version: 1.0
 #	Environment: Linux
 # 	Date: 2018/04/28  17:53
 # ===================================================================================================*/
SHELL := /bin/bash
CFLAGS := -g -Wall -std=c++11
CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXE = $(wildcard *.exe)

TEST :=
DIR := 

.PHONY: clean cleanobj dep main help

all: cleanall dep main

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
test: $(TEST:.c=.o)
	$(CC) $(CFLAGS) $? -o $@.exe

debug:
	valgrind --leak-check=full ./$(DIR)/$(TEST) > /dev/null 2> res2
	valgrind -v --track-origins=yes --leak-check=full ./$(DIR)/$(TEST) > /dev/null 2> res3
