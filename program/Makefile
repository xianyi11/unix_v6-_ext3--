#
# Makefile for Unix V6++ Shell
#

#命令定义
CC = gcc
LD = ld
OBJDUMP = objdump

#参数定义-nostartfiles
CFLAGS = -w -O0 -g -nostdlib -nostartfiles -nostdinc -fno-builtin -fno-exceptions

#目录定义
TARGET = .\objs
V6++LIB = "..\lib\Lib_V6++.a"
INCLUDE = .
LIB_INCLUDE = ..\lib\include

MAKEIMAGEPATH = ..\..\tools\MakeImage\bin\Debug\programs
#DEMO = demo
BIN = bin

.PHONY : all

SHELL_OBJS =$(TARGET)\cat.exe	\
			$(TARGET)\cp.exe	\
			$(TARGET)\ls.exe	\
			$(TARGET)\mkdir.exe	\
			$(TARGET)\rm.exe	\
			$(TARGET)\perf.exe	\
			$(TARGET)\sig.exe \
			$(TARGET)\copyfile.exe	\
			$(TARGET)\shutdown.exe	\
			$(TARGET)\test.exe	\
			$(TARGET)\forks.exe	\
			$(TARGET)\trace.exe	\
			$(TARGET)\echo.exe	\
			$(TARGET)\date.exe \
			$(TARGET)\newsig.exe \
			$(TARGET)\sigTest.exe \
			$(TARGET)\stack.exe	\
			$(TARGET)\malloc.exe \
			$(TARGET)\testSTDOUT.exe \
			$(TARGET)\fork.exe \
			$(TARGET)\TestGetFileName.exe \
			$(TARGET)\mycat.exe \
			$(TARGET)\pwd.exe \
			$(TARGET)\recover.exe
#$(TARGET)\performance.exe
			
#all	:	build
all	:	clean  build

build : $(SHELL_OBJS)

$(TARGET)\cat.exe :	cat.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\cat.exe $(MAKEIMAGEPATH)\$(BIN)\cat
	
$(TARGET)\cp.exe :	cp.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\cp.exe $(MAKEIMAGEPATH)\$(BIN)\cp
	
$(TARGET)\ls.exe :	ls.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\ls.exe $(MAKEIMAGEPATH)\$(BIN)\ls
	
$(TARGET)\mkdir.exe :	mkdir.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\mkdir.exe $(MAKEIMAGEPATH)\$(BIN)\mkdir
	
$(TARGET)\perf.exe :	performance.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\perf.exe $(MAKEIMAGEPATH)\$(BIN)\perf
	
$(TARGET)\rm.exe :	rm.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\rm.exe $(MAKEIMAGEPATH)\$(BIN)\rm
	
$(TARGET)\copyfile.exe :	copyfile.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\copyfile.exe $(MAKEIMAGEPATH)\$(BIN)\copyfile
	
$(TARGET)\shutdown.exe :	shutdown.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\shutdown.exe $(MAKEIMAGEPATH)\$(BIN)\shutdown

$(TARGET)\test.exe :	test.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\test.exe $(MAKEIMAGEPATH)\$(BIN)\test
	
$(TARGET)\forks.exe :		forks.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\forks.exe $(MAKEIMAGEPATH)\$(BIN)\forks
	
$(TARGET)\sig.exe :		sig.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\sig.exe $(MAKEIMAGEPATH)\$(BIN)\sig

$(TARGET)\sigTest.exe :		sigTest.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\sigTest.exe $(MAKEIMAGEPATH)\$(BIN)\sigTest
	
$(TARGET)\trace.exe :		trace.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\trace.exe $(MAKEIMAGEPATH)\$(BIN)\trace
	
$(TARGET)\echo.exe :		echo.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\echo.exe $(MAKEIMAGEPATH)\$(BIN)\echo
	
$(TARGET)\date.exe :		date.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\date.exe $(MAKEIMAGEPATH)\$(BIN)\date
	
$(TARGET)\newsig.exe :		newsig.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\newsig.exe $(MAKEIMAGEPATH)\$(BIN)\newsig
	
$(TARGET)\stack.exe :		stack.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\stack.exe $(MAKEIMAGEPATH)\$(BIN)\stack
	
$(TARGET)\malloc.exe :		malloc.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\malloc.exe $(MAKEIMAGEPATH)\$(BIN)\malloc

$(TARGET)\fork.exe :		fork.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\fork.exe $(MAKEIMAGEPATH)\$(BIN)\fork

$(TARGET)\testSTDOUT.exe :	testSTDOUT.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\testSTDOUT.exe $(MAKEIMAGEPATH)\$(BIN)\testSTDOUT
	
$(TARGET)\TestGetFileName.exe :	TestGetFileName.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\TestGetFileName.exe $(MAKEIMAGEPATH)\$(BIN)\TestGetFileName
	
$(TARGET)\mycat.exe :	mycat.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\mycat.exe $(MAKEIMAGEPATH)\$(BIN)\mycat
	
$(TARGET)\pwd.exe :	pwd.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\pwd.exe $(MAKEIMAGEPATH)\$(BIN)\pwd
	
$(TARGET)\recover.exe :	recover.c
	$(CC) $(CFLAGS) -I"$(INCLUDE)" -I"$(LIB_INCLUDE)"  $< -e _main1 $(V6++LIB) -o $@
	copy $(TARGET)\recover.exe $(MAKEIMAGEPATH)\$(BIN)\recover
clean:
	del $(TARGET)\*.*
	del $(MAKEIMAGEPATH)\$(BIN)\*.*
	

	