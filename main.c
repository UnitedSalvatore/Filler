/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:42:51 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/17 19:42:38 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_getline.h"
#include "libft.h"
#include "filler.h"

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
	map->set_coordinates = set_coordinates;
}

int		main(void)
{
	t_map	map;

	parse_player(&map);
	map.parse(&map);
	map.validate(&map);
	map.set_coordinates(&map);
	ft_printf("MAP");
	while (*(map.map))
		ft_printf("%s\n", *(map.map)++);
	ft_printf("TOKEN");
	while (*(map.map.token))
		ft_printf("%s\n", *(map.map.token)++);
	ft_printf("%d %d\n", map.finish_y, map.finish_x);
	return (0);
}

// $$$ exec p1 : [resources/players/ypikul.filler]
// Plateau 15 17:
//     01234567890123456
// 000 .................
// 001 .................
// 002 .................
// 003 .................
// 004 .................
// 005 .................
// 006 .................
// 007 .................
// 008 ..O..............
// 009 .................
// 010 .................
// 011 .................
// 012 ..............X..
// 013 .................
// 014 .................
// Piece 1 3:
// .**
