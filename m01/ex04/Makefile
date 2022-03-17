NAME		=	replace

SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)

D_FILES		=	$(SRCS:.cpp=.d)

CPP			=	c++

CPP_FLAGS	=	-Wall -Wextra -Werror -std=c++98

INCLUDES	=	-I.

RM			=	rm -f

REPLACE_F	=	*.replace

############## Design ##############

COL_RM		=	\033[1;38;5;221m
COL_TEST	=	\033[0;38;5;111m
COL_END		=	\033[0m

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CPP) $(CPP_FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
		$(CPP) $(CPP_FLAGS) $(INCLUDES) -c $< -o $@ -MMD -MP

include $(wildcard $(D_FILES))

clean	:
		@$(RM) $(OBJS) $(D_FILES)
		@echo "$(COL_RM)*  $(OBJS) $(D_FILES) removed$(COL_END)"

fclean	:	clean
		@$(RM) $(NAME) $(REPLACE_F)
		@echo "$(COL_RM)*  $(REPLACE_F) removed$(COL_END)"
		@echo "$(COL_RM)*  $(NAME) removed$(COL_END)"

re		:	fclean $(NAME)

############## with -i flag ##############

test	: all
		@echo
		@echo "> 1 $(COL_TEST)./replace Hihi$(COL_END)"
		@./replace Hihi
		@echo
		@echo "> 2 $(COL_TEST)./replace Hihi 1 2$(COL_END)"
		@./replace Hihi 1 2
		@echo
		@echo "> 3 $(COL_TEST)./replace test_file1 Hello Bye$(COL_END)"
		@./replace test_file1 Hello Bye
		@echo
		@echo "> 4 $(COL_TEST)./replace test_file2 Hello Bye$(COL_END)"
		@./replace test_file2 Hello Bye
		@echo
		@echo "> 5 $(COL_TEST)./replace test_forbidden Hello Bye$(COL_END)"
		@./replace test_forbidden Hello Bye
		@echo
		@echo "> 6 $(COL_TEST)./replace test_file3 \"I'd like to go\" \"I've actually been\"$(COL_END)"
		@./replace test_file3 "I'd like to go" "I've actually been"
		@echo
		@echo "> 7 $(COL_TEST)./replace test_file4 football tennis$(COL_END)"
		@./replace test_file4 football tennis
		@echo

.PHONY: all clean fclean re
