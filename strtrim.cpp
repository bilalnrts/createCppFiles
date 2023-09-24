#include "create.hpp"

static int	ft_check(char c, char const *set )
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		s;
	int		len;

	i = 0;
	s = 0;
	if (!s1)
		return (0);
	len = strlen(s1);
	while (s < len && ft_check(s1[s], set))
		s++;
	while (len > s && ft_check(s1[len - 1], set))
		len--;
	str = (char *)malloc(len - s + 1);
	if (!str)
		return (0);
	while (i < len - s)
	{
		str[i] = s1[s + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
