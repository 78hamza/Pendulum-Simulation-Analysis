CFLAGS = -Wall -Wextra -Werror
CC = gcc
LDFLAGS = -lm

# projet name
TARGET = program

# source files
SRCS = main.c lst.c pendulum.c print.c energy.c ft_itoa.c
OBJS = $(SRCS:.c=.o)

# default target
all: $(TARGET)

# LINK object  files to create executable 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# compile source file s to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean up build artifiacts
clean:
	rm -f $(OBJS) $(TARGET)

