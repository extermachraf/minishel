/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:30:38 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/27 15:22:43 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishel.h"

t_parser	*init_parser(char *value, int type, int i)
{
    t_parser	*parser;
    
	parser = malloc(sizeof(t_parser));
	parser->value = value;
    parser->type = type;
    parser->betwin_c_w = i;
	parser->next = NULL;
	return(parser);
}

t_parser    *return_error(t_token *token)
{
	t_parser *parser;
	
	if (check_err_pip(token) == 0)
		return(init_parser("syntax error in pip", ERROR, 2));
    else if (check_err_quote(token) == 0)
        return(init_parser("please close quote", ERROR, 2));
	else if (check_err_red(token) == 0)
		return(init_parser("synta error in red", ERROR, 2));
	else
		return(init_parser("all good", GOOD, 0));
}

// t_parser	*fill_parser_norm(t_token *token, t_parser *parser)
// {
// 	t_token	*tmp;

// 	tmp = token;
// 	parser = init_parser("Start", STAR, 1);
// 	while(tmp)
// 	{
// 		if(tmp->type == CMD_WORD)
			
// 		tmp = tmp->next;
// 	}
// }

// t_parser	*fill_parser(t_token *token)
// {
// 	t_parser *parser;
	
// 	parser = return_error(token);
// 	if(!(parser->type == GOOD))
// 		return(parser);
// 	parser = fill_parser_norm(token, parser);
// }

