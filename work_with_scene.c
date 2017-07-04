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

int		error(char *av)
{
	int num;

	num = ft_atoi(av);
	if (num < 0 || num > 4)
	{
		ft_putstr("Write correct number of scene: 0, 1, 2, 3, 4\n");
		exit(0);
	}
	return (num);
}

void	work_with_scene(t_mod *mod, int num)
{
	int		i;
	void	*intersection[5];
	void	*scene[5];

	i = -1;
	intersection[0] = find_closest_intersection_scene_1;
	intersection[1] = find_closest_intersection_scene_2;
	intersection[2] = find_closest_intersection_scene_3;
	intersection[3] = find_closest_intersection_scene_4;
	intersection[4] = find_closest_intersection_scene_5;
	scene[0] = scene_1;
	scene[1] = scene_2;
	scene[2] = scene_3;
	scene[3] = scene_4;
	scene[4] = scene_5;
	while (++i < THREAD)
	{
		mod[i].find_intersection = intersection[num];
		mod[i].scene = scene[num];
	}
}
