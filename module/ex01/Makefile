NAME		=	myphonebook

SRCS		=	MyPhonebook.cpp		PhoneBook.cpp	Contact.cpp

OBJS		=	$(SRCS:.cpp=.o)

D_FILES		=	$(SRCS:.cpp=.d)

CPP			=	c++

CPP_FLAGS	=	-Wall -Wextra -Werror -std=c++98

INCLUDES	=	-I.

RM			=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CPP) $(CPP_FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
		$(CPP) $(CPP_FLAGS) $(INCLUDES) -c $< -o $@ -MMD -MP

include $(wildcard $(D_FILES))

clean	:
		@$(RM) $(OBJS) $(D_FILES)
		@echo "\033[1;38;5;221m*  $(OBJS) $(D_FILES) removed\033[0m"

fclean	:	clean
		@$(RM) $(NAME)
		@echo "\033[1;38;5;221m*  $(NAME) removed\033[0m"

re		:	fclean $(NAME)

.PHONY: all clean fclean re
