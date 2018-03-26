/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:58:13 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:58:15 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

t_list			*ft_create_elem(void *data);
void			ft_list_push_back(t_list **begin_list, void *data);
void			ft_list_push_front(t_list **begin_list, void *data);
int				ft_list_size(t_list *begin_list);
t_list			*ft_list_last(t_list *begin_list);
t_list			*ft_list_push_params(int ac, char **av);
void			ft_list_clear(t_list **begin_list);
t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
void			ft_list_reverse(t_list **begin_list);
void			ft_list_foreach(t_list *begin_list, void (*f)(void *));
void			ft_list_foreach_if(t_list *a, void (*f)(void *), void *d,
				int (*c)());
t_list			*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void			ft_list_remove_if(t_list **a, void *data_ref, int (*cmp)());
void			ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void			ft_list_sort(t_list **begin_list, int (*cmp)());
void			ft_list_reverse_fun(t_list *begin_list);
void			ft_sorted_list_insert(t_list **a, void *data, int(*cmp)());
void			ft_sorted_list_merge(t_list **a, t_list *b, int (*cmp)());

#endif
