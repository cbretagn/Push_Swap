/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 11:57:30 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/02 15:57:28 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_link
{
	int				value;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;


typedef struct s_pile
{
	int		size;
	t_link  **head;
}				t_pile;


void		print_pile(t_pile *pl, int fd);
void		delete_link(t_link *del);
t_pile		*add_link(t_pile *pl, int nb);
void		delete_pile(t_pile *pl);
t_pile		*create_pile(void);

void		swap(t_pile *pl);
void		rotate(t_pile *pl);
void		rev_rotate(t_pile *pl);
t_pile		*push_sd(t_pile *src, t_pile *dest);
# endif