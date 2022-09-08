.PHONY: clean fclean re all makedir

NAME = Colleen

###################################################################################
#                               Compiler & Flags                                  #
###################################################################################

ASM      = nasm
ASMFLAGS = 
# DEBUG     = 1

LD       = ld
LDFLAGS  = --dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 -lc -e main

#     Another option
# gcc Colleen.o -o Col -lc -no-pie
# ld  -o Col Colleen.o

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
SRCS_LIST    = Colleen.asm
OUTPUT		 = tmp_Colleen
DIFF_FILE    = ${NAME}.diff

SRCS  = $(addprefix $(SRCS_DIR)/, ${SRCS_LIST})
OBJS  = $(addprefix $(OBJS_DIR)/, ${SRCS_LIST:.asm=.o})

###################################################################################
#                                   Commands                                      #
###################################################################################

all: makedir $(NAME)
	
makedir:
	@if ! [ -d ${OBJS_DIR} ] ; then mkdir ${OBJS_DIR} ; fi

$(NAME): $(OBJS)
	@$(LD) $(LDFLAGS) $^ -o $@
	@echo "${NAME} created"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.asm
	@$(ASM) $(ASMFLAGS) $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf ${OUTPUT}
	@rm -rf ${DIFF_FILE}

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@./${NAME} > ${OUTPUT}
	@diff ${SRCS_LIST} ${OUTPUT} > ${DIFF_FILE} || exit 0
	@if ! [ -s ${DIFF_FILE} ] ; then \
		echo "Test: OK" ; \
		rm -rf ${DIFF_FILE} ; \
	else \
		echo "Test: KO, see ${DIFF_FILE}" ; \
	fi ; \


