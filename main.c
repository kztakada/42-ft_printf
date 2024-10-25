/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:27:39 by katakada          #+#    #+#             */
/*   Updated: 2024/10/25 20:57:56 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	num;
	int	*ptr;

	int result_ft, result_printf;
	// 文字の出力
	printf("test 01------------------\n");
	result_ft = ft_printf("%c\n", 'A');
	result_printf = printf("%c\n", 'A');
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("A%cC\n", 'B');
	result_printf = printf("A%cC\n", 'B');
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 文字列の出力
	printf("test 02------------------\n");
	result_ft = ft_printf("%s\n", "Hello, World!");
	result_printf = printf("%s\n", "Hello, World!");
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("Hi! %s, World!\n", "Hello");
	result_printf = printf("Hi! %s, World!\n", "Hello");
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 空文字列の出力
	printf("test 03------------------\n");
	result_ft = ft_printf("%s\n", "");
	result_printf = printf("%s\n", "");
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// NULLポインタの出力
	printf("test 04------------------\n");
	result_ft = ft_printf("%s\n", (char *)NULL);
	result_printf = printf("%s\n", (char *)NULL);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 整数の出力
	printf("test 05------------------\n");
	result_ft = ft_printf("%d\n", 12345);
	result_printf = printf("%d\n", 12345);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("0000%d0000\n", 12345);
	result_printf = printf("0000%d0000\n", 12345);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 負の整数の出力
	printf("test 06------------------\n");
	result_ft = ft_printf("%d\n", -12345);
	result_printf = printf("%d\n", -12345);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("0000%d0000\n", -12345);
	result_printf = printf("0000%d0000\n", -12345);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 最小の整数の出力
	printf("test 07------------------\n");
	result_ft = ft_printf("%d\n", INT_MIN);
	result_printf = printf("%d\n", INT_MIN);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 符号なし整数の出力
	printf("test 08------------------\n");
	result_ft = ft_printf("%u\n", 123456789);
	result_printf = printf("%u\n", 123456789);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("0000%u0000\n", 123456789);
	result_printf = printf("0000%u0000\n", 123456789);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 16進数（小文字）の出力
	printf("test 09------------------\n");
	result_ft = ft_printf("%x\n", 0xabcdef);
	result_printf = printf("%x\n", 0xabcdef);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("0000%x0000\n", 0xabcdef);
	result_printf = printf("0000%x0000\n", 0xabcdef);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 16進数（大文字）の出力
	printf("test 10------------------\n");
	result_ft = ft_printf("%X\n", 0xABCDEF);
	result_printf = printf("%X\n", 0xABCDEF);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("0000%X0000\n", 0xABCDEF);
	result_printf = printf("0000%X0000\n", 0xABCDEF);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// パーセント記号の出力
	printf("test 11------------------\n");
	result_ft = ft_printf("%%\n");
	result_printf = printf("%%\n");
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("0000%%0000\n");
	result_printf = printf("0000%%0000\n");
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// ポインタの出力
	printf("test 12------------------\n");
	num = 42;
	ptr = &num;
	result_ft = ft_printf("%p\n", (void *)ptr);
	result_printf = printf("%p\n", (void *)ptr);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("0000%p0000\n", (void *)ptr);
	result_printf = printf("0000%p0000\n", (void *)ptr);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// nilポインタの出力
	printf("test 13------------------\n");
	ptr = NULL;
	result_ft = ft_printf("%p\n", (void *)ptr);
	result_printf = printf("%p\n", (void *)ptr);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	result_ft = ft_printf("0000%p0000\n", (void *)ptr);
	result_printf = printf("0000%p0000\n", (void *)ptr);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 複数の引数と変換
	printf("test 14------------------\n");
	result_ft = ft_printf(" %c %s %d %u %x %X %%\n", 'B', "test", 42, 100000,
			255, 255);
	result_printf = printf(" %c %s %d %u %x %X %%\n", 'B', "test", 42, 100000,
			255, 255);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// 同じ変換の連続
	printf("test 15------------------\n");
	result_ft = ft_printf(" %d %d %d\n", 1, 2, 3);
	result_printf = printf(" %d %d %d\n", 1, 2, 3);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// エッジケース
	printf("test 16------------------\n");
	result_ft = ft_printf(" %d %d %d\n", 0, INT_MAX, INT_MIN);
	result_printf = printf(" %d %d %d\n", 0, INT_MAX, INT_MIN);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// サインなしケース
	printf("test 17------------------\n");
	result_ft = ft_printf("This will fail\n");
	result_printf = printf("This will fail\n");
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// エラーケース
	printf("test 18------------------\n");
	fclose(stdout);
	result_ft = ft_printf("This will fail\n");
	result_printf = printf("This will fail\n");
	freopen("/dev/tty", "w", stdout);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	printf("test 19------------------\n");
	fclose(stdout);
	result_ft = ft_printf("%s\n", "This will fail");
	result_printf = printf("%s\n", "This will fail");
	freopen("/dev/tty", "w", stdout);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	// イレギュラーケース
	printf("test 20------------------\n");
	result_ft = ft_printf("aaa%weeee\n", 42);
	result_printf = printf("aaa%weeee\n", 42);
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
	printf("test 21------------------\n");
	result_ft = ft_printf("aaa%weees\n", "Hello");
	result_printf = printf("aaa%weees\n", "Hello");
	printf("出力文字数: ft_printf = %d, printf = %d\n\n", result_ft, result_printf);
}

// cc -o test main.c -L. -lftprintf