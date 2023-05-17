NAME		=		megaphone

#######################
#	DIR
#######################

SRC_DIR		=		./

INC_DIR		=		./

BUILD_DIR	=		.build/

#######################
#	FILES
#######################

SRC			=		megaphone.cpp

OBJ			=		$(addprefix $(BUILD_DIR), $(SRC:.cpp=.o))

DEPS		=		$(addprefix $(BUILD_DIR), $(OBJ:.o=.d))

#######################
#	FLAGS
#######################

CFLAGS		=		-Wall -Werror -Wextra -std=c++98

IFLAGS		=		-I $(INC_DIR)

DFLAGS		=		-MMD -MP

#######################
#	RULES
#######################

############
#	GENERAL
############

.PHONY:				all
all:				$(NAME)

.PHONY:				clean
clean:
					$(RM) $(OBJ) $(DEPS)

.PHONY:				fclean
fclean:
					$(RM) $(OBJ) $(DEPS) $(NAME)

.PHONY:				re
re:					fclean
					$(MAKE)

################
#	EXECUTABLES
################

-include			$(DEPS)

$(NAME):			$(OBJ)
					$(CXX) $(CFLAGS) $(DFLAGS) $(IFLAGS) $^ -o $@

##################
#	OBJECTS FILES
##################

$(BUILD_DIR)%.o:	$(SRC_DIR)%.cpp
					mkdir -p $(shell dirname $@)
					$(CXX) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@