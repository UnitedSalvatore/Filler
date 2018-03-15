/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:02:18 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/15 20:23:11 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define PLAYER_1 'O'
# define PLAYER_2 'X'

typedef struct s_map	t_map;
typedef struct s_token	t_token;

struct				s_token
{
	char			**map;
	int				size_x;
	int				size_y;
	unsigned int	size;
};

struct				s_map
{
	char			**map;
	unsigned char	player;
	unsigned char	enemy;
	int				size_x;
	int				size_y;
	unsigned int	size;
	t_token			token;
	\
	void			(*parse)(t_map *map);
	void			(*validate)(t_map *map);

};

void				parse(t_map *map);
void				validate(t_map *map);

#endif
