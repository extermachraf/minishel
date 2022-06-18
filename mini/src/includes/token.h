/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:42:55 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/17 19:15:20 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
#define TOKEN_H
#include "lexer.h"

typedef struct token
{
    char	*value;
	enum
	{
		TOKEN_ID,
		WORD,
		S_Q,
		D_Q,
		REDIRECT_IN,//  <
		REDIRECT_OT,//  >
		D_REDIRECT_IN,// <<
		D_REDIRECT_out,// >>
		DOLLAR,// $
		TOKEN_EOF,
	}	type;
	struct token *next;
}	t_token;

t_token	*init_token(char *value, int type);
#endif