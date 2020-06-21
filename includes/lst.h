#ifndef LST_H
#define LST_H

#include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstaddblank(t_list **alst, size_t content_size);
void			ft_lstaddrevsorted(t_list **root, t_list *node, void *param,
								   int (*cmp)(t_list *, t_list *, void *));
void			ft_lstaddsorted(t_list **root, t_list *node, void *param,
								int (*cmp)(t_list *, t_list *, void *));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstfind(t_list *alst, void *cmp,
							  int (*f)(t_list *, void *));
t_list			*ft_lstget(t_list *lst, int	index);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstnewblank(size_t content_size);
t_list			*ft_lstremove_if(t_list **root, int (*cmp)(void *, void *),
								   void *sec);
size_t			ft_lstsize(t_list *lst);
#endif
