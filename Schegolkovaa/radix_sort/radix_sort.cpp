struct StringItem {
	const char* str; //указатель на строку
	StringItem* next;
};

//pList - начало списка указателей на строки
//iDigit - разряд, по которому сортирует
//возвращает указатель на первый элемент отсортированной последовательности
StringItem*  radix_sort_msd_for_string(StringItem* pList, unsigned int iDigit)
{
	// количество вариантов значения одного разряда (char)
	const int iRange = 256;

	//массив bucket-ов (под-списков)
	StringItem* front[iRange];
	memset(front, 0, sizeof(front));

	StringItem** ppNextItem[iRange];
	for (int i = 0; i < iRange; i++)
		ppNextItem[i] = &front[i];

	//разбиваем список на bucket-ты, в зависимости от значения разряда
	while (pList)
	{
		StringItem* temp = pList;
		pList = pList->next;

		temp->next = NULL; //отключаем от списка

		unsigned char c = (unsigned char)temp->str[iDigit];
		*ppNextItem[c] = temp;
		ppNextItem[c] = &temp->next;
	}

	//строим выходной список
	StringItem* pResult = NULL;
	StringItem** ppNext = &pResult;

	//нулевой bucket возвращаем весь - он уже отсортирован
	*ppNext = front[0];
	while (*ppNext)
		ppNext = &((*ppNext)->next);

	for (int i = 1; i < iRange; i++)
	{
		//пустые - пропускаем
		if (!front[i])
			continue;

		if (front[i]->next == NULL)// с одним элементом - сразу добавляем
			*ppNext = front[i];
		else    // остальные - на сортировку по следующему разряду
			*ppNext = radix_sort_msd_for_string(front[i], iDigit + 1);

		while (*ppNext)
			ppNext = &((*ppNext)->next);
	}

	return pResult;
}