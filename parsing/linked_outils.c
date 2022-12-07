/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:27:46 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/26 04:03:34 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map   *init_map(char *str)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    map->str = str;
    map->next = NULL;
    return(map);
}

void	token_add_back(t_map **map, char *value)
{
	t_map	*last;
	t_map	*tmp;

	if (!*map)
	{
		*map = init_map(value);
		return ;
	}
	last = init_map(value);
	tmp = (*map);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
}

int lst_size(t_map *map)
{
    t_map   *tmp;
    int     i;

    tmp = map;
    i = 0;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return(i);
}

char    **swap_to_double(t_map *map)
{
    char    **str;
    t_map   *tmp;
    int i;

    i = 0;
    tmp = map;
    str = malloc(sizeof(char *) * (lst_size(map) + 1));
    while(tmp)
    {
        str[i] = ft_strdup(tmp->str);
        tmp = tmp->next;
        i++;
    }
    str[i] = 0;
    while(map)
    {
        tmp = map;
        map = map->next;
        free(tmp->str);
        free(tmp);
    }
    return(str);
}