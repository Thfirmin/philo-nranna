NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

DFLAGS =

INC_DIR = include

IFLAGS = $(addprefix -I ,$(INC_DIR))

SRC_DIR = src

SRC_FILE = main.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILE))

OBJS = $(SRCS:.c=.o)

.DEFAULT_GOAL: all

all:	$(NAME)

dev:	DFLAGS=-g

dev:	re

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) -o $(NAME)

clean:
ifneq (,$(shell ls $(OBJS) 2>/dev/null))
	rm -f $(OBJS)
endif

fclean:	clean
ifneq (,$(shell ls $(NAME) 2>/dev/null))
	rm -f $(NAME)
endif

re:	fclean all

.c.o:
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $(<:.c=.o)

.PHONY: all clean fclean re dev
