/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 11:57:30 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/21 13:50:06 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "./get_next_line.h"


#define SA 0
#define SB 2
#define RA 4
#define RRA 5
#define RB 7
#define RRB 8
#define PA 10
#define PB 11
#define RR 13
#define RRR 15
#define SS 17

typedef struct s_link
{
	int				value;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;


typedef struct s_pile
{
	int		size;
	t_link  *head;
}				t_pile;

typedef struct s_stru
{
	t_pile	*pla;
	t_pile	*plb;
	t_pile	*lst_pb;
	t_pile	*instru;
}				t_stru;

void		print_pile(t_pile *pl, int fd);
void		delete_link(t_link *del);
t_pile		*add_link(t_pile *pl, int nb);
void		delete_pile(t_pile *pl);
t_pile		*create_pile(void);

void		swap(t_pile *pl);
void		rotate(t_pile *pl);
void		rev_rotate(t_pile *pl);
void		push_sd(t_pile *src, t_pile *dest);

int			check_doublons(t_pile *pl);
int			error_checker(int size, char **tab);
int			check_sorted(t_pile *pl);

void		two_piles_qs(t_pile *pla, t_pile *plb);
void		quicksort(t_pile *pl, int sort(int, int), int pivot, int end, t_pile *instru);
int			croissant(int pivot, int value);
int			decroissant(int pivot, int value);

void		rec_qs(t_pile *pl, int sort(int, int), int pivot, int end);

void		push_instru(t_pile *instru, int value);
void		print_instru(t_pile *instru);

int			*create_array(t_pile *pl, int size);
void		tab_quicksort(int *tab, int head, int tail);

void		simple_sort(t_pile *pla, t_pile *plb, t_pile *instru);

int			find_pivot(t_pile *pl, int size);
int			divide_pile_pla(int size, t_stru *pl);
int			divide_pile_plb(int size, t_stru *pl);
void		full_sort(t_pile *pla, t_pile *plb, t_pile *instru);

void		sb_sa(t_pile *pl, t_pile *instru, int i);
void		rb_ra(t_pile *pl, t_pile *instru, int i);
void		rrb_rra(t_pile *pl, t_pile *instru, int i);
void		pb_pa(t_pile *pls, t_pile *pld, t_pile *instru, int i);

t_pile		*parse_string(char *str, t_pile *pl);
# endif
