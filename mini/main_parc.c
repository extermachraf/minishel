/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:47:34 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/06/17 16:53:09 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int main()
{
    char *str;
    while(1)
    {
        str = readline("minishel==>");
        add_history(str);
        char **g;
        g = split_redline_pip(str);
        int i = 0;
        while(g[i])
        {
            printf("%s\n", g[i]);
            i++;
        }
   
    }
}