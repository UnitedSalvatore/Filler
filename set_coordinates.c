/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:52:13 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/16 20:22:19 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	insert_token(t_map *map, int mx, int my);
{
	unsigned int	count;
	int tx;
	int ty;

	ty = 0;
	while ()
	{
		tx = 0;
	}
}

void				set_coordinates(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y <= map->size_y - map->token.size_y)
	{
		x = 0;
		while (x <= map->size_x - map->token.size_x)
		{
			if (insert_token(map, ))
		}
		++y;
	}
}
