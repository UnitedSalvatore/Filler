/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:42:51 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/15 14:56:32 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_getline.h"
#include "libft.h"
#include "filler.h"

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

int		main(void)
{
	t_map	map;

	if (parse_player(&map))
		ft_dprintf(2, "Error\n");
	else
		ft_dprintf(2, "OK\n");
	if (parse_map(&map))
		ft_dprintf(2, "Error\n");
	else
		ft_dprintf(2, "OK\n");
	if (parse_token(&map.token))
		ft_dprintf(2, "Error\n");
	else
		ft_dprintf(2, "OK\n");
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
