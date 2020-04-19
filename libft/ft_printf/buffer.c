/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnguyen <jnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:01:49 by jnguyen           #+#    #+#             */
/*   Updated: 2020/01/07 14:08:47 by jnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_buffer(t_pf *params)
{
	params->ret += write(1, params->str, params->pos);
	params->pos = 0;
}

void		add_to_buffer(char c, t_pf *params)
{
	if (params->pos == BUFF_SIZE - 1)
		reset_buffer(params);
	params->str[params->pos++] = c;
}

int			is_flag(t_pf *params, char *charset)
{
	while (*charset)
	{
		if (*params->format == *charset)
			return (1);
		charset++;
	}
	return (0);
}
