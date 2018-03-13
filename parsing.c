/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:30:27 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/13 17:26:25 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "filler.h"
#include "ft_getline.h"
#include "libft.h"

static int	parse_map_size(t_map *map)
{
	char	*str;
	char	**map_size;

	str = NULL;
	map->size_x = 0;
	map->size_y = 0;
	if (ft_getline(STDIN_FILENO, &str) < 1)
		return (1);
	if (!(map_size = ft_strsplit(str, ' ')))
		return (1);
	ft_strdel(&str);
	map->size_y = ft_atoi(map_size[2]);
	map->size_x = ft_atoi(map_size[3]);
	ft_splitdel(&map_size);
	return (0);
}

static int	parse_player(t_map *map)
{
	char	*str;

	str = NULL;
	map->player = 0;
	if (ft_getline(STDIN_FILENO, &str) < 1)
		return (1);
	if (ft_strstr(str, " p1 "))
		map->player = PLAYER_1;
	else if (ft_strstr(str, " p2 "))
		map->player = PLAYER_2;
	ft_strdel(&str);
	return (map->player ? 0 : 1);
}

int			parse(t_map *map)
{
	if (parse_player(map) || parse_map_size(map))
		return (1);
}
