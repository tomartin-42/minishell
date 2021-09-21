/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/19 13:23:24 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"							

#define CLOSE "\001\033[0m\002"                 // cierra todas las propiedades
#define BLOD  "\001\033[1m\002"                 // enfatizar, negrita, resaltar
#define BEGIN(x,y) "\001\033["#x";"#y"m\002"    // x: fondo, y: primer plano

int main(void)
{
	t_input	*input;

	input = malloc(sizeof(t_input));;
	while (1)
	{
		input->str = readline(BEGIN(49, 34)"Myshell $ "CLOSE);
		printf("%s\n", input->str);
		free(input->str);
	}
}
