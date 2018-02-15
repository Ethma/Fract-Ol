/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:05:52 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/15 17:34:44 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define ZR map->zr
#define ZI map->zi
#define TMP map->tmp
#define Y stock->y2
#define X stock->x2
#define TABINT stock->tabint
#define ZOOM stock->zoom

static int	ft_calc(t_map *map)
{
	int n;
	int maxiter;

	n = 0;
	maxiter = 100;
	while (n < maxiter)
	{
		TMP = ZR;
		ZR = ZR * ZR - ZI * ZI + map->ca;
		ZI = 2 * TMP * ZI + map->cb;
		if ((ZR * ZR - ZI * ZI) >= 4.0)
			return (n);
		n++;
	}
	return (n);
}

void		mandelbrot(t_stock *stock)
{
	int		n;
	t_map	map;

	if (stock->ra == 0)
		init_stock_map(stock, &map);
	Y = -1;
	stock->identifier = 1;
	while (++Y < stock->height)
	{
		TABINT[Y] = (int *)malloc(sizeof(int) * WIN_W);
		X = -1;
		map.cb = ft_map(-2, 2, Y) / ZOOM;
		while (++X < stock->width)
		{
			map.ca = ft_map(-2, 2, X) / ZOOM;
			map.zr = 0;
			map.zi = 0;
			n = ft_calc(&map);
			TABINT[Y][X] = n;
			ft_draw(stock, stock->color, n);
		}
	}
	ft_end(stock);
}
