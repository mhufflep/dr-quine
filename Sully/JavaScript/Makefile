.PHONY: clean fclean re all

NAME = Sully

###################################################################################
#                                  Interpreteur                                   #
###################################################################################

INTER = node

###################################################################################
#                              Directories & Files                                #
###################################################################################

SRCS_DIR     = .
SRC_FILE     = Sully.js
TEST_DIR     = tmp

SRCS  = $(addprefix $(SRCS_DIR)/, ${SRC_FILE})
OBJS  = $(addprefix $(OBJS_DIR)/, ${SRC_FILE:.c=.o})

###################################################################################
#                                   Commands                                      #
###################################################################################

all: $(NAME)

$(NAME): $(SRC_FILE)
	@${INTER} ${NAME}

clean:
	@rm -rf ${NAME}_*.js

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ${TEST_DIR}

re: fclean all

test: re
	mkdir -p ${TEST_DIR}; cp ${SRC_FILE} ${TEST_DIR}/; cd ${TEST_DIR}/ && ${INTER} ${NAME} ; ls -al | grep ${NAME} | wc -l

test2:
	@cd ${TEST_DIR} && diff ../${SRC_FILE} ${NAME}_5.js || exit 0
	@cd ${TEST_DIR} && diff ../${SRC_FILE} ${NAME}_4.js || exit 0
	@cd ${TEST_DIR} && diff ${NAME}_5.js ${NAME}_0.js || exit 0
