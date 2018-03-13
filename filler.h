#ifndef FILLER_H
# define FILLER_H

# define PLAYER_1 1
# define PLAYER_2 2

typedef struct		s_token
{
	char			**map;	
	int				size_x;
	int				size_y;
	unsigned int	size;
}					t_token;

typedef struct		s_map
{
	char			**map;
	unsigned int	player : 2;
	int				size_x;
	int				size_y;
	unsigned int	size;
	t_token			token;
}					t_map;

int					parse(t_map *map);

#endif