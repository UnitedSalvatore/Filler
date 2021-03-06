/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:52:13 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/20 20:40:07 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "filler.h"

static int			ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

static void			count_len(t_map *map, int mx, int my)
{
	unsigned int	len;
	int				tx;
	int				ty;
	int				mx2;
	int				my2;

	my2 = -1;
	while ((mx2 = -1) == -1 && ++my2 < map->size_y)
		while (++mx2 < map->size_x)
			if (map->map[my2][mx2] == map->enemy && (ty = -1) == -1)
				while ((tx = -1) == -1 && ++ty < map->token.size_y)
					while (++tx < map->token.size_x)
						if (map->token.map[ty][tx] == '*')
						{
							len = ft_abs(my2 - (my + ty)) + \
								ft_abs(mx2 - (mx + tx));
							if (len < map->len)
							{
								map->finish_x = mx;
								map->finish_y = my;
								map->len = len;
							}
						}
}

static unsigned int	check_position(t_map *map, int mx, int my)
{
	unsigned int	count;
	int				tx;
	int				ty;

	count = 0;
	ty = 0;
	while (ty < map->token.size_y)
	{
		tx = 0;
		while (tx < map->token.size_x)
		{
			if (map->token.map[ty][tx] == '*')
			{
				if (map->map[ty + my][tx + mx] == map->enemy)
					return (0);
				if (map->map[ty + my][tx + mx] == map->player)
					if (++count > 1)
						return (0);
			}
			++tx;
		}
		++ty;
	}
	return (count ? 1 : 0);
}

void				set_coordinates(t_map *map)
{
	int		x;
	int		y;

	map->finish_x = 0;
	map->finish_y = 0;
	map->len = UINT_MAX;
	y = 0;
	while (y <= map->size_y - map->token.size_y)
	{
		x = 0;
		while (x <= map->size_x - map->token.size_x)
		{
			if (check_position(map, x, y))
				count_len(map, x, y);
			++x;
		}
		++y;
	}
}
