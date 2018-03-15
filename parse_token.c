/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:27:35 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/15 17:30:24 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filler.h"
#include "ft_getline.h"
#include "libft.h"

static int	parse_board(t_token *token)
{
	char	*str;
	int		i;

	i = 0;
	if (!(token->map = ft_memalloc(sizeof(char **) * (token->size_y + 1))))
		return (1);
	while (i < token->size_y)
	{
		if (ft_getline(STDIN_FILENO, &str) < 1)
			return (1);
		token->map[i++] = str;
	}
	return (0);
}

static int	parse_token_size(t_token *token)
{
	char	*str;
	char	**token_size;

	str = NULL;
	token->size_x = 0;
	token->size_y = 0;
	if (ft_getline(STDIN_FILENO, &str) < 1)
		return (1);
	if (!(token_size = ft_strsplit(str, ' ')))
		return (1);
	ft_strdel(&str);
	token->size_y = ft_atoi(token_size[1]);
	token->size_x = ft_atoi(token_size[2]);
	ft_splitdel(&token_size);
	return ((!token->size_y || !token->size_x) ? 1 : 0);
}

int			parse_token(t_token *token)
{
	if (parse_token_size(token) || parse_board(token))
		return (1);
	return (0);
}
