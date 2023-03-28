# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 16:53:35 by xmatute-          #+#    #+#              #
#    Updated: 2023/03/28 18:40:53 by xmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define CUBE
                                                                                                             
                                                                                                              
                                                                                                              
                                                                                                              
                                                                                                              
                                                            .,                                                
                                          //////%#/////////////////,                                          
                         ,////(@&#///////////////////&##(///(%%%&&#//////                                     
              &##//////////////////#@%#/////(#&@&%(/////((&%(//////////////////                               
             ,,##@@##///////(#&&#///////(&#(//////////////////(&&#/////////(%&&&%(((.                         
             .,,,,,#%&&@%#%//////////////////@@%(((/((//(((#&%&@@@@@@@@(/////////////////(.                   
             .,,,,,,,&,*%&@@%#%///////////%%#@@@@@@@@////////////////(/((@@&&/////////////(#&#(#              
             .,,,,,,,%,,,,,*%@&@@##%//////////////////(@%&((/////////////(/(((@&@@@@@%#(////((#&%%            
             .,,,,,,,%,,,,,,,,#@#%@@@&%%/////////////////((/@#&%#%%&@@@@&#(/((((&@%%%%/ .. .    .%            
             .,,,,,,,#,,,,,,,,%@,,,,#%@@@&%#%#&@@@@@&%(//(/((&@#%@&&&%%%%(...   %&#..           .%            
             &&@,,,,,(,,,,,,,,%&,,,,,,,,#%@@&&&&&&&%%%%/....*%@&............... %&(.             #            
             ,,#%@@#%@,,,,,,,,%&,,,,,,,,,%&@&... ............&&%........ ...... %&/              #            
             ,,,,,,%%&@,,,,,,,%&,,,,,,,,,%&@&..........  ....&&%..   ...      ..&&*              #            
             ,,,,,,,%@%&@@%,,,%&,,,,,,,,,%&&&...............,&&%  .          ...&&*  ..          (            
             ,,,,,,,,&,,,,#%@@@@#,,,,,,,,%&&&.......      ..*@&%..            .#@&%%    ./%%%%%&%%            
             ,,,,,,,,%,,,,,,,%(@@@#,,,,,*%&&&....  ..    ...%@&%  .       . .%%@@@@@%/#%%%%#.    #            
             ,,,,,,,,%,,,,,,,,%@@%%%%%,,/%&&%........ ....%%@@@@&%%&@@@@#*/(%%%&@@@%             #            
             #*,,,,,,%,,,,,,,,,&@,,,,.%%&%&&&%/%%&@@@#@@&(//&@@@@@%%           .%&%              #            
             ,,,%&,,/&,,,,,,,,,&&,,,,,,,,%%%@%(&%%%%%%,..    %@@%/.             %&%              (            
             ,,,,,,%@@(,,,,,,,,&%,,,,,,,,,%&&&%.              @&%               %&%              (            
             ,,,,,,,%@@%#,,,,,,&#,,,,,,,,,%&&&#.             .@&%               %&%              /            
             ,,,,,,,,&,,,%@#,,%&(,,,,,,,,,%&&&#              .@&%               %&%             %.            
             ,,,,,,,,&,,,,,,%&@@@,,,,,,,,,%&&&(              *@&#              %@@&%. .#%%@@@@%(/             
             *,,,,,,,&,,,,,,,,%@@@%,,,,,,,%&&&*              /@&%           *%@@@@@@//%%%%%/   .%             
                ,,,,,&,,,,,,,,,@%%%%@%,,,,%&&&.             (@@@@%%%%&@@#*/%%%&@@@%/            %             
                  #,,&,,,,,,,,,%,,,,(%%@%#%&&%. .   *%%%&@@@@@@@@%%#,          %&&             .%             
                     &,,,,,,,,,#,,,,,,,(%#@@@@@#(#%%%%%/ ,%%%@&%               %&%              %             
                       .*,,,,,,(,,,,,,,,/%&&%.             .%@&                %&%             .&             
                          %,,,,/,,,,,,,,(%&&&     .         %@%                %&%             .%             
                             %%*,,,,,,,,#%&&%               %@%              ..%&% .       . .%%%             
                               *#,,,,,,,%%&&(              .%@%.         .  . *%@&#%%&&(                      
                                  %,,,,,&%&&*.             .%@&. ......(%&&&&,                                
                                     %,,&%&&.           .. %&@&&&&/                                           
                                       (%&&&/   (%%&&&%.                                                      
                                          ((                                                                  
                                                                                                              
                                                                                                              
                                                                                                              
                                                                                                             
endef
export CUBE
NAME := cub3D

SRC :=	main.c							\
		checkinput/validinput.c			\
		checkinput/validextension.c		\
		checkinput/readable.c			\
		checkinput/datanum.c			\
		checkinput/have_all_data.c		\
		checkinput/have_repeat_data.c	\
		checkinput/have_space.c			\
		checkinput/have_data.c			\
		checkinput/valid_data.c			\
		checkinput/valid_colors.c		\
		checkinput/are_inrange.c		\
		checkinput/strange_id.c			\
		parse/get_data.c				\
		checkinput/are_num.c			\
		utils/ft_get_next_line.c		\
		utils/ft_free2.c				\
		utils/ft_args_lenght.c			\
		errors/argc_error.c				\
		errors/extension_error.c		\
		errors/read_error.c				\
		errors/format_error.c			\
		errors/missingdata_error.c		\
		errors/repeat_data_error.c		\
		errors/nospace_error.c			\
		errors/validdata_error.c		\
		errors/empty_error.c			\
		errors/color_c_error.c			\
		errors/color_error.c			\
		errors/double_coma_error.c		\
		errors/color_n_error.c			\
		errors/color_r_error.c			\
		errors/strange_error.c			\
		

HEADER := cub3D.h
		
WHITE = \033[0;37m
RED = \033[0;31m
CYAN = \033[0;36m
GREEN = \033[0;32m
MAGENTA = \033[0;35m

OBJ := $(SRC:%.c=%.o)

SANI 	:= -fsanitize=address -g3

CC 		:= gcc
CFLAGS 	:= -Wall  -Wextra -Werror

RM 		:= rm -rf

MLXF	:= -I mlx/libmlx.a -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	@echo "$(GREEN)libft compiled...$(WHITE)"
	$(MAKE) -C mlx 2> logs
	$(RM) logs
	@echo "$(GREEN)MLX compiled...$(WHITE)"
	$(CC) $(CFLAGS) $(MLXF) ./libft/libft.a $(OBJ) -o $(NAME)
	@echo "$(GREEN)Cub3d compiled...$(WHITE)"
	@echo "$(CYAN)$$CUBE$(WHITE)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

sani: fclean
	$(MAKE) CFLAGS='$(CFLAGS) $(SANI)' all

flagless:
	$(MAKE) CFLAGS='' all

normi:
	norminette $(SRC) $(HEADER)

commit:
	git add $(SRC) $(HEADER) ./Makefile
	git commit -m "commit general"
	git push

test: all
	./Cub3d test.cub
	
clean : 
		$(RM) $(OBJ)
		make clean -C libft
		make clean -C mlx
		@echo "$(RED)clean done...$(WHITE)"

fclean : clean
		$(RM) $(NAME)
		@echo "$(RED)fclean done...$(WHITE)"

re : fclean all

.PHONY : all clean fclean re sani flagless normi commit test