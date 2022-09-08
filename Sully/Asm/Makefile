.PHONY: clean fclean re all makedir

NAME = Sully

###################################################################################
#                               Compiler & Flags                                  #
###################################################################################

ASM      = nasm
ASMFLAGS = 
#DEBUG   = 1

LD       = ld
LDFLAGS  = --dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 -lc

ifeq ($(DEBUG), 1)
	ASMFLAGS += -g
endif

ifeq ($(OS), Darwin)
	ASMFLAGS += -f macho64
else
	ASMFLAGS += -f elf64
endif

###################################################################################
#                              Directories & Files                                #
###################################################################################

SRCS_DIR     = .
OBJS_DIR     = .obj
TEST_DIR     = tmp
SRC_FILE     = Sully.s

SRCS  = $(addprefix $(SRCS_DIR)/, ${SRC_FILE})
OBJS  = $(addprefix $(OBJS_DIR)/, ${SRC_FILE:.s=.o})

###################################################################################
#                                   Commands                                      #
###################################################################################

all: makedir $(NAME)
	
makedir:
	@if ! [ -d ${OBJS_DIR} ] ; then mkdir ${OBJS_DIR} ; fi

$(NAME): $(OBJS)
	@$(LD) $(LDFLAGS) $^ -o $@
	@echo "${NAME} created"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.s
	@$(ASM) $(ASMFLAGS) $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf ${OUTPUT}
	@rm -rf ${TEST_DIR}

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	mkdir -p ${TEST_DIR}; cp ${NAME} ${TEST_DIR}/; cd ${TEST_DIR}/; ./${NAME} ; ls -al | grep ${NAME} | wc -l

test2:
	@cd ${TEST_DIR} && diff ../${SRC_FILE} ${NAME}_5.s || exit 0
	@cd ${TEST_DIR} && diff ../${SRC_FILE} ${NAME}_4.s || exit 0
	@cd ${TEST_DIR} && diff ${NAME}_5.s ${NAME}_0.s || exit 0
