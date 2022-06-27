/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:24:27 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/27 14:13:48 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishel.h"
# define ERROR 0
# define GOOD 1
# define STAR 2

typedef struct parser
{
	char	*value;
	int		type;
	int		betwin_c_w;
	struct parser *next;
}	t_parser;

t_parser	*init_parser(char *value, int type, int i);
int			check_err_quote(t_token *token);
int			check_err_red(t_token *token);
int			check_err_pip(t_token *token);
t_parser    *return_error(t_token *token);
#endif
