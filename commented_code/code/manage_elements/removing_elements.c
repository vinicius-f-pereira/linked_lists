/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removing_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:21:31 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/15 12:58:31 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}	t_node;

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

void	insert_sorted(t_node **root, int value)
{
	if (*root == NULL || (*root)->x >= value)
	{
		insert_beginning(root, value);
		return ;
	}
	t_node *current = *root;
	while (current->next != NULL)
	{
		if (current->next->x >= value)
		{
			break ;
		}
		current = current->next;
	}
	insert_after(current, value);
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

void	remove_element(t_node **root, int value)
{
	t_node	*current;
	t_node	*to_remove;

	current = *root;
	if (*root == NULL)
		return ;
	if ((*root)->x == value)
	{
		to_remove = *root;
		*root = (*root)->next;
		free(to_remove);
		return ;
	}
	while (current->next != NULL)
	{
		if (current->next->x == value)
		{
			to_remove = current->next;
			current->next = current->next->next;
			free(to_remove);
			return ;
		}
		current = current->next;
	}
}
int	main(int argc, char *argv[])
{
	t_node	*root = NULL;

	insert_sorted(&root, 5);
	insert_sorted(&root, 4);
	insert_sorted(&root, 3);
	insert_sorted(&root, 7);

	remove_element(&root, 7);
	
	for (t_node *current = root; current != NULL; current = current->next)
	{
		printf("%d\n", current->x);
	}
	deallocate(&root);
	return (0);
}
