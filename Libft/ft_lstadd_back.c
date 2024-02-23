#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *oldlast;
	if (*lst == NULL)
		*lst = new;
	else
	{
		oldlast = ft_lstlast(*lst);
		oldlast->next = new;
	}
}
