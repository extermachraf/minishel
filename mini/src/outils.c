/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:43 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/16 16:46:38 by ael-kouc         ###   ########.fr       */
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