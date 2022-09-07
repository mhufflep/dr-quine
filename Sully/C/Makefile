.PHONY: clean fclean re all makedir test

NAME = Sully

###################################################################################
#                               Compiler & Flags                                  #
###################################################################################

CC      =   clang
CFLAGS  =   -Wall -Wextra -Werror
# DEBUG     = 1

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

###################################################################################
#                              Directories & Files                                #
###################################################################################

SRCS_DIR     = .
OBJS_DIR     = .obj
TEST_DIR     = tmp
SRCS_LIST    = Sully.c
DIFF_FILE	 = ${NAME}.diff

SRCS  = $(addprefix $(SRCS_DIR)/, ${SRCS_LIST})
OBJS  = $(addprefix $(OBJS_DIR)/, ${SRCS_LIST:.c=.o})

###################################################################################
#                                   Commands                                      #
###################################################################################

all: makedir $(NAME)
	
makedir:
	@if ! [ -d ${OBJS_DIR} ] ; then mkdir ${OBJS_DIR} ; fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${NAME} assembled"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf ${TEST_DIR}

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	mkdir -p ${TEST_DIR}; cp ${NAME} ${TEST_DIR}/; cd ${TEST_DIR}/; ./${NAME} ; ls -al | grep ${NAME} | wc -l
