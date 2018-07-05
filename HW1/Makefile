 # ---------------------------------------------INFORMATION--------------------------------------------
 # 	Project Name: Advanced Oriented Programming HW1
 #	Author: Kelvin Lee 李冠霖
 #	Version: 1.0
 #	Environment: Linux
 # 	Date: 2017/11/14  03:55
 # ===================================================================================================*/
SHELL := /bin/bash
CFLAGS := -g -Wall
CC = g++
SRC = $(wildcard c/*.c) $(wildcard c++/*.c)
OBJ = $(SRC:.c=.o)
EXE = $(wildcard c/*.exe) $(wildcard c++/*.exe)

TEST :=
DIR := 

.PHONY: clean cleanobj dep main help

all: cleanall dep main

dep:
	@touch .depend
	@echo creating dependency file...
	@for n in $(SRC_C); do \
		$(CC) $(CFLAGS) -E -MM $$n >> .depend; \
	done;
-include .depend

c/%.o: c/%.c
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJ)
	@echo 
	@echo \ \ \ [CC] \ \ \ \  c/main.exe
	@cd c;$(CC) $(CFLAGS) stack.o main.o -o main.exe
	@echo \ \ \ [CC] \ \ \ \  c/main2.exe
	@cd c;$(CC) $(CFLAGS) stack.o main.o -o main2.exe
	@echo
	@echo \ \ \ [CC] \ \ \ \  c++/main.exe
	@cd c++;$(CC) $(CFLAGS) stack.o main.o -o main.exe
	@echo \ \ \ [CC] \ \ \ \  c++/main2.exe
	@cd c++;$(CC) $(CFLAGS) stack.o main.o -o main2.exe
	@echo


clean:
	@rm -f .depend res*

cleanobj:
	@rm -f $(OBJ) $(EXE)

cleanall: clean cleanobj

#============================================= Optional =============================================
test: $(TEST:.c=.o)
	$(CC) $(CFLAGS) $? -o $@.exe

debug:
	valgrind --leak-check=full ./$(DIR)/$(TEST) > /dev/null 2> res2
	valgrind -v --track-origins=yes --leak-check=full ./$(DIR)/$(TEST) > /dev/null 2> res3
