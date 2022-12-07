/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 03:59:08 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/27 00:42:33 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int find_wall(char **str, int i, int j)
{
    if(!(str[i - 1][j] == '1' || str[i - 1][j] == ' '))
        return(1);
    else if(!(str[i + 1][j] == '1' || str[i + 1][j] == ' '))
        return(1);
    else if(!(str[i][j + 1] == '1' || str[i][j + 1] == ' '))
        return(1);
    else if(!(str[i][j - 1] == '1' || str[i][j - 1] == ' '))
        return(1);
    return(0);
}
int check_last_line(char **str)
{
    int i;
    int j;

    j = lent_double_p(str) - 1;
    i = skip_space_start(str[j]);
    while(str[j][i] && i <= skip_space_end(str[j]))
    {
        if(str[j][i] == ' ')
        {
            if(!(str[j - 1][i] == ' ' || str[j - 1][i] == '1'))
                return(1);
        }
        i++;
    }
    return(0);
}
int check_first_line(char **str)
{
    int i;

    i = skip_space_start(str[0]);
    while(str[0][i] && i <= skip_space_end(str[0]))
    {
        if(str[0][i] == ' ')
        {
            if(!(str[1][i] == ' ' || str[1][i] == '1'))
                return(1);
        }
        i++;
    }
    return(0);
}

int check_spaces(char **str)
{
    int i;
    int j;

    i = 1;
    if(check_first_line(str) || check_last_line(str))
        return(1);
    while(str[i] && i < (lent_double_p(str) - 1))
    {
        j = skip_space_start(str[i]);
        while(str[i][j] && j <= skip_space_end(str[i]))
        {
            if(str[i][j] == ' ')
                if(find_wall(str, i, j))
                    return(1);
            if(str[i][j] == '0')
                if(check_zeros(str, i, j))
                    return(1);
            j++;
        }
        i++;
    }
    return(0);
}

int check_zeros(char **str, int i, int j)
{
    if(!(str[i - 1][j] == '1' || str[i - 1][j] == ' '
        || str[i - 1][j] == 'W' || str[i - 1][j] == 'N'
        || str[i - 1][j] == 'S' || str[i - 1][j] == 'E'
        ||str[i - 1][j] == '0'))
        return(1);
    else if(!(str[i + 1][j] == '1' || str[i + 1][j] == ' '
        || str[i + 1][j] == 'W' || str[i + 1][j] == 'N'
        || str[i + 1][j] == 'S' || str[i + 1][j] == 'E'
        || str[i + 1][j] == '0'))
        return(1);
    else if(!(str[i][j + 1] == '1' || str[i][j + 1] == ' '
        || str[i][j + 1] == 'W' || str[i][j + 1] == 'N'
        || str[i][j + 1] == 'S' || str[i][j + 1] == 'E'
        || str[i][j + 1] == '0'))
        return(1);
    else if(!(str[i][j - 1] == '1' || str[i][j - 1] == ' '
        || str[i][j - 1] == 'W' || str[i][j - 1] == 'N'
        || str[i][j - 1] == 'S' || str[i][j - 1] == 'E'
        || str[i][j - 1] == '0'))
        return(1);
    return(0);
}