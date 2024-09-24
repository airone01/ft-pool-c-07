/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:51:01 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/24 09:03:39 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + ft_strlen(str + 1));
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int	i;

	dest = malloc(ft_strlen(src));
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	printf("%s\n", ft_strdup(argv[1]));
// }
