/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:22:26 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 16:39:53 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fractol.h"

int	main(int a, char **b)
{
	if (!handle_error(a, b))
		return (0);
	entry_main(b);
	return (0);
}
