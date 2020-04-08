// radix_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

template <class T>
void my_radix_sort(vector<T>& v)
{
	std::vector<T> buckets[256];
	int sizes[256];

	for (int i = 0;i < 256;i++)
		sizes[i] = 0;

	size_t v_size = v.size();

	int mask[] = { 255,65280,16711680,-16777216 };

	for (int r = 0; r < 4; r++)
	{
		//const int mask = (0xff) << (8 * r);
		int cmask = mask[r];

		unsigned char b;
		for (size_t i = 0; i < v_size; ++i)
		{
			b = (v[i] & cmask) >> (8 * r);
			sizes[b]++;
		}
	}

	for (int i = 0;i < 256;i++)
		buckets[i].reserve(sizes[i]);

	for (int r = 0; r < 4; r++)
	{
		int cmask = mask[r];

		T val;
		unsigned char b;
		for (size_t i = 0; i < v_size; ++i)
		{
			b = (v[i] & cmask) >> (8 * r);
			buckets[b].push_back(v[i]);
		}

		int k = 0;
		for (int j = 0;j < 256;j++)
		{
			//if (buckets[j].empty()) continue;
			size_t b_size = buckets[j].size();
			for(size_t l = 0;l < b_size;l++)
				v[k++] = buckets[j][l];
			buckets[j].clear();
		}
	}
}
