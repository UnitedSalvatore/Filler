/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:43:23 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/16 19:30:38 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void		validate(t_map *map)
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
