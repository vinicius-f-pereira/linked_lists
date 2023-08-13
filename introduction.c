/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:24:46 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/12 23:34:57 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*build a "block" to store data (line x)*/

/**
 * put information, like elements of an array
 * Don't matter if is a array of char or int
 * you can put both type in a struct.
 */

/**
 * After set all variables (int, char, size_t, etc...)
 * you need to declare a pointer variable of the same type
 * of your struct, in this case Node* and call it "next" to be the next
 * element of our linked list. And to use it and "say" to the computer
 * that you want to call a struct and not a typedef, you need to write 
 * 'struct' before node name or you can do it like example bellow:
 *
 * typedef struct	s_node t_node;
 * struct s_node
 * {
 *	int x;
 *	Node *next;
 * };
 *
 * this only change the way how you write it, but both have same result.
 */
typedef struct s_Node
{
	int			x;
	struct s_Node	*next;
}	t_Node;

int	main(int argc, char *argv[])
{
	/* start to define our list */
	t_Node	root;
	/* create a second to use as an address in 'next' */
	t_Node	elem2;
	root.x = 15;
	/* now call 'next' and give a NULL pointer or an address of another Node. */
	root.next = &elem2;
	/* now the same behavior of root will be repeated. */
	elem2.x = -2;
	/* note that here we don't want more 'Nodes' in next, so we can assign 'NULL' to *.next' */
	elem2.next = NULL;
	printf("First: %d\n", root.x);
	printf("First: %d\n", elem2.x);
	return (0);
}
