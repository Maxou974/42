
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

void	mandatory();
void	bonus();

int main()
{
	// mandatory();
	bonus();
	return 0;
}

void atoi_base_test(char *src, char* base, int result) {
	int res = ft_atoi_base(src, base);

	if (res != result)
		printf("ERROR: ft_atoi_base src: %s, base: %s, returned: %d, expected: %d\n", \
						src, base, res, result);
}

int cmp(void *data, void* d2) {
	// printf("%d\n", *(char*)data);
	if (*(char*)data > *(char*)d2)
		return 1;
	return 0;
}

char *strcat_list(t_list *list) {
	char *dst = malloc(20);
	memset(dst, 0, 20);

	while (list) {
		strcat(dst, list->data);
		list = list->next;
	}
	return dst;
}

int is_odd(void *d1) {
	if (*(char *)d1 % 2 == 1)
		return 0;
	return 1;
}

int returnzero() {
	return 0;
}

void bonus() {
	atoi_base_test("10", "01", 2);
	atoi_base_test("-10", "01", -2);
	
	atoi_base_test("10", "0123456789", 10);
	atoi_base_test("12e31", "0123456789", 0);
	
	atoi_base_test("ea", "abcdefhijk", 40);
	atoi_base_test("    -ea", "abcdefhijk", -40);
	atoi_base_test(" - ea", "abcdefhijk", 0);
	atoi_base_test("zyjk", "abcdefhijk", 0);

	atoi_base_test("40", "0123456789abcdef", 64);
	atoi_base_test("f", "0123456789abcdef", 15);

	t_list *list = NULL, *tmp;

	ft_list_push_front(&list, ft_strdup("World"));
	ft_list_push_front(&list, ft_strdup("[ ]"));
	ft_list_push_front(&list, ft_strdup("Hello"));

	char *dst;

	dst = strcat_list(list);
	int compare = ft_strcmp(dst, "Hello[ ]World");
	if (compare)
		printf("ERROR push_front\n");
	free(dst);

	tmp = NULL;

	if (ft_list_size(list) != 3)
		printf("ERROR list_size\n");
	if (ft_list_size(tmp) != 0)
		printf("ERROR list_size\n");

	ft_list_sort(&list, &cmp);

	dst = strcat_list(list);
	compare = ft_strcmp(dst, "HelloWorld[ ]");
	if (compare)
		printf("ERROR push_front\n");
	free(dst);


	ft_list_remove_if(&list, "Hello", &ft_strcmp, &free);

	dst = strcat_list(list);
	compare = ft_strcmp(dst, "World[ ]");
	if (compare)
		printf("ERROR push_front\n");
	free(dst);

	ft_list_remove_if(&list, "World", &ft_strcmp, &free);
	ft_list_remove_if(&list, "[ ]", &ft_strcmp, &free);

	dst = strcat_list(list);
	compare = ft_strcmp(dst, "");
	if (compare)
		printf("ERROR push_front\n");
	free(dst);

	if (ft_list_size(list) != 0)
		printf("ERROR list_size\n");

	ft_list_push_front(&list, strdup("1"));
	ft_list_push_front(&list, strdup("2"));
	ft_list_push_front(&list, strdup("3"));
	ft_list_push_front(&list, strdup("4"));
	ft_list_push_front(&list, strdup("5"));
	ft_list_push_front(&list, strdup("6"));

	dst = strcat_list(list);
	if (strcmp(dst, "654321") != 0)
		printf("ERROR list must be: 654321, but is: %s\n", dst);
	free(dst);

	ft_list_remove_if(&list, NULL, &is_odd, &free);

	dst = strcat_list(list);
	if (strcmp(dst, "642") != 0)
		printf("ERROR list must be: 642, but is: %s\n", dst);
	free(dst);

	ft_list_remove_if(&list, NULL, &returnzero, &free); // remove all
}


void	mandatory() {
	char dst[20];
	memset(dst, 0, 20);
	strcpy(dst, "Hello World");

	test_strcmp("", "");
	test_strcmp("A", "A");
	test_strcmp("A", "Z");
	test_strcmp("Z", "A");
	test_strcmp("z", "a");
	test_strcmp("a", "z");
	test_strcmp("A", "z");
	test_strcmp("z", "A");
	test_strcmp("Z", "a");
	test_strcmp("a", "Z");
	test_strcmp("Hello World", "Hello Mom");
	test_strcmp("Hello Mom", "Hello World");
	test_strcmp("Hello", "Hello");
	test_strcmp("whoeif", "ascno");
	test_strcmp("whoeif", "Qscno");
	test_strcmp("Qscno", "whoeif" );
	test_strcmp("Hello World", dst);

	test_strlen(dst);
	test_strlen("");
	test_strlen("Hello");
	test_strlen("H");
	test_strlen("wehjfoiwehfoiwehfowhefowhefuwefwuiefwiuefui");

	test_strcpy(dst, "Hello World");
	test_strcpy(dst, "");
	test_strcpy(dst, "H");

	test_strdup(dst);
	test_strdup("");
	test_strdup("H");
	test_strdup("Hello World!");

	test_write(1, "This is working\n", 17);
	// test_write(1, "This is working\n", -1);
	test_write(3, "This is working\n", 17);
	// test_write(-1, "This is working\n", 17);
}