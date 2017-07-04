/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	work_with_pixel(t_mod *mod, t_vector *pixel)
{
	void (*find_closest_intersection)(t_mod *, t_ray *);

	find_closest_intersection = mod->find_intersection;
	init_pixel(mod, pixel);
	mod->t = 10000000.0;
	find_closest_intersection(mod, &mod->r);
	if (mod->intersection)
		value_of_light(mod);
}

void	anti_aliased(t_mod *mod, double x, double y)
{
	double		yy;
	double		xx;
	t_vector	pixel;

	yy = -1;
	while (++yy < SAMPLES)
	{
		xx = -1;
		while (++xx < SAMPLES)
		{
			pixel.x = x + (xx + 0.5) / SAMPLES;
			pixel.y = y + (yy + 0.5) / SAMPLES;
			pixel.z = 0;
			rot_coordinate(&mod->rot, &pixel);
			work_with_pixel(mod, &pixel);
		}
	}
}

void	*multi_thread(void *m)
{
	t_mod	*mod;
	double	x;
	double	y;

	mod = (t_mod *)m;
	y = -(HEIGHT / 2) + mod->y_cur - HEIGHT / THREAD - 1;
	while (y < -(HEIGHT / 2) + mod->y_cur)
	{
		x = -(WIDTH / 2);
		while (x < WIDTH / 2)
		{
			mod->intersection = 0;
			mod->shadow = 0;
			mod->light = 0;
			color_zero(mod);
			anti_aliased(mod, x, y);
			put_color_to_pixel(mod, x, y);
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}

void	write_to_image(t_mod *mod)
{
	pthread_t	tid[THREAD];
	int			i;

	i = -1;
	mlx_clear_window(mod->w->mlx, mod->w->win);
	create_image(mod);
	while (++i < THREAD)
		pthread_create(&tid[i], NULL, multi_thread, (void *)&mod[i]);
	i = -1;
	while (++i < THREAD)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(mod->w->mlx, mod->w->win, mod->w->image, 0, 0);
	mlx_hook(mod->w->win, 2, 5, my_key_funct, mod);
	mlx_loop(mod->w->mlx);
}

int		main(int ac, char **av)
{
	t_mod	*mod;
	int		i;
	int		num;

	i = -1;
	if (ac == 2)
	{
		num = error(av[1]);
		mod = (t_mod*)malloc(sizeof(t_mod) * THREAD);
		work_with_scene(mod, num);
		init_mod(mod);
		while (++i < THREAD)
			mod[i].w = (t_win*)malloc(sizeof(t_win));
		mod->w->mlx = mlx_init();
		mod->w->win = mlx_new_window(mod->w->mlx, WIDTH, HEIGHT, "RTv1");
		write_to_image(mod);
	}
	else
		ft_putstr("Write correct number of scene: 0, 1, 2, 3, 4\n");
	return (0);
}
