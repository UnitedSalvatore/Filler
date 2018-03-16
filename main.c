/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:42:51 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/16 19:41:28 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_getline.h"
#include "libft.h"
#include "filler.h"

static void	parse_player(t_map *map)
{
	char	*str;

	ft_getline(STDIN_FILENO, &str);
	if (ft_strstr(str, " p1 "))
		map->player = PLAYER_1;
	else if (ft_strstr(str, " p2 "))
		map->player = PLAYER_2;
	ft_strdel(&str);
	map->enemy = (map->player == PLAYER_2) ? PLAYER_1 : PLAYER_2;
	map->
	map->parse = parse;
	map->validate = validate;
	return (0);
}

int		main(void)
{
	t_map	map;

	parse_player(&map);
	map.parse(&map);
	map.validate(&map);
	map.set_coordinates(&map);
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
