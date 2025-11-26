/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:53:41 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/11/26 20:47:50 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include "libft.h"

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

	return (0);
}
