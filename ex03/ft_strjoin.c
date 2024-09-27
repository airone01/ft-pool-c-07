/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:20:54 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/25 11:02:04 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // aaaaaaaaaaaaaaaaaaaa

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (1);
	return (ft_strlen (str + 1) + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	src_len;
	int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (i < (src_len - 1))
	{
		dest[i + dest_len - 1] = src[i];
		i++;
	}
	// dest[i + dest_len - 1] = '\0';
	return (dest);
}

int	getFinalSize(int size, char **strs, int size_sep)
{
	int	size_final;
	int	i;

	i = 0;
	size_final = 0;
	while (i < size)
	{
		size_final += ft_strlen(strs[i]);
		if (i != size - 1)
			size_final += size_sep;
		i++;
	}
	return (size_final);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		size_sep;
	int		i;
	char	*final;

	if (size == 0)
		return (malloc(sizeof(char)));
	size_sep = ft_strlen(sep);
	final = malloc(getFinalSize(size, strs, size_sep) * sizeof(char));
	if (final == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(final, strs[i]);
		if (i != size - 1)
			ft_strcat(final, sep);
		i++;
	}
	return (final);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	char	*dest;
// 	char	*sep;
//
// 	// dest = malloc(sizeof(char));
// 	argv++;
// 	sep = *argv++;
// 	dest = ft_strjoin(argc - 2, argv, sep);
// 	printf("%s", dest);
// 	free(dest);
// }
