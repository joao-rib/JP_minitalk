CLIENT = client
SERVER = server
BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -fr
MAIN_CLIENT = client.c
MAIN_SERVER = server.c
MAIN_BONUS_CLIENT = client_bonus.c
MAIN_BONUS_SERVER = server_bonus.c
SRC = libft/*.c
OBJ_CL = obj_client/*.o
OBJ_SE = obj_server/*.o
BONUS_SRC = libft/*.c
BONUS_OBJ_CL = obj_bonus_client/*.o
BONUS_OBJ_SE = obj_bonus_server/*.o

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CL)
	@$(CC) $(FLAGS) $(OBJ_CL) -o $(CLIENT)

$(SERVER): $(OBJ_SE)
	@$(CC) $(FLAGS) $(OBJ_SE) -o $(SERVER)

$(OBJ_CL): $(MAIN_CLIENT) $(SRC)
	@mkdir -p obj_client
	@$(CC) $(FLAGS) -c $(SRC) $(MAIN_CLIENT)
	@mv *.o obj_client/

$(OBJ_SE): $(MAIN_SERVER) $(SRC)
	@mkdir -p obj_server
	@$(CC) $(FLAGS) -c $(SRC) $(MAIN_SERVER)
	@mv *.o obj_server/

bonus: $(BONUS_CLIENT) $(BONUS_SERVER)

$(BONUS_CLIENT): $(BONUS_OBJ_CL)
	@$(CC) $(FLAGS) $(BONUS_OBJ_CL) -o $(BONUS_CLIENT)

$(BONUS_SERVER): $(BONUS_OBJ_SE)
	@$(CC) $(FLAGS) $(BONUS_OBJ_SE) -o $(BONUS_SERVER)

$(BONUS_OBJ_CL): $(MAIN_BONUS_CLIENT) $(BONUS_SRC)
	@mkdir -p obj_bonus_client
	@$(CC) $(FLAGS) -c $(BONUS_SRC) $(MAIN_BONUS_CLIENT)
	@mv *.o obj_bonus_client/

$(BONUS_OBJ_SE): $(MAIN_BONUS_SERVER) $(BONUS_SRC)
	@mkdir -p obj_bonus_server
	@$(CC) $(FLAGS) -c $(BONUS_SRC) $(MAIN_BONUS_SERVER)
	@mv *.o obj_bonus_server/

clean:
	@$(RM) $(OBJ_CL) $(OBJ_SE) $(BONUS_OBJ_CL) $(BONUS_OBJ_SE) obj*/

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)

re: fclean all

bonus_re: fclean bonus