## 仕様

flags->precision == -1  
precisionの指定値に不正な文字が入っている場合（.の後に、＊と0〜9とフォーマットタイプ以外の文字が入っている場合）  
flags->precision == -2  
precisionの指定値が0の場合（.の後の文字列が0もしくは000...文字の場合＝atoiの結果が0になる）  
flags->precision == -3  
charと%以外のケースで.の後にフォーマットタイプが入っている場合

## 注意事項
```c
int	ft_vdprintf(int fd, const char *format, va_list *args)

	if (!format)
		return (-1);

	上記のバリデーションブロックを削除しているため、formatは必ずnull出ないことが求められる
```
