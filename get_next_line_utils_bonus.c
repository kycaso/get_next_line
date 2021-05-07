#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*r;
	int		j;

	i = 0;
	r = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r)
		return (NULL);
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;
	int		l;

	i = 0;
	l = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * l + 1);
	if (!s2)
		return (NULL);
	while (i < l)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	char	l;
	int		i;
	int		p;

	l = c;
	i = 0;
	p = ft_strlen(s);
	while (i <= p)
	{
		if (s[i] == l)
			return ((char *)&s[i + 1]);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
