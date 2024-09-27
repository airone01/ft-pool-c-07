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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	src_len;
	int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	return (dest);
}

int	get_final_size(int size, char **strs, int size_sep)
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
	final = malloc(get_final_size(size, strs, size_sep) * sizeof(char));
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
