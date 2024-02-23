#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *node;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int main(void)
{
	t_list *book;
	char booktitle[100];

	printf("What is the book title?\n");
	scanf("%s", booktitle);
	book = ft_lstnew(booktitle);
	printf("The book is %s\n", (char*)book->content);
	return(0);
}
 */
