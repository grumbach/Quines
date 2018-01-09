# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 11:27:05 by agrumbac          #+#    #+#              #
#    Updated: 2018/01/09 12:05:55 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################## VAR #############################################

QUINE1 = Colleen
QUINE2 = Grace
QUINE3 = Sully

SRC1 = Colleen.c
SRC2 = Grace.c
SRC3 = Sully.c

CFLAGS = -Wall -Wextra -Werror

TESTFLAGS = -g -fsanitize=address

CC = clang

OBJDIR = objs

OBJ1 = $(addprefix ${OBJDIR}/, $(SRC1:.c=.o))
OBJ2 = $(addprefix ${OBJDIR}/, $(SRC2:.c=.o))
OBJ3 = $(addprefix ${OBJDIR}/, $(SRC3:.c=.o))

KIDS = tmp_Colleen Grace_kid.c Sully_*.c

############################## COLORS ##########################################

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
C = "\033[36m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

############################## RULES ###########################################

all: quine ${QUINE1} ${QUINE2} ${QUINE3}

${QUINE1}: ${OBJ1}
	@echo ${B}Compiling [${QUINE1}]...${X}
	@${CC} ${CFLAGS} -o $@ ${OBJ1}
	@echo ${G}Success"   "[${QUINE1}]${X}

${QUINE2}: ${OBJ2}
	@echo ${B}Compiling [${QUINE2}]...${X}
	@${CC} ${CFLAGS} -o $@ ${OBJ1}
	@echo ${G}Success"   "[${QUINE2}]${X}

${QUINE3}: ${OBJ3}
	@echo ${B}Compiling [${QUINE3}]...${X}
	@${CC} ${CFLAGS} -o $@ ${OBJ3}
	@echo ${G}Success"   "[${QUINE3}]${X}

${OBJDIR}/%.o: ./srcs/%.c
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} ${INCL} -I. -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@echo ${R}Cleaning"  "[objs]...${X}
	@/bin/rm -Rf ${OBJDIR}
	@echo ${R}Cleaning"  "[kids]...${X}
	@/bin/rm -Rf ${KIDS}

fclean: clean
	@echo ${R}Cleaning"  "[${QUINE1}]...${X}
	@echo ${R}Cleaning"  "[${QUINE2}]...${X}
	@echo ${R}Cleaning"  "[${QUINE3}]...${X}
	@/bin/rm -f ${QUINE1}
	@/bin/rm -f ${QUINE2}
	@/bin/rm -f ${QUINE3}

test:
	@${CC} ${TESTFLAGS} -o ${QUINE1} $(addprefix srcs/, ${SRC1})
	@${CC} ${TESTFLAGS} -o ${QUINE2} $(addprefix srcs/, ${SRC2})
	@${CC} ${TESTFLAGS} -o ${QUINE3} $(addprefix srcs/, ${SRC3})

re: fclean all

silent: ${QUINE1} ${QUINE2} ${QUINE3}

quine:
	@cat Makefile

diff: silent
	./Colleen > tmp_Colleen ; diff tmp_Colleen Colleen.c
	# ./Grace; diff srcs/Grace.c Grace_kid.c
	# ./Sully; diff srcs/Sully.c Sully_0.c

############################## PHONY ###########################################

.PHONY: all clean fclean re test quine silent diff
