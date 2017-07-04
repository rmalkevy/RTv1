/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	create_image(t_mod *mod)
{
	int a[3];
	int	i;

	i = -1;
	mod->w->image = mlx_new_image(mod->w->mlx, WIDTH, HEIGHT);
	mod->w->line = mlx_get_data_addr(mod->w->image, &a[0], &a[1], &a[2]);
	while (++i < THREAD)
		mod[i].w->line = mod->w->line;
}

void	change_cam(t_mod *mod)
{
	int i;

	i = -1;
	calculation_rotation(&mod[0].rot);
	mod[0].r.start.x = 0;
	mod[0].r.start.y = 0;
	mod[0].r.start.z = CAM_START + mod[0].cam_distance;
	mod[0].r.start = rot_coordinate(&mod[0].rot, &mod[0].r.start);
	while (++i < THREAD)
	{
		mod[i].y_cur = (i + 1) * (HEIGHT / THREAD);
		mod[i].rot = mod[0].rot;
		mod[i].r.start = mod[0].r.start;
	}
}

int		addition_funct(int k, t_mod *mod)
{
	if (k == 126)
		mod[0].rot.angl_x += ANGLE;
	else if (k == 125)
		mod[0].rot.angl_x -= ANGLE;
	else if (k == 124)
		mod[0].rot.angl_y += ANGLE;
	else if (k == 123)
		mod[0].rot.angl_y -= ANGLE;
	else if (k == 83)
		mod[0].rot.angl_z += ANGLE;
	else if (k == 82)
		mod[0].rot.angl_z -= ANGLE;
	else if (k == 1)
		mod[0].cam_distance += DISTANCE;
	else if (k == 13)
		mod[0].cam_distance -= DISTANCE;
	change_cam(mod);
	return (0);
}

int		my_key_funct(int keycode, t_mod *mod)
{
	mlx_destroy_image(mod->w->mlx, mod->w->image);
	if (keycode == 53)
	{
		mlx_destroy_window(mod->w->mlx, mod->w->win);
		free(mod->w);
		free(mod);
		exit(0);
	}
	addition_funct(keycode, mod);
	write_to_image(mod);
	return (0);
}
