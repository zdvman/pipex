/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:41:32 by dzuiev            #+#    #+#             */
/*   Updated: 2024/01/16 12:41:32 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/*   Функция `ft_isnumber` проверяет, представляет ли строка `arg` число.     */
/*                                                                            */
/*   Параметры:                                                               */
/*   - `arg`: строка для проверки.                                            */
/*                                                                            */
/*   Работа функции:                                                          */
/*   1. Если `arg` равен NULL или содержит только знак без цифр, функция      */
/*      возвращает 0 (ложь).                                                  */
/*   2. Если строка начинается со знака '+' или '-', функция пропускает этот  */
/*      символ.                                                               */
/*   3. Функция перебирает символы строки `arg`, пока они являются цифрами.   */
/*   4. Если встречается символ, который не является цифрой, или достигнут    */
/*      конец строки (символ `'\0'`), функция завершает проверку.            */
/*   5. Если текущий символ в конце проверки равен `'\0'`,                   */
/*      это означает, что вся строка представляет число,                      */
/*      и функция возвращает 1 (истина).                                      */
/*      В противном случае возвращается 0.                                    */
/*                                                                            */
/*   Возвращаемое значение:                                                   */
/*   - Возвращает 1, если строка `arg` представляет число.                    */
/*   - Возвращает 0, если строка `arg` не представляет число или является     */
/*     пустой строкой или NULL.                                               */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnumber(char *arg)
{
	int	i;

	i = 0;
	if (!arg || (ft_issign(arg[i]) && arg[i + 1] == '\0'))
		return (0);
	if (ft_issign(arg[i]))
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	return (arg[i] == '\0');
}
