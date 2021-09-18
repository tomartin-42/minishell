/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/18 20:47:56 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"							

#define CLOSE "\001\033[0m\002"                 // cierra todas las propiedades
#define BLOD  "\001\033[1m\002"                 // enfatizar, negrita, resaltar
#define BEGIN(x,y) "\001\033["#x";"#y"m\002"    // x: fondo, y: primer plano

int main(void)
{
	char *str;
while (1)
{
	str = readline(BEGIN(49, 34)"Myshell $ "CLOSE);
	printf("%s", str);
	free(str);
	printf("HOLA2\n");
}
}
