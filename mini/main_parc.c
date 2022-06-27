/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:47:34 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/27 16:13:30 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int main()
{
    char *str;
    t_parser *parser;
    t_lexer *lexer;
    t_token *token;
    while(1)
    {
        str = readline("minishel>");
        add_history(str);
        lexer = init_lexer(str);
        token = pick_tokens(lexer);
        // parser = return_error(token);
        // printf("%s\n", parser->value);
        t_token *tmp;
        tmp = token;
        while(tmp)
        {
            printf("{%s}  ===  %d\n", tmp->value, tmp->type);
            tmp = tmp->next;
        }
        free (lexer->src);
        free(lexer);
        while(token != NULL)
        {
            tmp = token;
            token = token->next;
            free(tmp);
        }
        token = NULL;
    }
}