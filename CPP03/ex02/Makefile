# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 16:34:55 by juan-ant          #+#    #+#              #
#    Updated: 2025/09/26 18:21:22 by juan-ant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -std=c++98

COMPILER = c++

NAME = FragTrap

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ = $(FILES:%.cpp=%.o)

BLACK          	=   \033[0;30m
FBLACK          =   \033[1;30m
RED             =   \033[0;31m
FRED            =   \033[1;31m
GREEN           =   \033[0;32m
FGREEN          =   \033[1;32m
BROWNO    		=   \033[0;33m
FBROWNO		   	=   \033[1;33m
FYELLOW         =   \033[1;33m
YELLOW          =   \033[0;33m
BLUE            =   \033[0;34m
FBLUE           =   \033[1;34m
PURPLE          =   \033[0;35m
FPURPLE         =   \033[1;35m
CYAN            =   \033[0;36m
FCYAN           =   \033[1;36m
FWHITE          =   \033[1;37m
WHITE           =   \033[0;37m
RESET           =   \033[0m

all: $(NAME)

$(NAME): $(FILES) $(OBJ)
	@echo "$(CYAN) Compiling $(OBJ) into $(NAME)...$(RESET)"
	$(COMPILER) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(CYAN) 👍 Done compiling 👍$(RESET)"

%.o: %.cpp
	@echo "$(CYAN) Compiling $< into $@...$(RESET)"
	$(COMPILER) $(FLAGS) -MMD -o $@ -c $< 

clean:
	@echo " $(YELLOW)Cleaning $(OBJ) and $(OBJ:.o=.d) ...$(RESET)"
	rm -f $(OBJ) $(OBJ:.o=.d)
	@echo "$(YELLOW) 🧹 Done cleaning 🧹$(RESET)"

fclean: clean
	@echo " $(YELLOW)Cleaning $(NAME)...$(RESET)"
	rm -f $(NAME)
	@echo "$(YELLOW) 🧹 Done cleaning 🧹$(RESET)"


re: fclean all

.PHONY: clean
.PHONY: fclean
.PHONY: re
.PHONY: all

-include $(OBJ:.o=.d)
