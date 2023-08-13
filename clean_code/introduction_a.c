/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:58:19 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/13 01:23:15 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_Node
{
	int			x;
	struct s_Node	*next;
}	t_Node;

int	main(int argc, char *argv[])
{
	
	t_Node	root;

	root.x = 15;
	root.next = malloc(sizeof(t_Node));
	root.next->x = -2;
	root.next->next = NULL;

	printf("First: %d\n", root.x);
	printf("Next x: %d\n", root.next->x);
	printf("Next Next: %p\n", root.next->next);

	free(root.next);
	return (0);
}
