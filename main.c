/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:53:41 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/03 23:56:05 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include "libft.h"

static char	strmapi_test_func(unsigned int index, char c)
{
	/* Even index -> uppercase letters
	   Odd index  -> lowercase letters
	   Non-letters stay the same
	*/
	if ((index % 2) == 0 && c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	if ((index % 2) == 1 && c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

static void	striteri_test_func(unsigned int index, char *c)
{
	if ((index % 2) == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - ('a' - 'A');
	else if ((index % 2) == 1 && *c >= 'A' && *c <= 'Z')
		*c = *c + ('a' - 'A');
}

int	main(void)
{
	char	str[10] = "hello";

	printf("isalpha('A') = %d\n", ft_isalpha('A'));
	printf("isdigit('7') = %d\n", ft_isdigit('7'));
	printf("isalnum('$') = %d\n", ft_isalnum('$'));

	printf("strlen(\"hello\") = %zu\n", ft_strlen("hello"));

	ft_memset(str, 'X', 3);
	printf("after memset: %s\n", str);

	ft_bzero(str + 3, 2); // zero out 'l' and 'o'
	printf("after bzero:  [%s]\n", str); // will show some zeros

	/* ================== memcpy tests ================== */
	char	src[10] = "12345";
	char	dst[10] = "abcdef";

	printf("\n-- memcpy tests --\n");
	printf("before: src = \"%s\", dst = \"%s\"\n", src, dst);

	// copy only 3 bytes
	ft_memcpy(dst, src, 3);
	printf("after ft_memcpy(dst, src, 3): dst = \"%s\" (expect \"123def\")\n", dst);

	// copy 6 bytes (5 chars + '\0') so dst becomes full copy of src
	ft_memcpy(dst, src, 6);
	printf("after ft_memcpy(dst, src, 6): dst = \"%s\" (expect \"12345\")\n", dst);
	/* ================================================== */

	char buf[20] = "123456789";
	ft_memmove(buf + 2, buf, 5);
	printf("%s\n", buf);  // expect: 121234589

	/* ================== strlcpy ================== */
	char src1[] = "abcdef";
	char dst1[10];
	char dst2[5];
	size_t n;

	printf("\n-- strlcpy tests --\n");
	n = ft_strlcpy(dst1, src1, sizeof(dst1));
	printf("dst1=\"%s\", n=%zu (expect dst1=\"abcdef\", n=6)\n", dst1, n);

	n = ft_strlcpy(dst2, src1, sizeof(dst2));
	printf("dst2=\"%s\", n=%zu (expect dst2=\"abcd\", n=6)\n", dst2, n);
	/* ==================+++++++++================== */

	/* ================== strlcat ================== */
	char buf2[10] = "hello";
	size_t n2 = ft_strlcat(buf2, " world", sizeof(buf2));
	printf("\n-- strlcat tests --\n");
	printf("buf2 = \"%s\", n2 = %zu (expect truncated, n2 = 11)\n", buf2, n2);
	/* ==================+++++++++================== */

	/* ================== toupper & tolower ================== */
	printf("\n-- toupper test --\n");
	printf("ft_toupper('a') = %c (expect 'A')\n", ft_toupper('a'));
	printf("\n-- tolower test --\n");
	printf("ft_tolower('A') = %c (expect 'a')\n", ft_toupper('A'));
	/* ==================+++++++++================== */

	/* ================== strchr ================== */
	printf("\n-- strchr test --\n");
	char a[] = "hello";
	printf("%s\n", ft_strchr(a, 'l'));   // "llo"
	printf("%p\n", (void *)ft_strchr(a, 'x')); // (nil)

	/* ==================+++++++++================== */

	/* ================== strrchr ================== */
	printf("\n-- strrchr test --\n");
	char b[] = "hello world";
	printf("%s\n", ft_strrchr(b, 'l'));   // "ld"
	printf("%s\n", ft_strrchr(b, 'o'));   // "orld"

	/* ==================+++++++++================== */

	/* ================== strncmp ================== */
	printf("\n-- strncmp test --\n");
	printf("%d\n", ft_strncmp("hello", "hello", 5));     // 0
	printf("%d\n", ft_strncmp("hello", "helxo", 3));     // 0  (first 3 letters same)
	printf("%d\n", ft_strncmp("hello", "helxo", 4));     // 'l' - 'x' = negative
	printf("%d\n", ft_strncmp("abc", "abd", 3));         // negative
	printf("%d\n", ft_strncmp("abcd", "abce", 10));      // negative
	printf("%d\n", ft_strncmp("abc", "abc", 0));         // 0 (n=0)
	printf("%d\n", ft_strncmp("a", "", 1));              // positive ('a' - '\0')
	printf("%d\n", ft_strncmp("", "a", 1));              // negative ('\0' - 'a')
	printf("%d\n", ft_strncmp("abcdef", "abc\0xx", 6));  // 'd' - '\0' = positive
	/* ==================+++++++++================== */

		/* ================== memchr ================== */
	printf("\n-- memchr test --\n");
	char c[] = "hello world";
	printf("%s\n", (char *)ft_memchr(c, 'o', 11));  // "o world"
	printf("%s\n", (char *)ft_memchr(c, 'w', 11));  // "world"
	printf("%s\n", (char *)ft_memchr(c, 'l', 11));  // "llo world"
	printf("%p\n", ft_memchr(c, 'z', 11));          // NULL
	/* ==================+++++++++================== */

	/* ================== memcmp ================== */
	printf("\n-- memcmp test --\n");
	unsigned char a1[] = {1, 2, 3, 4, 5};
	unsigned char a2[] = {1, 2, 3, 4, 5};
	unsigned char a3[] = {1, 2, 4, 4, 5};

	printf("memcmp(a1, a2, 5) = %d (expect 0)\n",
	ft_memcmp(a1, a2, 5));

	printf("memcmp(a1, a3, 5) = %d (expect < 0)\n",
	ft_memcmp(a1, a3, 5)); // first diff: 3 < 4

	printf("memcmp(a3, a1, 5) = %d (expect > 0)\n",
	ft_memcmp(a3, a1, 5)); // first diff: 4 > 3

	printf("memcmp(a1, a3, 0) = %d (expect 0)\n",
	ft_memcmp(a1, a3, 0));
	/* ==================+++++++++================== */

	/* ================== memcmp ================== */
	printf("\n-- strnstr test --\n");
	char d[] = "hello world";
	char *d1;

	d1 = ft_strnstr(d, "world", 11);
	printf("1: %s\n", d1);  // expect "world"

	d1 = ft_strnstr(d, "world", 5);
	printf("2: %p\n", (void *)d1); // expect NULL

	d1 = ft_strnstr(d, "", 5);
	printf("3: %s\n", d1);  // expect "hello world"

	/* ==================+++++++++================== */

	/* ================== atoi ================== */
	printf("\n-- atoi test --\n");
	printf("ft_atoi(\"42\") = %d\n", ft_atoi("42"));                 // 42
	printf("ft_atoi(\"   -123\") = %d\n", ft_atoi("   -123"));       // -123
	printf("ft_atoi(\"\\t\\n+56abc\") = %d\n", ft_atoi("\t\n+56abc"));// 56
	printf("ft_atoi(\"abc123\") = %d\n", ft_atoi("abc123"));         // 0
	printf("ft_atoi(\"0\") = %d\n", ft_atoi("0"));                   // 0
	/* ==================+++++++++================== */

	/* ================== calloc ================== */
	printf("\n-- calloc test --\n");
	size_t	count;
	size_t	index;
	int		*arr;

	count = 5;
	arr = (int *)ft_calloc(count, sizeof(int));
	if (!arr)
	{
		printf("ft_calloc failed (returned NULL)\n");
		return (1);
	}
	printf("ft_calloc(%zu, sizeof(int)) allocated array:\n", count);
	index = 0;
	while (index < count)
	{
		printf("  arr[%zu] = %d\n", index, arr[index]);
		index++;
	}
	free(arr);
	/* ==================+++++++++================== */

	/* ================== strdup ================== */
	printf("\n-- strdup test --\n");
	char *orig = "hello world";
	char *copy;

	copy = ft_strdup(orig);
	if (!copy)
	{
		printf("ft_strdup failed\n");
		return (1);
	}
	printf("orig = \"%s\"\n", orig);
	printf("copy = \"%s\"\n", copy);
	copy[0] = 'H';
	printf("after modifying copy:\n");
	printf("orig = \"%s\"  (expect \"hello world\")\n", orig);
	printf("copy = \"%s\"  (expect \"Hello world\")\n", copy);
	free(copy);
	/* ==================+++++++++================== */

	/* ================== substr ================== */
	printf("\n-- substr test --\n");
	char *s = "hello world";
	char *sub;

	/* normal case */
	sub = ft_substr(s, 0, 5);
	printf("ft_substr(\"%s\", 0, 5) -> \"%s\" (expect \"hello\")\n", s, sub);
	free(sub);

	/* middle of string */
	sub = ft_substr(s, 6, 5);
	printf("ft_substr(\"%s\", 6, 5) -> \"%s\" (expect \"world\")\n", s, sub);
	free(sub);

	/* len bigger than remaining */
	sub = ft_substr(s, 3, 50);
	printf("ft_substr(\"%s\", 3, 50) -> \"%s\" (expect \"lo world\")\n", s, sub);
	free(sub);

	/* start past end */
	sub = ft_substr(s, 20, 5);
	printf("ft_substr(\"%s\", 20, 5) -> \"%s\" (expect \"\")\n", s, sub);
	free(sub);

	/* ==================+++++++++================== */

	/* ================== strjoin ================== */
	printf("\n-- strjoin test --\n");

	char	*s1;
	char	*s2;
	char	*joined;
	
	s1 = "hello";
	s2 = "world";
	joined = ft_strjoin(s1, s2);
	if (!joined)
	{
		printf("ft_strjoin failed (NULL)\n");
		return (1);
	}
	printf("ft_strjoin(\"%s\", \"%s\") -> \"%s\" (expect \"helloworld\")\n",
		s1, s2, joined);
	free(joined);

	// 2) With space: "hello " + "world"
	s1 = "hello ";
	s2 = "world";
	joined = ft_strjoin(s1, s2);
	printf("ft_strjoin(\"%s\", \"%s\") -> \"%s\" (expect \"hello world\")\n",
		s1, s2, joined);
	free(joined);

	// 3) Empty s1: "" + "abc"
	s1 = "";
	s2 = "abc";
	joined = ft_strjoin(s1, s2);
	printf("ft_strjoin(\"%s\", \"%s\") -> \"%s\" (expect \"abc\")\n",
		s1, s2, joined);
	free(joined);

	// 4) Empty s2: "abc" + ""
	s1 = "abc";
	s2 = "";
	joined = ft_strjoin(s1, s2);
	printf("ft_strjoin(\"%s\", \"%s\") -> \"%s\" (expect \"abc\")\n",
		s1, s2, joined);
	free(joined);

	/* ==================+++++++++================== */

	/* ================== strtrim ================== */
	printf("\n-- strtrim test --\n");

	char *t;

	t = ft_strtrim("  hello  ", " ");
	printf("\"  hello  \" trimmed by \" \" -> \"%s\" (expect \"hello\")\n", t);
	free(t);

	t = ft_strtrim("xxxyhelloxyx", "xy");
	printf("\"xxxyhelloxyx\" trimmed by \"xy\" -> \"%s\" (expect \"hello\")\n", t);
	free(t);

	t = ft_strtrim("abcabc", "abc");
	printf("\"abcabc\" trimmed by \"abc\" -> \"%s\" (expect \"\")\n", t);
	free(t);

	t = ft_strtrim("hello", "xyz");
	printf("\"hello\" trimmed by \"xyz\" -> \"%s\" (expect \"hello\")\n", t);
	free(t);
	
	/* ==================+++++++++================== */


	/* ==================== split ==================== */
	char    **result_split;
	size_t  index_split;

	printf("\n-- ft_split tests --\n");

	/* Test 1 */
	printf("\nTest 1: \"hello world  42  piscine\", sep = ' '\n");
	result_split = ft_split("hello world  42  piscine", ' ');
	if (!result_split)
    	return (1);
	index_split = 0;
	while (result_split[index_split] != NULL)
	{
    	printf("word[%zu] = \"%s\"\n", index_split, result_split[index_split]);
    	free(result_split[index_split]);
    	index_split++;
	}
	free(result_split);

	/* Test 2 */
	printf("\nTest 2: \",,,abc,,def,,\", sep = ','\n");
	result_split = ft_split(",,,abc,,def,,", ',');
	if (!result_split)
    	return (1);
	index_split = 0;
	while (result_split[index_split] != NULL)
	{
    	printf("word[%zu] = \"%s\"\n", index_split, result_split[index_split]);
    	free(result_split[index_split]);
    	index_split++;
	}
	free(result_split);

	/* Test 3 */
	printf("\nTest 3: \";;;;\", sep = ';'\n");
	result_split = ft_split(";;;;", ';');
	if (!result_split)
    	return (1);
	index_split = 0;
	while (result_split[index_split] != NULL)
	{
    	printf("word[%zu] = \"%s\"\n", index_split, result_split[index_split]);
    	free(result_split[index_split]);
    	index_split++;
	}
	free(result_split);

	/* ==================+++++++++================== */

	/* ==================== itoa ================ */
	printf("\n-- ft_itoa tests --\n");

	int		values[] = {0, 42, -42, 123456, -123456, -2147483648};
	size_t	index_itoa = 0;
	char	*str_num;

	while (index_itoa < 6)
	{
	str_num = ft_itoa(values[index_itoa]);
	if (!str_num)
		return (1);
	printf("ft_itoa(%d) = \"%s\"\n", values[index_itoa], str_num);
	free(str_num);
	index_itoa++;
	}
	/* ==================+++++++++================== */

	/* ================= strmapi ================= */
	printf("\n-- ft_strmapi tests --\n");

	const char	*inputs[] = {
		"hello world",
		"42Network",
		"",
		"AbCdEfG",
		NULL
	};
	size_t		index_strmapi = 0;
	char		*result_strmapi;

	while (inputs[index_strmapi] != NULL)
	{
		result_strmapi = ft_strmapi(inputs[index_strmapi], strmapi_test_func);
		if (!result_strmapi)
			return (1);
		printf("input [%zu] : \"%s\"\n", index_strmapi, inputs[index_strmapi]);
		printf("output[%zu] : \"%s\"\n\n", index_strmapi, result_strmapi);
		free(result_strmapi);
		index_strmapi++;
	}
	/* ========================================== */

	/* ================= striteri ================= */
	printf("\n-- ft_striteri tests --\n");

	char	str1[] = "hello world";
	char	str2[] = "42Network";
	char	str3[] = "";
	char	str4[] = "AbCdEfG";
	char	*strings[] = {str1, str2, str3, str4, NULL};

	size_t	index_striteri = 0;

	while (strings[index_striteri] != NULL)
	{
		printf("\nBefore[%zu]: \"%s\"\n", index_striteri, strings[index_striteri]);
		ft_striteri(strings[index_striteri], striteri_test_func);
		printf("After [%zu]: \"%s\"\n", index_striteri, strings[index_striteri]);
		index_striteri++;
	}
	/* ========================================== */

	/* ================= putchar ================= */
	printf("\n-- ft_putchar_fd tests --\n");

	ft_putchar_fd('A', 1);  // stdout
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('B', 1);
	ft_putchar_fd('\n', 1);

	ft_putchar_fd('E', 2);  // stderr
	ft_putchar_fd('r', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('o', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('\n', 2);
	/* ========================================== */

	/* ================= putstr ================= */
	printf("\n-- ft_putstr_fd tests --\n");

	ft_putstr_fd("Hello, stdout!\n", 1);
	ft_putstr_fd("This goes to stderr.\n", 2);

	char	*null_str = NULL;
	ft_putstr_fd(null_str, 1); // should do nothing and not crash
	/* =============================================== */

	/* ================= putendl ================= */
	printf("\n-- ft_putendl_fd tests --\n");

	ft_putendl_fd("Hello, world!", 1);
	ft_putendl_fd("This line goes to stdout", 1);
	ft_putendl_fd("This line goes to stderr", 2);

	char	*null_line = NULL;
	ft_putendl_fd(null_line, 1); // should do nothing, no crash
	/* ================================================ */

	/* ================= putnbr ================ */

	int		values_putnbr[] = {0, 42, -42, 123456, -123456, -2147483648};
	size_t	index_putnbr = 0;

	while (index_putnbr < 6)
	{
		printf("n = %d -> \"", values_putnbr[index_putnbr]);
		ft_putnbr_fd(values_putnbr[index_putnbr], 1);
		printf("\"\n");
		index_putnbr++;
	}
	/* =============================================== */

	/* =============================================================*/
	
	/* ============ B B B   OOO   N   N   U   U  SSSS  ============ */
	/* ============ B   B   OOO   N   N   U   U  SSSS  ============ */
	/* ============ B   B  O   O  NN  N   U   U  S     ============ */
	/* ============ BBBB   O   O  N N N   U   U  SSS   ============ */
	/* ============ B   B  O   O  N  NN   U   U     S  ============ */
	/* ============ BBBB    OOO   N   N    UUU  SSSS  ============ */

	/* ================= lstnew ==================================== */
	printf("\n-- lstnew --\n");

	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew(ft_strdup("hello"));
	node2 = ft_lstnew(ft_strdup("42"));
	node3 = ft_lstnew(ft_strdup("libft"));

	if (!node1 || !node2 || !node3)
	{
		printf("ft_lstnew returned NULL (malloc failed)\n");
		return (1);
	}

	printf("node1 content: \"%s\", next: %p\n",
		(char *)node1->content, (void *)node1->next);
	printf("node2 content: \"%s\", next: %p\n",
		(char *)node2->content, (void *)node2->next);
	printf("node3 content: \"%s\", next: %p\n",
		(char *)node3->content, (void *)node3->next);

	/* free content + nodes */
	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);
	/* =============================================== */

	/* ================= lstadd_front ================ */
	printf("\n-- lstadd_front --\n");

	t_list	*node4;
	t_list	*node5;
	t_list	*node6;
	t_list	*head;
	t_list	*current;
	t_list	*next;
	size_t	index1;
	
	head = NULL;
	node4 = ft_lstnew(ft_strdup("your"));
	node5 = ft_lstnew(ft_strdup("cheese"));
	node6 = ft_lstnew(ft_strdup("pie"));

	if (!node4 || !node5 || !node6)
	{
		printf("ft_lstnew returned NULL (malloc failed)\n");
		return (1);
	}
	ft_lstadd_front(&head, node4);
	ft_lstadd_front(&head, node5);
	ft_lstadd_front(&head, node6);

	current = head;
	index1 = 0;
	while (current)
	{
		printf("node %zu: \"%s\"\n", index1, (char *)current->content);
		current = current->next;
		index1++;
	}

	current = head;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	/* =============================================== */

	/* ================== lstlast ==================== */
	printf("\n-- ft_lstlast tests --\n");

	t_list	*list3;
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	t_list	*last_node;

	list3 = NULL;
	last_node = ft_lstlast(list3);
	printf("Empty list: last = %p (expected NULL)\n", (void *)last_node);

	l1 = ft_lstnew(ft_strdup("first"));
	l2 = ft_lstnew(ft_strdup("middle"));
	l3 = ft_lstnew(ft_strdup("last"));

	if (!l1 || !l2 || !l3)
	{
		printf("ft_lstnew returned NULL (malloc failed)\n");
		return (1);
	}

	list3 = l1;
	l1->next = l2;
	l2->next = l3;

	last_node = ft_lstlast(list3);
	if (last_node)
		printf("Last node content: \"%s\" (expected \"last\")\n",
			(char *)last_node->content);
	else
		printf("Last node is NULL (unexpected!)\n");

	t_list	*cur1 = list3;
	t_list	*next3;

	while (cur1)
	{
		next3 = cur1->next;
		free(cur1->content);
		free(cur1);
		cur1 = next3;
	}
	/* ============================================= */

	/* ================= lstadd_back ================== */
	printf("\n-- ft_lstadd_back tests --\n");

	t_list	*head4;
	t_list	*b1;
	t_list	*b2;
	t_list	*b3;
	t_list	*cur2;
	t_list	*next4;
	size_t	index_back;

	head4 = NULL;

	b1 = ft_lstnew(ft_strdup("first"));
	b2 = ft_lstnew(ft_strdup("second"));
	b3 = ft_lstnew(ft_strdup("third"));

	if (!b1 || !b2 || !b3)
	{
		printf("ft_lstnew returned NULL (malloc failed)\n");
		return (1);
	}

	ft_lstadd_back(&head4, b1); 
	ft_lstadd_back(&head4, b2); 
	ft_lstadd_back(&head4, b3); 


	cur2 = head4;
	index_back = 0;
	while (cur2)
	{
		printf("node %zu: \"%s\"\n", index_back, (char *)cur2->content);
		cur2 = cur2->next;
		index_back++;
	}

	cur2 = head4;
	while (cur2)
	{
		next4 = cur2->next;
		free(cur2->content);
		free(cur2);
		cur2 = next4;
	}
	/* =============================================== */

	/* ================= lstdelone ==================== */

	printf("\n-- ft_lstdelone tests --\n");

	t_list	*head_lstdelone;
	t_list	*node_first;
	t_list	*node_middle;
	t_list	*node_last;
	t_list	*current_lstdelone;
	t_list	*next_lstdelone;
	t_list	*after_middle;
	size_t	index_lstdelone;

	node_first = ft_lstnew(ft_strdup("first"));
	node_middle = ft_lstnew(ft_strdup("middle"));
	node_last = ft_lstnew(ft_strdup("last"));
	if (!node_first || !node_middle || !node_last)
	{
		printf("ft_lstnew returned NULL (malloc failed)\n");
		return (1);
	}
	head_lstdelone = node_first;
	node_first->next = node_middle;
	node_middle->next = node_last;

	printf("Before delete:\n");
	current_lstdelone = head_lstdelone;
	index_lstdelone = 0;
	while (current_lstdelone)
	{
		printf("  node %zu: \"%s\"\n",
			index_lstdelone, (char *)current_lstdelone->content);
		current_lstdelone = current_lstdelone->next;
		index_lstdelone++;
	}

	printf("\nDeleting middle node (\"middle\")...\n");
	after_middle = node_middle->next;          
	ft_lstdelone(node_middle, free);           
	node_first->next = after_middle;

	printf("After delete:\n");
	current_lstdelone = head_lstdelone;
	index_lstdelone = 0;
	while (current_lstdelone)
	{
		printf("  node %zu: \"%s\"\n",
			index_lstdelone, (char *)current_lstdelone->content);
		current_lstdelone = current_lstdelone->next;
		index_lstdelone++;
	}


	current_lstdelone = head_lstdelone;
	while (current_lstdelone)
	{
		next_lstdelone = current_lstdelone->next;
		free(current_lstdelone->content);
		free(current_lstdelone);
		current_lstdelone = next_lstdelone;
	}

	/* =============================================== */

	/* ================= lstclear ===================== */
	printf("\n-- ft_lstclear tests --\n");

	t_list	*head_lstclear;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;

	node_a = ft_lstnew(ft_strdup("alpha"));
	node_b = ft_lstnew(ft_strdup("beta"));
	node_c = ft_lstnew(ft_strdup("gamma"));
	if (!node_a || !node_b || !node_c)
	{
		printf("ft_lstnew returned NULL (malloc failed)\n");
		return (1);
	}
	head_lstclear = node_a;
	node_a->next = node_b;
	node_b->next = node_c;

	printf("Before clear:\n");
	t_list	*current_lstclear = head_lstclear;
	size_t	index_lstclear = 0;
	while (current_lstclear)
	{
		printf("  node %zu: \"%s\"\n",
			index_lstclear, (char *)current_lstclear->content);
		current_lstclear = current_lstclear->next;
		index_lstclear++;
	}

	printf("\nClearing list with ft_lstclear...\n");
	ft_lstclear(&head_lstclear, free);

	printf("After clear: head_lstclear = %p (expected NULL)\n",
		(void *)head_lstclear);

	printf("List contents after clear:\n");
	current_lstclear = head_lstclear;
	index_lstclear = 0;
	while (current_lstclear)
	{
		printf("  node %zu: \"%s\"\n",
			index_lstclear, (char *)current_lstclear->content);
		current_lstclear = current_lstclear->next;
		index_lstclear++;
	}
	/* =============================================== */

	return (0);

	}
