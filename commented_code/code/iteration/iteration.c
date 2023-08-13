/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 01:17:25 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/13 04:42:57 by vde-frei         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_node	root;
	t_node	*current;

	root.x = 15;
	root.next = malloc(sizeof(t_node));
	root.next->x = -2;
	root.next->next = malloc(sizeof(t_node));
	/* this piece of code is made after the end of code
	 * to add more one node in linked list
	 * with it, when you print linked lists in the while loop
	 * this number (22) will be printed too.
	 */
	root.next->next->x = 22;
	root.next->next->next = NULL;
	/**
	 * to go through an array we can use index
	 * in linked list we need of another node that
	 * take initial list (root list) and make a
	 * loop to it works.
	 * I'll create that node below of root node.
	 */
	//here you need to put '&' in root variable to get address.
	current = &root;
	while (current != NULL)
	{
		printf("%d\n", current->x);
		current = current->next;
	}
	/* keep in mind that when you free allocated variables, you need to do it like a stack
	 * if you free the first variable allocated, it should return a error.
	 * use LIFO to do that!
	 */
	free (root.next->next);
	free (root.next);
	return (0);
}
