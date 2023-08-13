/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:24:46 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/12 21:41:08 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*build a "block" to store data (line x)*/

/**
 * put information, like elements of an array
 * Don't matter if is a array of char or int
 * you can put both type in a struct. (line x)
 * */

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
 * this way only change the way how you write it, but both have same result.
 * (start at line x)
 * */
typedef struct s_Node
{
	int			x;
	struct Node	*next;
}	t_Node;

int	main(int argc, char *argv[])
{
	
}
