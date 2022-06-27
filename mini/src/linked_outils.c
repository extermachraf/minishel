/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:38:06 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/26 08:06:21 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishel.h"

void    free_first_node(t_token *token)
{
    t_token *tmp;

    tmp = token;
    token = token->next;
    free(tmp);
}

