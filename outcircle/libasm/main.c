
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "includes/libasm.h"
#include "includes/libasm_bonus.h"

void test_strcmp(const char *s1, const char *s2)
{
	int t = strcmp(s1, s2);
	int f = ft_strcmp(s1, s2);

	if (t != f)
		printf("strcmp: %d ft_strcmp: %d | with s1: \"%s\" - s2:\"%s\"\n", t, f, s1, s2);
}

void test_strlen(const char *s)
{
	int t = strlen(s);
	int f = ft_strlen(s);

	if (t != f)
		printf("strlen: %d ft_strlen: %d | with s: %s", t, f, s);
}

void test_strcpy(char *dst, const char *src)
{

	char *t = ft_strcpy(dst, src);

	if (t != dst || strcmp(t, src) != 0)
		printf("strcpy with dst: %s - src: %s", dst, src);
}

void test_strdup(const char *src)
{

	char *t = ft_strdup(src);

	if (t == 0)
		printf("Malloc faild ft_strdup\n");
	else
	{
		if (strcmp(t, src) != 0)
			printf("strdup with src: %s output \"%s\"", src, t);
		free(t);
	}
}

void test_write(int fd, const void *buf, size_t count)
{
	ft_write(fd, buf, count);
	int o = errno;
	write(fd, buf, count);
	int t = errno;

	if (o != t)
		printf("errno diff on fd: %d, buf:\"%s\", count: %ld", fd, (char *)buf, count);
}

int cmp(void *a, void *b)
{
	if ((long long)a > (long long)b)
		return 1;
	return 0;
}

int main()
{
	// test_strcmp("", "");
	// test_strcmp("A", "A");
	// test_strcmp("A", "Z");
	// test_strcmp("Z", "A");
	// test_strcmp("z", "a");
	// test_strcmp("a", "z");
	// test_strcmp("A", "z");
	// test_strcmp("z", "A");
	// test_strcmp("Z", "a");
	// test_strcmp("a", "Z");
	// test_strcmp("Hello World", "Hello Mom");
	// test_strcmp("Hello Mom", "Hello World");
	// test_strcmp("Hello", "Hello");
	// test_strcmp("whoeif", "ascno");
	// test_strcmp("whoeif", "Qscno");
	// test_strcmp("Qscno", "whoeif" );

	// test_strlen("");
	// test_strlen("Hello");
	// test_strlen("H");
	// test_strlen("wehjfoiwehfoiwehfowhefowhefuwefwuiefwiuefui");

	// test_strcpy(dst, "Hello World!");
	// test_strcpy(dst, "");
	// test_strcpy(dst, "H");

	// test_strdup("");
	// test_strdup("H");
	// test_strdup("Hello World!");

	// test_write(1, "This is working\n", 17);
	// test_write(1, "This is working\n", -1);
	// test_write(3, "This is working\n", 17);
	// test_write(-1, "This is working\n", 17);


	t_list *list = NULL;
	// ft_list_push_front(&list, (void*)4);
	// ft_list_push_front(&list, (void*)-2);
	// ft_list_push_front(&list, (void*)1);
	// ft_list_push_front(&list, (void*)3);
	// ft_list_push_front(&list, (void*)-1);
	// ft_list_push_front(&list, (void*)5);
	// ft_list_push_front(&list, (void*)-2);
	// ft_list_push_front(&list, (void*)6);
	ft_list_push_front(&list, (void*)-3);
	ft_list_push_front(&list, (void*)0);

		printf("\n%d\n", ft_list_size(list));
	

	ft_list_sort(&list, &cmp);

	while (list) {
		printf("%lld", (long long)list->data);
		list = list->next;
	}
	printf("\n");

	// int i = 0;
	// char dst[20] = "wef";

	// while (++i < 100)
	// {
	// 	test_write(1, "This is working\n", 17);
	// 	test_write(1, "This is working\n", -1);
	// 	test_write(3, "This is working\n", 17);
	// 	test_write(-1, "This is working\n", 17);
	// 	test_strdup("");
	// 	test_strdup("H");
	// 	test_strdup("Hello World!");
	// 	test_strcpy(dst, "Hello World!");
	// 	test_strcpy(dst, "");
	// 	test_strcpy(dst, "H");
	// 	test_strlen("");
	// 	test_strlen("Hello");
	// 	test_strlen("H");
	// 	test_strlen("wehjfoiwehfoiwehfowhefowhefuwefwuiefwiuefui");
	// 	test_strcmp("", "");
	// 	test_strcmp("A", "A");
	// 	test_strcmp("A", "Z");
	// 	test_strcmp("Z", "A");
	// 	test_strcmp("z", "a");
	// 	test_strcmp("a", "z");
	// 	test_strcmp("A", "z");
	// 	test_strcmp("z", "A");
	// 	test_strcmp("Z", "a");
	// 	test_strcmp("a", "Z");
	// 	test_strcmp("Hello World", "Hello Mom");
	// 	test_strcmp("Hello Mom", "Hello World");
	// 	test_strcmp("Hello", "Hello");
	// 	test_strcmp("whoeif", "ascno");
	// 	test_strcmp("whoeif", "Qscno");
	// 	test_strcmp("Qscno", "whoeif" );
	// 	ft_list_size(&list);
	// 	ft_list_sort(&list, &cmp);
	// }
	return 0;
}
