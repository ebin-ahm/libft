/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:53:41 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/11/29 21:43:47 by ebin-ahm         ###   ########.fr       */
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
	return (0);
}
