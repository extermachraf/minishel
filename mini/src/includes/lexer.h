/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:41:21 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/17 19:14:27 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H
#include "token.h"
typedef struct lexer
{
	char	c;
	int		src_size;
	int		j;
	char	*src;
	int		i;
	char	n_c;
}	t_lexer;

t_lexer	*init_lexer(char *src); 
void	lexer_advance(t_lexer *lexer);
void	lexer_skip_space(t_lexer *lexer);
t_token	*lexer_next_token(t_lexer *lexer, t_token *token);
t_token	*lexer_parse_id(t_lexer *lexer);
t_token	*lexer_advance_with(t_lexer *lexer, t_token *token);
// t_token	*lexer_next_token(t_lexer *lexer);
#endif  