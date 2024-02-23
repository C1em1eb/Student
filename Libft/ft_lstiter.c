#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *nodetoapplyfunctionto;

	nodetoapplyfunctionto = lst;
	while (nodetoapplyfunctionto)
	{
		f(nodetoapplyfunctionto->content);
		nodetoapplyfunctionto = nodetoapplyfunctionto->next;
	}
}
