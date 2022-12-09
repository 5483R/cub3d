/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:40:21 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/09 20:11:03 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H

# include "../cub3d.h"

typedef struct t_g{
	int	flag_no;
	int	flag_so;
	int	flag_ea;
	int	flag_we;
	int	flag_f;
	int	flag_c;
	int	take_the_map;
}	t_g;

typedef struct t_map
{
	char			*str;
	struct t_map	*next;
}	t_map;

typedef struct s_rays
{
	double	rayangle;
	double	wallhitx;
	double	wallhity;
	double	distance;
	double	projectionplan;
	double	projectiowalls;
	double	wallsheight;
	double	walltoppixel;
	double	wallbottompixel;
}	t_rays;

typedef struct t_norm
{
    int		y;
	int		x;
	double	i;
	int		ray;
	int		textureoffset_x;
	int		textureoffset_y;
	int		distancefromtop;
}   t_norm;

typedef struct t_texture
{
	void	*img;
	char	*add;
	int		bp;
	int		end;
	int		len;
}	t_texture;

typedef struct t_cubd
{
	void		*mlx;
	void		*win;
	double		x_player;
	double		y_player;
	double		ang;
	char		direction;
	int			*f_col;
	int			*c_col;
	char		**map;
	double		*distances;
	char		*info;
	t_rays		**rays;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			b;
	int			l;
	int			e;
	void		*img;
	int			*add;
	t_texture	*texture;
	t_norm		norm;
}	t_cubd;

typedef struct lexer
{
	char	c;
	int		src_size;
	int		j;
	char	*src;
	int		i;
}	t_lexer;

char			*line_map(int fd);
t_cubd			*return_map(char *av, t_cubd *cub);
char			*change_value(char *str);
int				find_path(char *str, char *search);
int				check_if_true(char *str);
t_lexer			*init_lexer(char *src);
void			lexer_skip_space(t_lexer *lexer);
void			lexer_advance(t_lexer *lexer);
void			err_fre_lex_cub(t_lexer *lexer, t_cubd *cub);
char			*get_c_as_str(char c);
void			lexer_skip_space_line(t_lexer *lexer);
char			*take_id(t_lexer *lexer, t_cubd *cub);
void			lexer_back(t_lexer *lexer);
char			*check_id(t_lexer *lexer, t_cubd *cub, char *str, t_g *g);
int				*take_col(t_lexer *lexer, t_cubd *cub, char *str, t_g *g);
void			free_double_p(char **str);
int				lent_double_p(char **str);
int				check_numbers(char **str);
char			**find_er(t_lexer *lexer, t_cubd *cub, char *str);
char			*take_line(t_lexer *lexer);
t_map			*take_map(t_lexer *lexer);
t_map			*init_map(char *str);
void			token_add_back(t_map **map, char *value);
char			**swap_to_double(t_map *map);
int				lst_size(t_map *map);
void			exit_mssg(char *str);
void			check_map(t_cubd *cub);
void			free_cub(t_cubd *cub);
int				all_element(char **map);
int				sur_by_walls(char **map);
int				check_1(char **str);
int				skip_space_start(char *str);
int				skip_space_end(char *str);
int				check_spaces(char **str);
int				check_first_line(char **str);
int				check_last_line(char **str);
int				check_zeros(char **str, int i, int j);
int				one_player(char **str, t_cubd *cub);
unsigned int	pixelget(t_cubd *cub, int x, int y, int i);
void			norm_oneplayer(t_cubd *cub, char **str, int i, int j);
void			norm_take_colore(int *color, char **spl_tmp,
					t_cubd *cub, t_lexer *lexer);
t_g				*init_globals(void);
int				return_offsetx(t_cubd *cub, int ray);
void			generate3d_floor(t_cubd *cub, int j, int ray);
int				generate3d_sky(t_cubd *cub, int j, int ray);
void			norm_generate3d(t_cubd *cub, int ray, double i);
int				rgb_to_int(int r, int g, int b);
int				direction(t_cubd *cub, int ray);
#endif