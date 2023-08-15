/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_after_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:41:58 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/15 08:51:53 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


typedef struct s_node
{
	int				x;
	struct s_node	*next;
}	t_node;

/**
 * here don't need to be a pointer to a pointer, because
 * we want only to change one node
 */
void	insert_after(t_node *node, int value)
{
	t_node *new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = value;
	new_node->next = node->next;

	node->next = new_node;
}

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

void	insert_beginning(t_node **root, int value)
{
	t_node *new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
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
		return ;
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
	t_node	*root = NULL;
	

	insert_end(&root, 2);
	insert_end(&root, 4);
	insert_end(&root, 5);

	insert_after(root, 7);

	
	for (t_node *current = root; current != NULL; current = current->next)
	{
		printf("%d\n", current->x);
	}
	deallocate(&root);
	return (0);
}
