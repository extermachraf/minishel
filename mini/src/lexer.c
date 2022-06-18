/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:50:32 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/17 21:49:24 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishel.h"


t_lexer	*init_lexer(char *src)
{
	t_lexer *lexer;

	lexer = malloc(sizeof(t_lexer));
	lexer->src = src;
	lexer->src_size = ft_strlen(src);
	lexer->i = 0;
	lexer->j = 0;
	lexer->c = lexer->src[lexer->i];
	if(lexer->src[lexer->i + 1] != '\0')
		lexer->n_c = lexer->src[lexer->i + 1];
	return (lexer);
}

void	lexer_skip_space(t_lexer *lexer)
{
	while(lexer->src[lexer->i])
	{
		if(lexer->src[lexer->i] == ' ' || lexer->src[lexer->i] == '\t'
		|| lexer->src[lexer->i] == '\n' || lexer->src[lexer->i] == '\r')
			lexer_advance(lexer);
	}
	
}

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->i < lexer->src_size && lexer->i != '\0')
	{
		lexer->i++;
		lexer->c = lexer->src[lexer->i];
		if (lexer->src[lexer->i + 1] != '\0')
			lexer->n_c = lexer->src[lexer->i + 1];
	}
}

t_token	*lexer_parse_id(t_lexer *lexer)
{
	char *value;

	value = malloc(sizeof(char) * 1);
	while(ft_isalnum(lexer->c))
	{
		ft_realloc(value, ft_strlen(value) + 2);
		value = ft_strcat(value, (char[]){lexer->c ,0});
		lexer_advance(lexer);
	}
	return(init_token(value, TOKEN_ID));
}

t_token	*lexer_advance_with(t_lexer *lexer, t_token *token)
{
	lexer_advance(lexer);
	return(token);
}

t_token	*lexer_next_token(t_lexer *lexer, t_token *token)
{
	while(lexer->c != '\0')
	{
		if(ft_isalnum(lexer->c))
			return(lexer_advance_with(lexer, lexer_parse_id(lexer)));
		if(lexer->c == '|')
		else if(lexer->c == '\'')
		else if(lexer->c == '"')
		else if(lexer->c == '<' && lexer->n_c == '<')
		else if(lexer->c == '>' && lexer->n_c == '>')
		else if(lexer->c == '<' && lexer->n_c != '<')
		else if(lexer->c == '>' && lexer->n_c != '>')
		else if(lexer->c == '$')	
	}
	return(init_token(0, TOKEN_EOF));
}
