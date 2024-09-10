/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:53:05 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 16:54:42 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lists_top, t_list *new_add_list)
{
	t_list	*last_list;

	if (!lists_top || !new_add_list)
		return ;
	if (!*lists_top)
		*lists_top = new_add_list;
	else
	{
		last_list = ft_lstlast(*lists_top);
		last_list->next = new_add_list;
	}
}
