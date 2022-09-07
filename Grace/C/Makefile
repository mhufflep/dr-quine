.PHONY: clean fclean re all makedir test

NAME = Grace

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
SRCS_LIST    = Grace.c
OUTPUT		 = Grace_kid.c
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
	@rm -rf ${OUTPUT}
	@rm -rf ${DIFF_FILE}

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@rm ${OUTPUT} || exit 0
	@./${NAME}
	@diff ${SRCS_LIST} ${OUTPUT} > ${DIFF_FILE} || exit 0
	@if ! [ -s ${DIFF_FILE} ] ; then \
		echo "Test: OK" ; \
		rm -rf ${DIFF_FILE} ; \
	else \
		echo "Test: KO, see ${DIFF_FILE}" ; \
	fi ; \
