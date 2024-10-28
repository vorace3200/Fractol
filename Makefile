BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
BBLACK = \033[1;30m
BRED = \033[1;31m
BGREEN = \033[1;32m
BYELLOW = \033[1;33m
BBLUE = \033[1;34m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BWHITE = \033[1;37m
BG_BLACK = \033[40m
BG_RED = \033[41m
BG_GREEN = \033[42m
BG_YELLOW = \033[43m
BG_BLUE = \033[44m
BG_PURPLE = \033[45m
BG_CYAN = \033[46m
BG_WHITE = \033[47m
RESET = \033[0m
CHECK = ✓
ROCKET = 🚀
CLEAN = 🧹
ERROR = ❌
WARN = ⚠️
FIRE = 🔥
SPARKLES = ✨
COMPUTER = 💻
PACKAGE = 📦
TOOLS = 🛠️
NAME = fractol
MLX_DIR = include/minilibx_opengl
MLX_LIB = $(MLX_DIR)/libmlx.a
SRC = main.c src/error/error.c src/initialization/init.c src/initialization/entry_main.c \
	src/utils/ft_strcmp.c	src/initialization/handle_fractals.c src/fractals/mandelbrot.c  \
	src/moves/handle_keys.c src/moves/handle_mouse.c src/utils/fractols_utils.c \
	src/fractals/julia.c src/fractals/burning_ship.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

define loading_bar
	@printf "$(BBLUE)[$(RESET)"
	@for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25; do \
		printf "$(BGREEN)▰$(RESET)"; \
		sleep 0.02; \
	done
	@printf "$(BBLUE)]$(RESET) $(BWHITE)100%%$(RESET)\n"
endef

all: banner $(NAME)

$(NAME): $(MLX_LIB) $(OBJ)
	@echo "\n$(BBLUE)$(COMPUTER) Initializing final compilation...$(RESET)"
	$(call loading_bar)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)
	@echo "$(BGREEN)$(SPARKLES) $(NAME) compiled successfully! $(ROCKET)$(RESET)\n"
	@echo "	$(BPURPLE)╔══════════════════════════════════════╗$(RESET)"
	@echo "	$(BPURPLE)║ $(BGREEN)Compilation completed successfully!$(BPURPLE)  ║$(RESET)"
	@echo "	$(BPURPLE)╚══════════════════════════════════════╝$(RESET)\n"

$(MLX_LIB):
	@echo "$(BYELLOW)$(TOOLS) Compiling MiniLibX...$(RESET)"
	@$(MAKE) -sC $(MLX_DIR) 2>/dev/null
	@echo "$(BGREEN)MiniLibX compiled successfully! $(CHECK)$(RESET)\n"

%.o: %.c
	@echo "$(BCYAN)$(PACKAGE) Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(BGREEN)$< compiled! $(CHECK)$(RESET)"

clean:
	@echo "$(BYELLOW)$(CLEAN) Cleaning in progress...$(RESET)"
	$(call loading_bar)
	@$(MAKE) -sC $(MLX_DIR) clean >/dev/null 2>&1
	@rm -f $(OBJ) >/dev/null 2>&1
	@echo "$(BGREEN)Object files deleted! $(CHECK)$(RESET)\n"

fclean:
	@echo "$(BYELLOW)$(CLEAN) Complete cleanup...$(RESET)"
	$(call loading_bar)
	@$(MAKE) -sC $(MLX_DIR) clean >/dev/null 2>&1
	@rm -f $(OBJ) >/dev/null 2>&1
	@rm -f $(NAME) >/dev/null 2>&1
	@echo "$(BGREEN)Cleanup completed successfully! $(CHECK)$(RESET)\n"

re: fclean all

banner:
	@clear
	@echo "$(BBLUE)"
	@echo "╔═════════════════════════════════════════════════════════════╗"
	@echo "║                                                             ║"
	@echo "║  $(BYELLOW)███████╗██████╗  █████╗  ██████╗████████╗ ██████╗ ██╗$(BBLUE)      ║"
	@echo "║  $(BYELLOW)██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║$(BBLUE)      ║"
	@echo "║  $(BYELLOW)█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║$(BBLUE)      ║"
	@echo "║  $(BYELLOW)██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║$(BBLUE)      ║"
	@echo "║  $(BYELLOW)██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗$(BBLUE) ║"
	@echo "║  $(BYELLOW)╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝$(BBLUE) ║"
	@echo "║                                                             ║"
	@echo "║                    $(BWHITE)Created by: vorace32 $(BBLUE)                    ║"
	@echo "║                     $(SPARKLES) $(BWHITE)Version: 1.0 $(SPARKLES)$(BBLUE)                      ║"
	@echo "╚═════════════════════════════════════════════════════════════╝"
	@echo "$(RESET)\n"

.PHONY: all clean fclean re banner
