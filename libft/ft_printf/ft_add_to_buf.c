/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:41:15 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/05 15:35:19 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_.h"

void		ft_add_to_buf(const char c, struct s_buffer *buffer)
{
	buffer->buf[buffer->size++] = c;
	if (buffer->size == BUFF_SIZE)
	{
		write(STDOUT_FILENO, buffer->buf, buffer->size);
		buffer->written += buffer->size;
		buffer->size = 0;
	}
}
