/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_elemtens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:32:33 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/14 18:58:47 by vde-frei         ###   ########.fr       */
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

void	insert_end(t_node **root, int value)
{
	t_node	*new_node = malloc(sizeof(t_node));
	/**
	 * you computer may no have sufficient memory to 
	 * allocate the node, so you need to protect it
	 */
	if (new_node == NULL)
		exit (1); //is the same thing to just 'return ;' but say do main the error code 1.
	new_node->next = NULL;
	new_node->x = value;

	/**
	* verify if root isn't a NULL pointer
	* if root is a new pointer, make it point to new_node
	* if you try add something without this step, you code will crash
	* this need to point and change an address, if it's null, you'll 
	* get an error!
	*/
	if (*root == NULL)
	{
		*root = new_node;
	}
	/**
	 * now we need to make this go to the last node
	 * so we need to implement a loop to verify when
	 * we are at the last node and insert it there.
	 */

	t_node *current = *root;
	while (current->next != NULL)
	{
		current = current->next;
	}
	/**
	 * after run through all list (nodes)
	 * we need to end current node with new_node
	 * that keeps '->next = NULL'
	 */
	current->next = new_node;
}
int	main(int argc, char *argv[])
{
	/**
	 * change the way that it's write to improve code
	 * need to reference root with pointer and arguments of
	 * the struct with arrows and malloc root with size of t_node
	 * difference between dot and arrow is that arrows also derreference the pointer
	 * and dot you just get the struct member from a variable that is not a pointer
	 */
	t_node	*root;
	
	root = malloc(sizeof(t_node));
	if (root == NULL)
		exit (2);
	root->x = 15;
	root->next = NULL;

	insert_end(&root, -2);
	insert_end(&root, -11);
	for (t_node *current = root; current != NULL; current = current->next)
	{
		printf("%d\n", current->x);
	}
	return (0);
	}
