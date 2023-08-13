/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:24:46 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/13 01:21:30 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_Node
{
	int			x;
	struct s_Node	*next;
}	t_Node;

int	main(int argc, char *argv[])
{
	t_Node	root;
	t_Node	elem2;

	root.x = 15;
	root.next = &elem2;
	elem2.x = -2;
	elem2.next = NULL;
	
	printf("First: %d\n", root.x);
	printf("First: %d\n", elem2.x);
	return (0);
}
