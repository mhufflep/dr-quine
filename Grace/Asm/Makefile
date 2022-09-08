.PHONY: clean fclean re all makedir

NAME = Grace

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
SRC_FILE    = Grace.s
OUTPUT		 = Grace_kid.s
DIFF_FILE    = ${NAME}.diff

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
	@rm -rf ${DIFF_FILE}

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@rm ${OUTPUT} || exit 0
	@./${NAME}
	@diff ${SRC_FILE} ${OUTPUT} > ${DIFF_FILE} || exit 0
	@if ! [ -s ${DIFF_FILE} ] ; then \
		echo "Test: OK" ; \
		rm -rf ${DIFF_FILE} ; \
	else \
		echo "Test: KO, see ${DIFF_FILE}" ; \
	fi ; \


