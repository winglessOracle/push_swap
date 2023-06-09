/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 09:51:22 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/31 12:14:39 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free(void *param)
{
	if (param)
		free(param);
	param = 0;
}
