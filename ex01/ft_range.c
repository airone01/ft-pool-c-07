/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:59:09 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/24 10:38:24 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Returns:
 * - pointer to ints if everything worked
 * - NULL if malloc failed
*/
int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;

	if (min >= max)
		return (0);
	dest = malloc(sizeof(int) * (max - min));
	if (dest == 0)
		return (0);
	i = min;
	while (i < max)
	{
		dest[i] = i;
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	*dest;
// 	int	i;
//
// 	dest = ft_range(0, 5);
// 	i = 0;
// 	while(i < 5)
// 	{
// 		printf("%d, ", dest[i]);
// 		i++;
// 	}
// 	free(dest);
// }
