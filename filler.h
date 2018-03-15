/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:02:18 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/15 17:39:18 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define PLAYER_1 'O'
# define PLAYER_2 'X'

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
	unsigned char	player;
	int				size_x;
	int				size_y;
	unsigned int	size;
	t_token			token;
}					t_map;

int					parse_map(t_map *map);
int					parse_token(t_token *token);

#endif