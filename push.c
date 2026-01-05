

static void ft_push (t_list **lst1, t_list **lst2)
{
    t_list *node;

    node = *lst1;
    ft_lstadd_front (lst2, node);
    *lst1 = (*lst1)->next;
}

void pa(t_list **a, t_list **b)
{
    ft_push (a, b);
    write (1, "pa\n", 1);
}

void pb(t_list **a, t_list **b)
{
    ft_push (b, a);
    write (1, "pb\n", 1);
}
