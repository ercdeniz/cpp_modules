NAME    = intern

CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = .objFiles

FILES		= main  Bureaucrat  AForm  PresidentialPardonForm  RobotomyRequestForm  ShrubberyCreationForm  Intern

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

GITIGNORE_EXISTS := $(shell grep -Fxq "$(NAME)" ../.gitignore && echo "yes" || echo "no")

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[92m   - Compiling $(NAME)...\033[0m"
	@$(CC) $(OBJ) -o $(NAME)
	@cp $(NAME) ../
	@if [ "$(GITIGNORE_EXISTS)" = "no" ]; then \
		echo $(NAME) >> ../.gitignore; \
	fi
	@printf "\n\033[92m   Working... \033[0m\n  "
	@printf "\033[92m █"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.3
	@clear
	@printf "\n\033[96m   Built 🛠 \033[0m\n\n"
	@echo " GitHub    ~>  \033[4;1;34mgithub.com/ercdeniz\033[0m"
	@echo " 42 Intra  ~>  \033[4;1;34mercdeniz\033[0m\n"
	@echo "\033[96m    - Executable ready-> ./$(NAME)\033[0m\n"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@clear
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "\n\033[91m   Deleting... \033[0m\n  "
	@printf "\033[91m █"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@printf "█"
	@sleep 0.001
	@clear
	@echo "\033[95m    - ⛔️ Executable removed-> $(NAME)\033[0m\n"
	@sleep 0.3
	@clear

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)
	@$(RM) *.shrubbery
	@$(RM) ../*.shrubbery
	@$(RM) *.dSYM
	@echo "\033[92m    - Cleanup Over.✅\033[0m"
	@sleep 0.3
	@clear

re: fclean all

.PHONY: all clean fclean re