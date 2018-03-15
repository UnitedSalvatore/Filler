/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:43:23 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/15 20:21:54 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static void	validate_map(t_map *map)
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

static void	validate_token(t_map *map)
{
	char	**chart;
	char	*line;

	chart = map->token.map;
	while (*chart)
	{
		line = *chart;
		while (*line)
		{
			if (*line == '*')
				*line = map->player;
			++line;
		}
		++chart;
	}
}

void		validate(t_map *map)
{
	validate_map(map);
	validate_token(map);
}
