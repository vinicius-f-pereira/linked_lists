/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:58:19 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/13 00:30:10 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * now we'll allocate 'next' dynamically instead of
 * create another node to point as 'next'
 */

typedef struct s_Node
{
	int			x;
	struct s_Node	*next;
}	t_Node;

int	main(int argc, char *argv[])
{
	/* start to define our list like in introduction.c file */
	t_Node	root;
	root.x = 15;
	/* now, we need to malloc next; */
	root.next = malloc(sizeof(t_Node));
	/**
	 * now call 'next' and give a NULL pointer or
	 * an address of another Node or a value.
	 * the arrow notation '->' use when need to point to
	 * next node.
	 */
	root.next->x = -2;
	/* now the same behavior to the NULL pointer. */
	root.next->next = NULL;
	/* note that here we don't want more 'Nodes' in next, so we can assign 'NULL' to *.next' */
	printf("First: %d\n", root.x);
	printf("Next x: %d\n", root.next->x);
	printf("Next Next: %p\n", root.next->next);
	return (0);
}
