/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:24:04 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/20 13:15:36 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <string.h>
#include "filler.h"
#include "libft.h"

static void	crop_x_l(t_token *token)
{
	int		i;
	int		count;
	char	**map;

	count = 0;
	map = token->map;
	while (*map)
	{
		i = 0;
		while ((*map)[i])
		{
			if ((*map)[i] == '*' && i > count)
				count = i;
			++i;
		}
		++map;
	}
	map = token->map;
	while (*map)
	{
		*(*map + count + 1) = '\0';
		++map;
	}
}

static void	crop_x_f(t_token *token)
{
	int		i;
	int		count;
	char	**map;

	count = token->size_x;
	map = token->map;
	while (*map)
	{
		i = 0;
		while ((*map)[i] == '.')
			++i;
		if (i < count)
			count = i;
		++map;
	}
	map = token->map;
	while (*map)
	{
		*map = *map + count;
		++map;
	}
}

static int	find_shape(char *str)
{
	while (*str)
		if (*str++ != '.')
			return (1);
	return (0);
}

static void	crop_y(t_token *token)
{
	char	**map;

	map = token->map;
	while (*map && !find_shape(*map))
		++map;
	while (*map && find_shape(*map))
		++map;
	*map = NULL;
}

void		crop_token(t_token *token)
{
	int		i;

	crop_y(token);
	crop_x_l(token);
	i = 0;
	while (token->map[i])
		++i;
	token->size_x = ft_strlen(*token->map);
	token->size_y = i;
	while (*token->map && !find_shape(*token->map))
		++token->map;
	i = 0;
	while (token->map[i])
		++i;
	crop_x_f(token);
	token->shape_x = token->size_x - ft_strlen(*token->map);
	token->shape_y = token->size_y - i;
	token->size_y -= token->shape_y;
	token->size_x -= token->shape_x;
}
