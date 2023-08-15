/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:15:47 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/14 22:54:08 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * you should noted that this code is exactly
 * same code of 'adding_elements', but you need to
 * pay attention in 'deallocate' function in this example
 */
typedef struct s_node
{
	int				x;
	struct s_node	*next;
}	t_node;

void	insert_end(t_node **root, int value)
{
	t_node	*new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit (1);
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
	{
		*root = new_node;
	}
	t_node *current = *root;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

	/**
	 * in while loop we'll make aux point to
	 * position of current node, and then
	 * current node point to 'current->next'
	 * so we can free current (now in aux) without lost 
	 * the referrence of next node.
	 */
void	deallocate(t_node **root)
{
	t_node *current;
	t_node *aux;

	current = *root;
	while (current != NULL)
	{
		t_node *aux = current;
		current = current->next;
		free(aux);
	}
	*root = NULL;
}

int	main(int argc, char *argv[])
{
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
	deallocate(&root);
	_CrtDumpMemoryLeaks();
	return (0);
}
