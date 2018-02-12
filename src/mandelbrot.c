/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:05:52 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/12 14:49:20 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define ZR map->zr
#define ZI map->zi
#define TMP map->tmp
#define Y stock->y2
#define X stock->x2
#define TABINT stock->tabint

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
	int		maxiter;
	t_map	map;

	maxiter = 100;
	ft_create_img(stock);
	init_stock_map(stock, &map);
	Y = -1;
	while (++Y < stock->height)
	{
		TABINT[Y] = (int *)malloc(sizeof(int) * WIN_W);
		X = -1;
		map.cb = ft_map(-2, 2, Y);
		while (++X < stock->width)
		{
			map.ca = ft_map(-2, 2, X);
			map.zr = 0;
			map.zi = 0;
			n = ft_calc(&map);
			TABINT[Y][X] = n;
			ft_draw(stock, 0, n);
		}
	}
	ft_end(stock);
}
