/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:24:04 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/18 20:25:16 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <string.h>
#include "filler.h"
#include "libft.h"

static void	crop_x_l(t_token *token)
{
	int		i;
	char	*str;
	int		count;
	char	**map;
	int		j;

	count = token->size_x - 1;
	map = token->map;
	while (*map)
	{
		i = 0;
		str = *map;
		while (str[i])
		{
			if (str[i] == PLAYER_1 || str[i] == PLAYER_2)
				j = i;
			++i;
		}
		if (j < count)
			count = i;
		++map;
	}
	map = token->map;
	while (*map)
	{
		*(*map + count) = '\0';
		++map;
	}
}

static void	crop_x_f(t_token *token)
{
	int		i;
	char	*str;
	int		count;
	char	**map;

	count = token->size_x;
	map = token->map;
	while (*map)
	{
		i = 0;
		str = *map;
		while (str[i] == '.')
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

static void crop_y(t_token *token, const char c)
{
	char	**map;

	if (c == 'f')
		while (*token->map && !find_shape(*token->map))
			++token->map;
	else if (c == 'l')
	{
		map = token->map;
		while (*token->map && find_shape(*token->map))
			++token->map;
		*token->map = NULL;
		token->map = map;
	} 
}

void		crop_token(t_token *token)
{
	int i;

	crop_y(token, 'f');
	crop_y(token, 'l');
	crop_x_f(token);
	crop_x_l(token);
	token->size_x = ft_strlen(*token->map);
	i = 0;
	while ((token->map)[i])
		++i;
	token-> size_y = i;
}
