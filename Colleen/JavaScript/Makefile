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
SRC_FILE    = Colleen.js
OUTPUT		 = tmp_Colleen
DIFF_FILE    = ${NAME}.diff

SRCS  = $(addprefix $(SRCS_DIR)/, ${SRC_FILE})
OBJS  = $(addprefix $(OBJS_DIR)/, ${SRC_FILE:.c=.o})

###################################################################################
#                                   Commands                                      #
###################################################################################

all: $(NAME)

$(NAME): $(SRC_FILE)
	@${INTER} ${NAME} > ${OUTPUT}
	@diff ${SRC_FILE} ${OUTPUT} > ${DIFF_FILE} || exit 0
	@if ! [ -s ${DIFF_FILE} ] ; then \
		echo "Test: OK" ; \
		rm -rf ${DIFF_FILE} ; \
	else \
		echo "Test: KO, see ${DIFF_FILE}" ; \
	fi ; \

clean:
	@rm -rf ${OUTPUT}


fclean: clean
	@rm -rf $(NAME)

re: fclean all