.PHONY: clean fclean re all makedir

NAME = Colleen

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
SRC_FILE    = Colleen.c
OUTPUT		 = tmp_Colleen
DIFF_FILE    = ${NAME}.diff

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
	@rm -rf ${OUTPUT}
	@rm -rf ${DIFF_FILE}

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@./${NAME} > ${OUTPUT}
	@diff ${SRC_FILE} ${OUTPUT} > ${DIFF_FILE} || exit 0
	@if ! [ -s ${DIFF_FILE} ] ; then \
		echo "Test: OK" ; \
		rm -rf ${DIFF_FILE} ; \
	else \
		echo "Test: KO, see ${DIFF_FILE}" ; \
	fi ; \


