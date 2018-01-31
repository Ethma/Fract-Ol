/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:33:24 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/31 15:37:22 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		ft_exit_finish(char *str, int i, t_stock *stock)
{
	if (i == 2)
	{
		ft_putendl(str);
		exit(1);
	}
	return (0);
}
