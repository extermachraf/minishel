/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:44:33 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/07/01 22:16:01 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishel.h"

int no_second_quote(t_lexer *lexer, char c)
{
    lexer->j = lexer->i;
    lexer->j += 1;
    while(lexer->src[lexer->j] != '\0')
    {
		if(lexer->src[lexer->j] == c)
			return(0);
		lexer->j++;
    }
	return(1);
}


int check_special_c(char c)
{
    if(c == '|' || c == '>'  || c == '<'
        || c == '\'' || c == '"' || c == ' ' || c == '\0')
        return(0);
    else
        return(1);
}

void    check_after_space(t_lexer *lexer, t_token *token)
{
    if(lexer->c <= 32)
    {
        lexer->j = lexer->i;
        while(lexer->src[lexer->j] <= 32)
            lexer->j++;
        if(lexer->src[lexer->j] == '\'' || lexer->src[lexer->j] == '"')
            token_add_back(&token, "space", SPACE);
        lexer->j = 0;
    }
}

void    pick_bitwen_sq(t_lexer *lexer, t_token *token, char **env)
{
    char    *value;
    char    *c;

    if (no_second_quote(lexer, '\'') == 1)
	{
		token_add_back(&token, "ERROR", RED_FLAG);
        lexer_advance(lexer);
		return ;
	}
    value = malloc(sizeof(char));
	value[0] = '\0';
    lexer_advance(lexer);
    while(lexer->c != '\'')
    {
        
        c = get_c_as_str(lexer->c);
		value = ft_realloc(value, (ft_strlen(value) + 1));
		value = ft_strcat(value, c);
		lexer_advance(lexer);
    }
    lexer_advance(lexer);
    token_add_back(&token, value, S_Q);
    check_after_space(lexer, token);
}

void    pick_bitwen_dq(t_lexer *lexer, t_token *token, char **env)
{
    char    *value;
    char    *c;
    char    *tmp;

    if (no_second_quote(lexer, '"') == 1)
	{
		token_add_back(&token, "ERROR", RED_FLAG);
        lexer_advance(lexer);
		return ;
	}
    value = malloc(sizeof(char));
	value[0] = '\0';
    lexer_advance(lexer);
    while(lexer->c != '"')
    {
        if(lexer->c == '$' && ft_isalnum(lexer->src[lexer->i + 1])
            && lexer->src[lexer->i + 1] != '_'
            && lexer->src[lexer->i + 1] != '"')
            c = expand2(lexer, env);
        else
            c = get_c_as_str(lexer->c);
        tmp = value;
		value = ft_strjoin(value, c);
        free(tmp);
        free(c);
		lexer_advance(lexer);
    }
    
    lexer_advance(lexer);
    token_add_back(&token, value, D_Q);
    lexer_advance(lexer);
    check_after_space(lexer, token);
}

void    lexer_back(t_lexer *lexer)
{
    lexer->i--;
    lexer->c = lexer->src[lexer->i];
}

void    check_after(t_lexer *lexer, t_token *token)
{
    lexer->j = lexer->i;
    while(lexer->src[lexer->j] <= 32)
        lexer->j++;
    if(check_special_c(lexer->src[lexer->j]) == 1)
        token_add_back(&token, "space", SPACE);
}
