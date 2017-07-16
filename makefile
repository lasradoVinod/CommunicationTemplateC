ROOT = $(shell pwd)
SRC = main.c \
	Communication.c \
	Serial.c \
	Udp.c

OBJDIR = $(ROOT)/obj
CC = gcc

CFLAGS = -Wall -Wconversion -Werror -O3 -std=c11

# Generate dependency information
CFLAGS += -MD -MP -MF .dep/$(@F).d

LIBDIR = 
LIB = 
VPATH = ./src
INC = ./inc

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRC)))
LIBDIRS = $(patsubst %,-L%,$(LIBDIR))
LIBS = $(patsubst %,-l%,$(LIB))
INCS  = $(patsubst %,-I%,$(INC))

.PHONY: clean

execute: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(INCS) $(LIBDIRS) -o execute $(LIBS)

clean:
	rm $(ROOT)/obj/*

$(OBJDIR)/%.o: %.c
	@echo Compiling $@ $< ...
	mkdir -p $(OBJDIR)
	$(CC) -c $(CXFLAGS) $(INCS) $(LIBDIRS) $< -o $@ $(LIBS)

# Include the dependency files
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
