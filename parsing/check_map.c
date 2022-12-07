/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:04:58 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/27 01:24:45 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int skip_space_end(char *str)
{
    int i;

    i = ft_strlen(str) - 1;
    while(i >= 0 && str[i] < 32)
        i--;
    return(i);
}

int skip_space_start(char *str)
{
    int i;

    i = 0;
    while(str[i] && str[i] == ' ')
        i++;
    return(i);
}

int check_1(char **str)
{
    int i;
    int a;
    int b;

    i = 1;
    while(str[i])
    {
        a = skip_space_end(str[i]);
        b = skip_space_start(str[i]);
        if(!(str[i][a] == '1' && str[i][b] == '1'))
            return(1);
        i++;
    }
    return(0);
}

int sur_by_walls(char **map)
{
    int j;
    int a;

    a = 0;
    j = lent_double_p(map) - 1;
    while(map[0][a])
    {
        if(!(map[0][a] == ' ' || map[0][a] == '1'))
            return(1);
        a++;
    }
    a = 0;
    while(map[j][a])
    {
        if(!(map[0][a] == ' ' || map[0][a] == '1'))
            return(1);
        a++;
    }
    return(0);
}

int all_element(char **map)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(map[0][j])
    {
        if(!(map[0][j] == '~' || map[0][j] == '1' || map[0][j] == ' '))
            return(1);
        j++;
    }
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(!(map[i][j] == '1' || map[i][j] == '0'
                || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
                || map[i][j] == 'W' || map[i][j] == ' '))
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

void    free_cub(cub3d_t *cub)
{
    free(cub->NO);
    free(cub->SO);
    free(cub->EA);
    free(cub->WE);
    free(cub->f_col);
    free(cub->c_col);
    free_double_p(cub->map);
}

void    check_map(cub3d_t *cub)
{
    if(all_element(cub->map) || sur_by_walls(cub->map)
        || check_1(cub->map) || check_spaces(cub->map)
        || one_player(cub->map, cub))
    {
        free_cub(cub);
        exit_mssg("INVALID MAP !!");
    }
}