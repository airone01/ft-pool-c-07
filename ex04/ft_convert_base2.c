/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:56:03 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/25 15:42:22 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_strlen(str + sizeof(char)) + 1);
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
	dest[i + dest_len - 1] = '\0';
	return (dest);
}

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		size;
	int		negative;
	int		tmp;
	char	*str;

	negative = 0;
	size = 0;
	if (nbr < 0)
		negative = 1;
	tmp = nbr;
	while (tmp /= ft_strlen(base))
		size++;
	size = size + negative + 1;
	str = (char *) malloc(sizeof(char) * (size  + 1));
	str[size] = '\0';
	if (negative == 1)
		str[0] = '-';
	while (size > negative)
	{
		str[size - 1] = base[ft_abs(nbr % ft_strlen(base))];
		size--;
		nbr /= ft_strlen(base);
	}
	return (str);
}

// char	*ft_itoa_base(int nbr, char *base)
// {
// 	int		base_len;
// 	char	*tmp;
// 	char	*a;
// 	char	*b;
//
// 	if (nbr == 0)
// 		return "";
// 	base_len = ft_strlen(base);
// 	if (nbr < 0)
// 	{
// 		// write(1, "-", 1);
// 		nbr = -nbr;
// 	}
// 	if (nbr >= base_len)
// 	{
// 		ft_itoa_base(nbr / base_len, base);
// 	}
// 	tmp = ft_itoa_base(nbr, base);
// 	a = malloc((ft_strlen(tmp) + 1) * sizeof(char));
// 	a = tmp;
// 	b = &(base[nbr % base_len]);
// 	b[1] = '\0';
// 	ft_strcat(a, b);
// 	return (a);
// 	// write(1, &(base[nbr % base_len]), 1);
// }

