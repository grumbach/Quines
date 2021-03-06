# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 11:27:05 by agrumbac          #+#    #+#              #
#    Updated: 2018/01/11 22:54:45 by agrumbac         ###   ########.fr        #
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

KIDS = tmp_Colleen Grace_kid.* Sully_*.* Sully_*

############################## COLORS ##########################################

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
C = "\033[36m"
BG = "\033[32;1m"
BB = "\033[34;1m"
WR = "\033[0m""\033[31;5m"
WC = "\033[0m""\033[36;5m"
WG = "\033[0m""\033[32;5m"
WB = "\033[0m""\033[34;5m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

############################## RULES ###########################################

all: art ${QUINE1} ${QUINE2} ${QUINE3}

${QUINE1}: ${OBJ1}
	@echo ${B}Compiling [${QUINE1}]...${X}
	@${CC} ${CFLAGS} -o $@ ${OBJ1}
	@echo ${G}Success"   "[${QUINE1}]${X}

${QUINE2}: ${OBJ2}
	@echo ${B}Compiling [${QUINE2}]...${X}
	@${CC} ${CFLAGS} -o $@ ${OBJ2}
	@echo ${G}Success"   "[${QUINE2}]${X}

${QUINE3}: ${OBJ3}
	@echo ${B}Compiling [${QUINE3}]...${X}
	@${CC} ${CFLAGS} -o $@ ${OBJ3}
	@echo ${G}Success"   "[${QUINE3}]${X}

${OBJDIR}/%.o: ./srcs/%.c
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -c -o $@ $<
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

diff_colleen: ${QUINE1}
	@echo ${WG}"-- diff Colleen --"${X}
	@./Colleen > tmp_Colleen && diff srcs/Colleen.c tmp_Colleen
	@echo ${WG}"-- diff Colleen --"${X}

diff_grace: ${QUINE2}
	@echo ${WC}"-- diff Grace --"${X}
	@/bin/rm -f Grace_kid.c; ./Grace && diff srcs/Grace.c Grace_kid.c
	@echo ${WC}"-- diff Grace --"${X}

diff_sully: ${QUINE3}
	@./Sully
	@echo ${WB}"-- diff Sully 5--"${X}
	@diff srcs/Sully.c Sully_5.c && echo ${WB}"-- diff Sully 5--"${X}
	@echo ${WB}"-- diff Sully 4--"${X}
	@diff srcs/Sully.c Sully_4.c || echo ${WB}"-- diff Sully 4--"${X}
	@echo ${WB}"-- diff Sully 3--"${X}
	@diff srcs/Sully.c Sully_3.c || echo ${WB}"-- diff Sully 3--"${X}
	@echo ${WB}"-- diff Sully 2--"${X}
	@diff srcs/Sully.c Sully_2.c || echo ${WB}"-- diff Sully 2--"${X}
	@echo ${WB}"-- diff Sully 1--"${X}
	@diff srcs/Sully.c Sully_1.c || echo ${WB}"-- diff Sully 1--"${X}
	@echo ${WB}"-- diff Sully 0--"${X}
	@diff srcs/Sully.c Sully_0.c || echo ${WB}"-- diff Sully 0--"${X}

diff: art diff_colleen diff_grace diff_sully

bonus:
	@echo ${WG}"-- diff Colleen --"${X}
	@node bonus/Colleen.js > tmp_Colleen && diff bonus/Colleen.js tmp_Colleen && echo ${WG}"-- diff Colleen --"${X}
	@echo ${WC}"-- diff Grace --"${X}
	@node bonus/Grace.js && diff bonus/Grace.js Grace_kid.js && echo ${WC}"-- diff Grace --"${X}
	@node bonus/Sully.js
	@echo ${WB}"-- diff Sully 5--"${X}
	@diff bonus/Sully.js Sully_5.js && echo ${WB}"-- diff Sully 5--"${X}
	@echo ${WB}"-- diff Sully 4--"${X}
	@diff bonus/Sully.js Sully_4.js || echo ${WB}"-- diff Sully 4--"${X}
	@echo ${WB}"-- diff Sully 3--"${X}
	@diff bonus/Sully.js Sully_3.js || echo ${WB}"-- diff Sully 3--"${X}
	@echo ${WB}"-- diff Sully 2--"${X}
	@diff bonus/Sully.js Sully_2.js || echo ${WB}"-- diff Sully 2--"${X}
	@echo ${WB}"-- diff Sully 1--"${X}
	@diff bonus/Sully.js Sully_1.js || echo ${WB}"-- diff Sully 1--"${X}
	@echo ${WB}"-- diff Sully 0--"${X}
	@diff bonus/Sully.js Sully_0.js || echo ${WB}"-- diff Sully 0--"${X}

art:
	@echo ${BG}
	@echo "--.   --..,_   _,.--.   --..,_   _,.--.   --..,_   _,.--.   --..,_   _,.--."
	@echo ""${WR}"o"${X}${BG}"  \`;__. \`'.:'\`__ "${WR}"o"${X}${BG}"  \`;__. \`'.:'\`__ "${WR}"o"${X}${BG}"  \`;__. \`'.:'\`__ "${WR}"o"${X}${BG}"  \`;__. \`'.:'\`__ "${WR}"o"${X}${BG}"  \`;__."
	@echo "---'\`  \`  .'.:\`. '---'\`  \`  .'.:\`. '---'\`  \`  .'.:\`. '---'\`  \`  .'.:\`. '---'\`  \`"
	@echo "--....--'\`.'  '.\`'--....--'\`.'  '.\`'--....--'\`.'  '.\`'--....--'\`.'  '.\`'--...."
	@echo "--....--'\`      \`'--....--'\`      \`'--....--'\`      \`'--....--'\`      \`'--...."
	@echo ${X}

############################## PHONY ###########################################

.PHONY: all clean fclean re test quine silent art diff diff_colleen diff_grace diff_sully bonus
