.PHONY: clean fclean re all

NAME = Colleen

###################################################################################
#                                  Interpreteur                                   #
###################################################################################

INTER = node

###################################################################################
#                              Directories & Files                                #
###################################################################################

SRCS_DIR     = .
SRCS_LIST    = Colleen.js
OUTPUT		 = Colleen_copy.js
DIFF_FILE    = ${NAME}.diff

SRCS  = $(addprefix $(SRCS_DIR)/, ${SRCS_LIST})
OBJS  = $(addprefix $(OBJS_DIR)/, ${SRCS_LIST:.c=.o})

###################################################################################
#                                   Commands                                      #
###################################################################################

all: $(NAME)

$(NAME): $(SRCS_LIST)
	@${INTER} ${NAME} > ${OUTPUT}
	@diff ${SRCS_LIST} ${OUTPUT} > ${DIFF_FILE} || exit 0
	@if ! [[ -s ${DIFF_FILE} ]] ; then \
		echo "Test: OK" ; \
		rm -rf ${DIFF_FILE} ; \
	else \
		echo "Test: KO, see ${DIFF_FILE}" ; \
	fi ; \

clean:
	@rm -rf ${NAME}_*.js

fclean: clean
	@rm -rf $(NAME)

re: fclean all