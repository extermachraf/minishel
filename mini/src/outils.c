/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:43 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/20 16:55:37 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishel.h"

void	get_back_pipes(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < 0)
				str[i][j] *= -1;
			j++;
		}
		i++;
	}
}

char	**split_redline_pip(char *str)
{
	int		i;
	char	c;
	char	**readline;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			c = str[i];
			i++;
			while (str[i] != c)
			{
				if (str[i] == '|')
					str[i] *= -1;
				i++;
			}
		}
		i++;
	}
	readline = ft_split(str, '|');
	get_back_pipes(readline);
	return(readline);
}

char	*get_c_as_str(char c)
{
	char *str;

	str = malloc(sizeof(char ) * 2);
	str[0] = c;
	str[1] = '\0';
	return(str);
}

int	eroor_quote(t_lexer *lexer, char c)
{
	lexer->j = lexer->i + 1;
	while(lexer->src[lexer->j])
	{
		if(lexer->src[lexer->j] == c)
			return(1);
		lexer->j++;
	}
	return(0);
}

int eroor_pip(t_lexer *lexer, char c)
{
	lexer->j = lexer->i - 1;
	while(lexer->src[lexer->j] <= 32 &&
		lexer->j >= 0)
		lexer->j--;
	if(lexer->src[lexer->j] == '|')
		return(1);
	lexer->j = lexer->i + 1;
	while(lexer->src[lexer->j] <= 32 &&
		lexer->src[lexer->j])
		lexer->j++;
	if(lexer->src[lexer->j] == '|' ||
		lexer->src[lexer->j] == '\0')
		return(1);
	return(0);
}
