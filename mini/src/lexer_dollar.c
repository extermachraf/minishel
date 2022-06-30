/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:41:57 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/30 19:57:32 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishel.h"

char	*check_env(char *str, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while(env[i])
	{
		if(!strncmp(str, env[i], ft_strlen(str)))
		{
			tmp = str;
			str = ft_substr(env[i], ft_strlen(tmp) + 1, ft_strlen(env[i]));
			break;
		}
		i++;
	}
	if(env[i] == 0)
	{
		tmp = str;
		str = ft_strdup("\0");
	}
	return(str);
}

char	*expand(t_lexer *lexer, char **env)
{
	char	*str;
	int i;
	char	*real_value;
	
	i = 0;
	lexer_advance(lexer);
	lexer->j = lexer->i;
	// if(lexer->c == '$')
	// 	return(get_c_as_str(lexer->c));
	while(lexer->src[lexer->j] && (ft_isalnum(lexer->src[lexer->j])
		|| lexer->src[lexer->j] == '_'))
		lexer->j++;
	str = malloc(sizeof(char) * (lexer->j - lexer->i + 1));
	while(lexer->i < lexer->j)
	{
		str[i] = lexer->c;
		lexer_advance(lexer);
		i++;
	}
	lexer_back(lexer);
	str[i] = '\0';
	real_value = check_env(str, env);
	free(str);
	return(real_value);
}