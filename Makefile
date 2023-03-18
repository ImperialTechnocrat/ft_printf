NAME = printf

CC = gcc

FLAGS = -Wall

SOURCE = ft_format.c ft_helper.c ft_numberprocess.c ft_pointerprint.c ft_printf.c main.c

OBJECT = $(SOURCE:.c=.o)
DEPS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT) $(NAME)
