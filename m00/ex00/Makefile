NAME		=	megaphone

SRCS		=	megaphone.cpp

CPP			=	c++

CPP_FLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

all		:	$(NAME)

$(NAME)	:	$(SRCS)
		$(CPP) $(CPP_FLAGS) $(SRCS) -o $(NAME)

clean	:
		@$(RM) $(NAME)
		@echo "\033[1;38;5;221m*  $(NAME) removed\033[0m"

fclean	:	clean

re		:	fclean $(NAME)

.PHONY: all clean fclean re
