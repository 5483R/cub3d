/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:14:49 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/27 00:53:40 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_mssg(char *str)
{
	ft_putstr(str);
	exit(1);	
}

char	*line_map(int fd)
{
	char	*line;
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
	}
	return (map);
}

void	err_fre_lex_cub(t_lexer *lexer, cub3d_t *cub)
{
	free(lexer->src);
	free(lexer);
	free(cub);
	exit_mssg("INVALID MAP !!\n");
}

void	fill_info(cub3d_t *cub, char *map)
{
	t_lexer *lexer;

	lexer = init_lexer(map);
	free(map);
	while(lexer->c)
	{
		lexer_skip_space_line(lexer);
		if(lexer->c == 'N' && flag_no == 1)
		{
			flag_no = 0;
			cub->NO = check_id(lexer, cub, "NO");
		}
		else if(lexer->c == 'S' && flag_so == 1)
		{
			flag_so = 0;
			cub->SO = check_id(lexer, cub, "SO");
		}
		else if(lexer->c == 'W' && flag_we == 1)
		{
			flag_we = 0;
			cub->WE = check_id(lexer, cub, "WE");
		}
		else if(lexer->c == 'E' && flag_ea == 1)
		{
			flag_ea = 0;
			cub->EA = check_id(lexer, cub, "EA");
		}
		else if(lexer->c == 'F' && flag_f == 1)
		{
			flag_f = 0;
			cub->f_col = take_col(lexer, cub, "F");
		}
		else if(lexer->c == 'C' && flag_c == 1)
		{
			flag_c = 0;
			cub->c_col = take_col(lexer, cub, "C");
		}
		else if(take_the_map == 0)
			cub->map = swap_to_double(take_map(lexer));
		else
			err_fre_lex_cub(lexer, cub);
		lexer_advance(lexer);
	}
	free(lexer->src);
	free(lexer);
}

cub3d_t	*return_map(char *av, cub3d_t *cub)
{
	char	*map;
	int		fd;

	fd = open(av, O_RDONLY);
	map = change_value(line_map(fd));
	fill_info(cub, map);
	return(cub);
}

// cub3d_t *init_cub(char *str)
// {
//     cub3d_t *cub;

//     cub = malloc(sizeof(cub3d_t));
//     cub->map = return_map(str);
//     cub->x_player = 1;
//     cub->y_player = 1;
//     cub->direction = 'S';
//     cub->f_col[0] = 220;
//     cub->f_col[0] = 100;
//     cub->f_col[0] = 0;
//     cub->c_col[0] = 225;
//     cub->c_col[0] = 30;
//     cub->c_col[0] = 0;
//     return(cub);
// }