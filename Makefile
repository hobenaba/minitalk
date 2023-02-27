CC = cc 

CFLAGS = -Wall -Wextra -Werror 

SERVER = server 

CLIENT = client 

SERVER_B = server_bonus

CLIENT_B = client_bonus

all : libft $(SERVER) $(CLIENT)

bonus : libft $(SERVER_B) $(CLIENT_B)

libft :
	@make -C libft -s

$(SERVER) : server.c 
	@$(CC) $(CFLAGS) server.c -o $(SERVER) -L libft -l ft -L libft/ft_printf -l ftprintf
	@echo "\033[0;31myour server is launching ...\033[0;0m"

$(CLIENT) : client.c ft_check_args.c
	@$(CC) $(CFLAGS)  client.c ft_check_args.c -o $(CLIENT) -L libft -l ft -L libft/ft_printf -l ftprintf
	@echo "\033[0;35myour client is launching ...\033[0;0m"

$(SERVER_B) : server_bonus.c
	@$(CC) $(CFLAGS) server_bonus.c -o $(SERVER_B) -L libft -l ft -L libft/ft_printf -l ftprintf
	@echo "\033[0;31myour SPECIAL server is launching ...\033[0;0m"

$(CLIENT_B) : client_bonus.c ft_check_args.c
	@$(CC) $(CFLAGS)  client_bonus.c ft_check_args.c -o $(CLIENT_B) -L libft -l ft -L libft/ft_printf -l ftprintf
	@echo "\033[0;35myour SPECIAL client is launching ...\033[0;0m"

clean : 
	@make clean -C libft -s
	@rm -rf server.o client.o server_bonus.o client_bonus.o

fclean : clean
	@make fclean -C libft -s
	@rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	@echo "\033[0;32mall clean\033[0;0m"

re : fclean all

.PHONY : libft all clean fclean re

