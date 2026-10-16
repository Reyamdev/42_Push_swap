/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 23:09:25 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:35:38 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Traverses the original list
 *        ↓
 * applies f(content)
 *        ↓
 * creates a NEW node with the transformed content
 *        ↓
 * appends it to a NEW list
 *        ↓
 * if allocation fails:
 *        ↓
 * 		deletes the newly created content
 *        ↓
 * 		clears every node already created with 'del'
 *        ↓
 *	 	returns NULL
 *
 * Returns the head of the new mapped list on success.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
