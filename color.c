/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	color_zero(t_mod *mod)
{
	mod->red = 0;
	mod->green = 0;
	mod->blue = 0;
	mod->opacity = 220;
}

void	put_color_to_pixel(t_mod *mod, double x, double y)
{
	int			pixel;

	pixel = (int)(((x + HALF_WIDTH) + (y + HALF_HEIGHT) * WIDTH) * 4);
	mod->w->line[pixel + 0] = (unsigned char)(mod->blue * 255);
	mod->w->line[pixel + 1] = (unsigned char)(mod->green * 255);
	mod->w->line[pixel + 2] = (unsigned char)(mod->red * 255);
	mod->w->line[pixel + 3] = (unsigned char)(mod->opacity);
}
