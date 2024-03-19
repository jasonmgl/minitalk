# ********************************************************************* #
#  __   __  _______  ___   _  _______  _______  ___   ___      _______  #
# |  |_|  ||   _   ||   | | ||       ||       ||   | |   |    |       | #
# |       ||  |_|  ||   |_| ||    ___||    ___||   | |   |    |    ___| #
# |       ||       ||      _||   |___ |   |___ |   | |   |    |   |___  #
# |       ||       ||     |_ |    ___||    ___||   | |   |___ |    ___| #
# | ||_|| ||   _   ||    _  ||   |___ |   |    |   | |       ||   |___  #
# |_|   |_||__| |__||___| |_||_______||___|    |___| |_______||_______| #
#                                                                       #
# ********************************************************************* #


# ************************************************** #

NAME_CLIENT			=		client

NAME_SERVER			=		server

NAME_CLIENT_BONUS	=		client_bonus

NAME_SERVER_BONUS	=		server_bonus

CC					=		cc

CFLAGS				=		-Wall -Wextra -Werror -I libft/include/ -I includes/

INCLUDES			=		includes/minitalk.h

INCLUDES_BONUS		=		bonus/includes/minitalk_bonus.h

LIB_H				=		libft/include/libft.h

LIB_A				=		libft/libft.a

SRCS_D				=		srcs/

SRCS_CLIENT			=		${SRCS_D}client.c

SRCS_SERVER			=		${SRCS_D}server.c

OBJS_CLIENT			=		${SRCS_D}client.o

OBJS_SERVER			=		${SRCS_D}server.o

BONUS_D				=		bonus/${SRCS_D}

SRCS_CLIENT_BONUS	=		${BONUS_D}client_bonus.c

SRCS_SERVER_BONUS	=		${BONUS_D}server_bonus.c

OBJS_CLIENT_BONUS	=		${BONUS_D}client_bonus.o

OBJS_SERVER_BONUS	=		${BONUS_D}server_bonus.o


# ************************************************** #

all :						${NAME_CLIENT} ${NAME_SERVER} Makefile

${NAME_CLIENT} :			${LIB_A} ${OBJS_CLIENT} ${INCLUDES}
	${CC} ${CFLAGS} ${OBJS_CLIENT} ${LIB_A} -o $@

${NAME_SERVER} :			${LIB_A} ${OBJS_SERVER} ${INCLUDES}
	${CC} ${CFLAGS} ${OBJS_SERVER} ${LIB_A} -o $@

${OBJS_CLIENT} :			${SRCS_CLIENT} ${INCLUDES}
	@${CC} ${CFLAGS} -c $< -o $@

${OBJS_SERVER} :			${SRCS_SERVER} ${INCLUDES}
	@${CC} ${CFLAGS} -c $< -o $@

${LIB_A} :
	@${MAKE} -C libft/ --no-print-directory

bonus : 					${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS} Makefile

${NAME_CLIENT_BONUS} :		${LIB_A} ${OBJS_CLIENT_BONUS} ${INCLUDES_BONUS}
	${CC} ${CFLAGS} ${OBJS_CLIENT_BONUS} ${LIB_A} -o $@

${NAME_SERVER_BONUS} :		${LIB_A} ${OBJS_SERVER_BONUS} ${INCLUDES_BONUS}
	${CC} ${CFLAGS} ${OBJS_SERVER_BONUS} ${LIB_A} -o $@

${OBJS_CLIENT_BONUS} :		${SRCS_CLIENT_BONUS} ${INCLUDES_BONUS}
	@${CC} ${CFLAGS} -c $< -o $@

${OBJS_SERVER_BONUS} :		${SRCS_SERVER_BONUS} ${INCLUDES_BONUS}
	@${CC} ${CFLAGS} -c $< -o $@

clean :
	${MAKE} clean -C libft --no-print-directory
	rm -rf ${OBJS_CLIENT}
	rm -rf ${OBJS_SERVER}
	rm -rf ${OBJS_CLIENT_BONUS}
	rm -rf ${OBJS_SERVER_BONUS}

fclean : clean
	${MAKE} fclean -C libft --no-print-directory
	rm -rf ${NAME_CLIENT}
	rm -rf ${NAME_SERVER}
	rm -rf ${NAME_CLIENT_BONUS}
	rm -rf ${NAME_SERVER_BONUS}

re :	fclean all

# ************************************************** #

.PHONY :	all clean fclean re bonus

# ************************************************** #