/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_elemtens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:32:33 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/14 10:41:27 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * note that in this file and future files
 * old comments will not be made.
 */

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}	t_node;

/**
 * this function will add a node to
 * the end of node's list.
 */

void	insert_end(Node **root, int value)
{
	t_node	*new_node = malloc(sizeof(t_node));
	/**
	 * you computer may no have sufficient memory to 
	 * allocate the node, so you need to protect it
	 */
	if (new_node == NULL)
		exit (1);
	new_node->next = NULL;
	new_node->x = value;
}
int	main(int argc, char *argv[])
{
	t_node	root;

	root.x = 15;
	root.next = malloc(sizeof(t_node));
	root.next->x = -2;
	root.next->next = malloc(sizeof(t_node));
	root.next->next->x = 22;
	root.next->next->next = NULL;
	free (root.next->next);
	free (root.next);
	return (0);
}
