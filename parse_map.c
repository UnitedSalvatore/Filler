/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:30:27 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/15 17:12:44 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filler.h"
#include "ft_getline.h"
#include "libft.h"

static int	parse_board(t_map *map)
{
	char	**line;
	char	*str;
	int		i;

	i = 0;
	if (ft_getline(STDIN_FILENO, &str) < 1)
		return (1);
	ft_strdel(&str);
	if (!(map->map = ft_memalloc(sizeof(char **) * (map->size_y + 1))))
		return (1);
	while (i < map->size_y)
	{
		if (ft_getline(STDIN_FILENO, &str) < 1)
			return (1);
		if ((line = ft_strsplit(str, ' ')) && line[0] && line[1])
		{
			map->map[i++] = line[1];
			line[1] = NULL;
			ft_splitdel(&line);
		}
		else
			return (1);
		ft_strdel(&str);
	}
	return (0);
}

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
	map->size_y = ft_atoi(map_size[1]);
	map->size_x = ft_atoi(map_size[2]);
	ft_splitdel(&map_size);
	return ((!map->size_y || !map->size_x) ? 1 : 0);
}

int			parse_map(t_map *map)
{
	if (parse_map_size(map) || parse_board(map))
		return (1);
	return (0);
}
