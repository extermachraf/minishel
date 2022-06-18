/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:51:20 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/14 14:44:56 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishel.h"

t_token	*init_token(char *value, int type)
{
	t_token *token;

	token = malloc(sizeof(t_token)); 
	token->value = value;
	token->type = type;
	return (token);
}