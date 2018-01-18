/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:16:48 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 14:37:28 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct		s_index
{
	int		i;
	int		j;
	int		argc;
}					t_index;

typedef struct		s_datas
{
	char	*save;
	int		save_index;
	int		pack_size;
	int		nb_appel;
	int		encadreur;
	int		med;
	int		to_put;
	int		x;
	int		i;
	int		n;
}					t_datas;

typedef struct		s_merge
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		diff_rr;
	int		diff_rrr;
	int		i;
	int		j;
}					t_merge;

typedef struct		s_rot
{
	int		rotate;
	int		reverse_rotate;
	int		nb_rotate;
	int		nb_reverse_rotate;
}					t_rot;

void				ft_push_swap(int *origine, int nb);
void				ft_free_double_tab(char **av);
void				ft_norme_boucle1(int *pile1, int *pile2,\
		t_index *index, t_datas *d);
void				ft_norme_boucle2(int *pile1, int *pile2,\
		t_index *index, t_datas *d);
void				ft_norme_boucle3(int *pile1, int *pile2,\
		t_index *index, t_datas *d);
void				ft_norme_boucle4(int *pile1, int *pile2,\
		t_index *index, t_datas *d);
void				ft_norme_boucle4bis(int *pile1, int *pile2,\
		t_index *index, t_datas *d);
void				ft_supp_doublons(char *save, t_merge m);
int					ft_find_which_place_top_of_pa(int to_put,\
		int *pile1, t_index *index, t_datas *d);
int					find_min_in_pile2(int *pile2, t_index *index);
int					find_max_in_pile2(int *pile2, t_index *index);
int					find_closest(int *smallest, int n,\
		int *pile2, t_index *index);
int					find_closest_in_the_n_biggest_to_x(int *pile2,\
		t_index*index, int n, int x);
int					find_closest_in_the_n_smallest_from_x(int *pile2,\
		t_index *index, int n, int x);
void				ft_reput_sorted_to_pile1_for_small2(int *pile1,\
		int *pile2, t_index *index, t_datas *d);
void				ft_reput_sorted_to_pile1_for_small(int *pile1,\
		int *pile2, t_index *index, t_datas *d);
void				ft_replace_pack_in_pile1_for_small(int *pile1,\
		int *pile2, t_index *index, t_datas *d);
void				ft_place_pack_in_pile2_for_small(int *pile1,\
		int *pile2, t_index *index, t_datas *d);

void				ft_reput_sorted_to_pile1(int *pile1, int *pile2,\
		t_index *index, t_datas *d);
void				ft_replace_pack_in_pile1(int *pile1, int *pile2,\
		t_index *index, t_datas *d);
void				ft_place_pack_in_pile2(int *pile1, int *pile2,\
		t_index *index, t_datas *d);
void				ft_merging_instr(char *save, int save_index);

int					ft_is_in_tab(int *tmp, int len, int to_find);
int					*ft_find_biggest_sort_down(int *pile2, t_index n, int *z);
int					*ft_find_biggest_sort_up(int *pile1,\
		int m, int *z, t_index n);
int					ft_find_max_b(int *pile2, t_index n);
int					sim_rb(int *pile1, int j, int sommet);
int					sim_rrb(int *pile1, int j, int sommet);
void				ft_find_road_b(int to_find, int *pile2,\
		t_index *n, t_datas *d);
void				find_road_a(int to_find, int *pile1,\
		t_index *n, t_datas *d);
void				ft_print(int *tab, int nb);
void				ft_put_instr(char *save, int s);
int					ft_is_sort(int *pile, t_index n);
void				ft_sort(int *pile, t_index *n, t_datas *d);
void				ft_cop(int *origine, int *tmp, int nb);
int					ft_transcription(int *tmp, int *origine, int nb);
int					ft_quick_sort_big(int *pile1, int nb);
void				ft_sort_for_less_ten(int *pile1, int nb);
int					ft_quick_sort_small(int *pile1, int nb);
void				ft_sort_for_three_nbrs(int *pile1, int nb);

void				make_ra(int *pile1, t_index *n, t_datas *d);
void				make_rb(int *pile2, t_index *n, t_datas *d);
void				make_rr(int *pile1, int *pile2, t_index *n, t_datas *d);
void				make_rra(int *pile1, t_index *n, t_datas *d);
void				make_rrb(int *pile2, t_index *n, t_datas *d);
void				make_sa(int *pile1, t_index *n, t_datas *d);
void				make_sb(int *pile2, t_index *n, t_datas *d);
void				make_ss(int *pile1, int *pile2, t_index *n, t_datas *d);
void				make_pa(int *pile1, int *pile2, t_index *n, t_datas *d);
void				make_pb(int *pile1, int *pile2, t_index *n, t_datas *d);
void				make_rrr(int *pile1, int *pile2, t_index *n, t_datas *d);

void				instr_sa(int *pile1, t_index *n);
void				instr_sb(int *pile2, t_index *n);
void				instr_ss(int *pile1, int *pile2, t_index *n);
void				instr_pa(int *pile1, int *pile2, t_index *n);
void				instr_pb(int *pile1, int *pile2, t_index *n);
void				instr_ra(int *pile1, t_index *n);
void				instr_rb(int *pile2, t_index *n);
void				instr_rr(int *pile1, int *pile2, t_index *n);
void				instr_rra(int *pile1, t_index *n);
void				instr_rrb(int *pile2, t_index *n);

int					*ft_parsing(int argc, char **argv);
int					*ft_parsing_swap(int argc, char **argv);
int					do_instr(int *pile1, int argc);

#endif
