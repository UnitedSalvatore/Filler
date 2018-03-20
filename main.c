/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:42:51 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/20 13:18:20 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_getline.h"
#include "libft.h"
#include "filler.h"

static void	die(t_map *map)
{
	ft_splitdel(&map->map);
	ft_splitdel(&map->token.raw_map);
	ft_memdel((void **)&map->token.kostul);
}

static void	validate(t_map *map)
{
	char	**chart;
	char	*line;

	chart = map->map;
	while (*chart)
	{
		line = *chart;
		while (*line)
		{
			if (*line == ft_tolower(PLAYER_1) || *line == ft_tolower(PLAYER_2))
				*line = ft_toupper(*line);
			++line;
		}
		++chart;
	}
}

static void	parse_player(t_map *map)
{
	char	*str;

	ft_getline(STDIN_FILENO, &str);
	if (ft_strstr(str, " p1 "))
		map->player = PLAYER_1;
	else
		map->player = PLAYER_2;
	ft_strdel(&str);
	map->enemy = (map->player == PLAYER_2) ? PLAYER_1 : PLAYER_2;
	map->parse = parse;
	map->validate = validate;
	map->crop_token = crop_token;
	map->set_coordinates = set_coordinates;
	map->die = die;
}

int		main(void)
{
	t_map	map;
	char	*str;

	parse_player(&map);
	while (ft_getline(STDIN_FILENO, &str) > 0)
	{
		map.parse(&map, str);
		map.validate(&map);
		map.crop_token(&map.token);
		map.set_coordinates(&map);
		map.die(&map);
		ft_printf("%d %d\n", map.finish_y - map.token.shape_y, \
			map.finish_x - map.token.shape_x);
	}
	return (0);
}
