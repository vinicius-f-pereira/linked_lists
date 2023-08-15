/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_beggining.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:26:54 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/15 07:46:48 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * this file will have only one function more
 * compared with 'add...elements file' that's a
 * function to add at beggining of a list
 */

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}	t_node;

void	insert_beginning(t_node **root, int value)
{
	t_node *new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	/**
	 * idea here is very simple
	 * we make new node get position (just position, not the value)
	 * and then say to root assume position of new node.
	 * If you have root with number 15, and new node with number 13
	 * when you call this function, new node will be the node with value 15
	 * and root the node will value 13.
	 */
	new_node->x = value;
	new_node->next = *root;

	*root = new_node;
}

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
int	main(int argc, char *argv[])
{
	t_node	*root;
	
	root = malloc(sizeof(t_node));
	if (root == NULL)
		exit (2);
	root->x = 15;
	root->next = NULL;

	insert_beginning(&root, 13);
	insert_beginning(&root, 11);
	insert_beginning(&root, 12);
	insert_beginning(&root, 14);
	for (t_node *current = root; current != NULL; current = current->next)
	{
		printf("%d\n", current->x);
	}
	return (0);
	}
