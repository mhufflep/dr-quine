.PHONY: clean fclean re all makedir test

NAME = Sully

###################################################################################
#                               Compiler & Flags                                  #
###################################################################################

CC      =   clang
CFLAGS  =   -Wall -Wextra -Werror
#DEBUG  = 1

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

###################################################################################
#                              Directories & Files                                #
###################################################################################

SRCS_DIR     = .
OBJS_DIR     = .obj
TEST_DIR     = tmp
SRC_FILE     = Sully.c

SRCS  = $(addprefix $(SRCS_DIR)/, ${SRC_FILE})
OBJS  = $(addprefix $(OBJS_DIR)/, ${SRC_FILE:.c=.o})

###################################################################################
#                                   Commands                                      #
###################################################################################

all: makedir $(NAME)
	
makedir:
	@if ! [ -d ${OBJS_DIR} ] ; then mkdir ${OBJS_DIR} ; fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${NAME} is ready"

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

test2:
	@cd ${TEST_DIR} && diff ../${SRC_FILE} ${NAME}_5.c || exit 0
	@cd ${TEST_DIR} && diff ../${SRC_FILE} ${NAME}_4.c || exit 0
	@cd ${TEST_DIR} && diff ${NAME}_5.c ${NAME}_0.c || exit 0
