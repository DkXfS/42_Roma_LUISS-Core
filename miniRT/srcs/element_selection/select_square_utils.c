/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_square_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:51:38 by apanthap          #+#    #+#             */
/*   Updated: 2021/04/19 11:51:40 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_square(void *param, t_v axis)
{
	t_square	*square;

	square = (t_square *)param;
	square->c = v_sum(square->c, v_scalar_mul(axis, MOVE_EPSILON));
}
