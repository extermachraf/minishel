/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:47:34 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/07/01 12:30:51 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int main(int ac, char **av, char **envp)
{
    t_mini  *mini;
    char    *str;

    mini = malloc(sizeof(t_mini));
    mini->env = get_env(envp);
    while(1)
    {
        str = readline("minishel>");
        add_history(str);
        mini->lexer = init_lexer(str);
        mini->token = pick_tokens(mini->lexer, envp);
        // mini->parser = return_error(mini->token);
    //     // printf("%s\n", mini->parser->value);
        t_token *tmp;
        tmp = mini->token;
        tmp = tmp->next;
        while(tmp)
        {
            printf("{%s}  ===  %d\n", tmp->value, tmp->type);
            tmp = tmp->next;
        }
        free (mini->lexer->src);
        free(mini->lexer);
        while(mini->token != NULL)
        {
            tmp = mini->token;
            mini->token = mini->token->next;
            free(tmp);
        }
        mini->token = NULL;
        free(str);
    }
}