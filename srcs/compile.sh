gcc -g main.c read_map.c ../libft/libft.a
gcc -g -I /usr/local/include/ main.c read_map.c draw.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit ../libft/libft.a