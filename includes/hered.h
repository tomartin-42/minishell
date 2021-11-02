/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hered.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 07:39:50 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/01 19:12:28 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERED_H
# define HERED_H

# include "minishell.h"

void	main_hered(t_element *elemento, t_env *env, int sig);
void	close_hered(t_element *element);

#endif
