/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:30:27 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/20 20:42:52 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "filler.h"
#include "libft/include/ft_getline.h"
#include "libft/include/libft.h"

static void	parse_token(t_token *token)
{
	char	*str;
	int		i;

	i = 0;
	token->raw_map = malloc(sizeof(char *) * (token->size_y + 1));
	token->map = malloc(sizeof(char *) * (token->size_y + 1));
	while (i < token->size_y)
	{
		ft_getline(STDIN_FILENO, &str);
		token->raw_map[i] = str;
		token->map[i++] = str;
		str = NULL;
	}
	token->raw_map[i] = NULL;
	token->map[i] = NULL;
	token->kostul = token->map;
}

static void	parse_token_size(t_token *token)
{
	char	*str;

	token->size_y = 0;
	token->size_x = 0;
	str = NULL;
	ft_getline(STDIN_FILENO, &str);
	token->size_y = ft_atoi(ft_strchr(str, ' '));
	token->size_x = ft_atoi(ft_strrchr(str, ' '));
	ft_strdel(&str);
}

static void	parse_map(t_map *map)
{
	char	*str;
	int		i;

	i = 0;
	ft_getline(STDIN_FILENO, &str);
	ft_strdel(&str);
	map->map = malloc(sizeof(char *) * (map->size_y + 1));
	while (i < map->size_y)
	{
		ft_getline(STDIN_FILENO, &str);
		map->map[i++] = ft_strdup(ft_strchr(str, ' ') + 1);
		ft_strdel(&str);
	}
	map->map[i] = NULL;
}

static void	parse_map_size(t_map *map, char *str)
{
	map->size_y = 0;
	map->size_x = 0;
	map->size_y = ft_atoi(ft_strchr(str, ' '));
	map->size_x = ft_atoi(ft_strrchr(str, ' '));
	ft_strdel(&str);
}

void		parse(t_map *map, char *str)
{
	parse_map_size(map, str);
	parse_map(map);
	parse_token_size(&map->token);
	parse_token(&map->token);
}
