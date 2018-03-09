/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:42:51 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/11 19:55:02 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_getline.h"
#include "libft.h"
#include "filler.h"

int		main(void)
{
	//t_map	map;
	//t_token	token;
	char	*str;
	int i;

	ft_dprintf(2, "----------\n");
	while ((i = ft_getline(0, &str)) > 0)
	{
		ft_dprintf(2, "%s\n", str);
		ft_strdel(&str);
	}
	ft_dprintf(2, "i = %i\n", i);
	ft_printf("0 0\n");
	return (0);
}
