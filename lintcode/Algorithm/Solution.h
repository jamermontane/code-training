#pragma once
#include <vector>
#include <ctime>
#include <unordered_map >

#define  DEBUG

using namespace std;

class CSolution
{
public:
	CSolution();
	~CSolution();

public:
	/**
	* @param array: An array.
	* @return: An integer.
	*/
	struct Elem
	{
		int content;
		int Cnt;
	};

	clock_t startTime, endTime;
	double SearchCounter=0;
	double SortCounter=0;

	Elem* _elemTemp;
	Elem _elems[100000];// = new Elem[array.size()];
	Elem _maxElm;
	vector<Elem> _vecElems;
	int NewFlag;

	int findNumber(vector<int> &array) {
		// Write your code here.
		if (array.size()>100000) return -1;
		/*vector<Elem> elems;*/
		
		_elemTemp = new Elem[100000];
		
		SearchCounter = 0;
		SortCounter = 0;
		NewFlag = 0;
		for (int i = 0;i<array.size();i++)
		{
			if (array[i]<0 || array[i]>2147483647) return -1;
			if (i == 0)
			{
				Elem elm;
				elm.content = array[i];
				elm.Cnt = 1;
				_elems[NewFlag] = elm;
				NewFlag++;
				_maxElm = elm;
				continue;
			}
// 			bool isFind = false;
// 			for (int j = 0;j<NewFlag;j++)
// 			{
// 				if (array[i] == elems[j].content)
// 				{
// 					elems[j].Cnt++;
// 					isFind = true;
// 
// 					if (elems[j].Cnt > maxElm.Cnt)
// 					{
// 						maxElm = elems[j];
// 					}
// 					else if (elems[j].Cnt == maxElm.Cnt)
// 					{
// 						if (elems[j].content <= maxElm.content)
// 						{
// 							maxElm = elems[j];
// 						}
// 					}
// 
// 					break;
// 				}
// 			}

#ifdef DEBUG
			int IsFind = -1;
			if (array[i] == 17)
				IsFind = -1;
			if (array[i] == 41)
				IsFind = -1;
			startTime = clock();
#endif // DEBUG

		
			/*IsFind = binarySearch(_elems, NewFlag, array[i]);*/
			IsFind = binarySearch(_elems, NewFlag, array[i]);
			

#ifdef DEBUG
			endTime = clock();
			SearchCounter += (double)(endTime - startTime) / CLOCKS_PER_SEC;
#endif // DEBUG




			if (IsFind == -1)
			{
				Elem elm;
				elm.content = array[i];
				elm.Cnt = 1;
				/*elems.push_back(elm);*/
				//_elems[NewFlag] = elm;
				if(NewFlag>1)
				{
#ifdef DEBUG
					startTime = clock();
#endif // DEBUG

					
					binarySort(_elems, NewFlag, elm);
#ifdef DEBUG
					endTime = clock();
					SortCounter += (double)(endTime - startTime) / CLOCKS_PER_SEC;
#endif // DEBUG

					
				}
				else
				{
					if (elm.content < _elems[0].content)
					{
						Elem t = _elems[0];
						_elems[0] = elm;
						_elems[NewFlag] = t;
					}
				}
				NewFlag++;
// 				if (NewFlag > 1)
// 					mergeSort(elems, 0, NewFlag - 1);
// 				
				

				if (elm.Cnt > _maxElm.Cnt)
				{
					_maxElm = elm;
				}
				else if (elm.Cnt == _maxElm.Cnt)
				{
					if (elm.content <= _maxElm.content)
					{
						_maxElm = elm;
					}
				}
			}
			else
			{
				_elems[IsFind].Cnt++;

				if (_elems[IsFind].Cnt > _maxElm.Cnt)
				{
					_maxElm = _elems[IsFind];
				}
				else if (_elems[IsFind].Cnt == _maxElm.Cnt)
				{
					if (_elems[IsFind].content <= _maxElm.content)
					{
						_maxElm = _elems[IsFind];
					}
				}
			}
		}
		delete[] _elemTemp;
		return _maxElm.content;
	}

	int findNumberFinal(vector<int> &array) {
		unordered_map<int, int> counter;
		int length = array.size();
		int answer = 0;
		int maxNumber = 0;

		for (int i = 0; i < length; i++) {
			counter[array[i]] = counter[array[i]] + 1;
			if (counter[array[i]] > maxNumber) {
				maxNumber = counter[array[i]];
				answer = array[i];
			}
			else if (counter[array[i]] == maxNumber && array[i] < answer) {
				answer = array[i];
			}
		}

		return answer;
	}

	int HalffindNumber(vector<int> &array) 
	{
		// Write your code here.
		if (array.size() > 100000) return -1;
		/*vector<Elem> elems;*/

		_elemTemp = new Elem[100000];
		
		NewFlag = 0;
		if (array.size() > 1)
		{
			for (int i = 0, j = array.size() - 1;j > i;i++, j--)
			{
				EngageElem(array, i);
				EngageElem(array, j);
			}
		}
		else
		{
			_maxElm.Cnt = 1;
			_maxElm.content = array[0];
		}
		

		
		delete[] _elemTemp;
		return _maxElm.content;
	}

	int FindNumberInVector(vector<int> &array)
	{
		// Write your code here.
		if (array.size() > 100000) return -1;
		/*vector<Elem> elems;*/

		_vecElems.clear();

		NewFlag = 0;
		if (array.size() > 1)
		{
			for (int i = 0, j = array.size() - 1;j > i;i++, j--)
			{
				EngageElemInVector(array, i);
				EngageElemInVector(array, j);
			}
		}
		else
		{
			_maxElm.Cnt = 1;
			_maxElm.content = array[0];
		}



		return _maxElm.content;
	}

	void EngageElem(vector<int> &array, int index)
	{
		if (array[index] < 0 || array[index]>2147483647) return;
		if (index == 0)
		{
			Elem elm;
			elm.content = array[index];
			elm.Cnt = 1;
			_elems[NewFlag] = elm;
			NewFlag++;
			_maxElm = elm;
			return;
		}
		// 			
		Elem elm;
		elm.content = array[index];
		elm.Cnt = 1;
		//_elems[NewFlag] = elm;
		/*elems.push_back(elm);*/
		int IsFind = -1;
		if (NewFlag > 1)
		{
			startTime = clock();
			IsFind = binaryGet(_elems, NewFlag, elm);
			endTime = clock();

			if (IsFind != -1)
			{
				_elems[IsFind].Cnt++;

				if (_elems[IsFind].Cnt > _maxElm.Cnt)
				{
					_maxElm = _elems[IsFind];
				}
				else if (_elems[IsFind].Cnt == _maxElm.Cnt)
				{
					if (_elems[IsFind].content <= _maxElm.content)
					{
						_maxElm = _elems[IsFind];
					}
				}
			}
			else
			{
				NewFlag++;
			}
			SortCounter += (double)(endTime - startTime) / CLOCKS_PER_SEC;
		}
		else
		{
			if (elm.content < _elems[0].content)
			{
				Elem t = _elems[0];
				_elems[0] = elm;
				_elems[NewFlag] = t;
				NewFlag++;
				_maxElm = elm;
			}
			else if (elm.content > _elems[0].content)
			{
				_elems[NewFlag].content = array[index];
				_elems[NewFlag].Cnt = 1;
				NewFlag++;
				_maxElm = _elems[0];
			}
			else
			{
				_elems[0].Cnt++;;
				_maxElm = _elems[0];
			}
		}
	}

	void EngageElemInVector(vector<int> &array, int index)
	{
		if (array[index] < 0 || array[index]>2147483647) return;
		if (index == 0)
		{
			Elem elm;
			elm.content = array[index];
			elm.Cnt = 1;
			_vecElems.push_back(elm);
			_maxElm = elm;
			return;
		}
		// 			
		Elem elm;
		elm.content = array[index];
		elm.Cnt = 1;
		//_elems[NewFlag] = elm;
		/*elems.push_back(elm);*/
		int IsFind = -1;
		if (_vecElems.size() > 1)
		{
			startTime = clock();
			IsFind = binaryGetInVector(elm);
			endTime = clock();

			if (IsFind != -1)
			{
				_vecElems[IsFind].Cnt++;

				if (_vecElems[IsFind].Cnt > _maxElm.Cnt)
				{
					_maxElm = _vecElems[IsFind];
				}
				else if (_vecElems[IsFind].Cnt == _maxElm.Cnt)
				{
					if (_vecElems[IsFind].content <= _maxElm.content)
					{
						_maxElm = _vecElems[IsFind];
					}
				}
			}
			
			SortCounter += (double)(endTime - startTime) / CLOCKS_PER_SEC;
		}
		else
		{
			if (elm.content < _vecElems[0].content)
			{
				_vecElems.push_back(elm);
				swap(_vecElems[0], _vecElems[1]);
				_maxElm = elm;
			}
			else if (elm.content > _vecElems[0].content)
			{
				_vecElems.push_back(elm);
				_maxElm = _vecElems[0];
			}
			else
			{
				_vecElems[0].Cnt++;;
				_maxElm = _vecElems[0];
			}
		}
	}

	int binaryGet(Elem* data, int dataSize, Elem elm)
	{
		int left = 0;
		int right = dataSize - 1;
		int mid = left + ((right - left) >> 1);
		int FindPos = -1;
		while (left <= right)
		{
			if (data[mid].content > elm.content)
				right = mid - 1;
			else if (data[mid].content < elm.content)
				left = mid + 1;
			else if (data[mid].content == elm.content)
			{
				FindPos = mid;
				return FindPos;
			}
			else
				break;
			mid = left + ((right - left) >> 1);
		}
		mid++;
		if (mid > dataSize - 1)
		{
			data[dataSize] = elm;
		}
		else
		{
			const int size = (dataSize - mid) * sizeof(Elem);
			// 			Elem* elmTemp = new Elem[size];
			memcpy(_elemTemp, data + mid, size);
			memcpy(data + mid + 1, _elemTemp, size);
			//memcpy(data + mid, data + mid - 1, size);


			/*delete[] elmTemp;*/
			// 			for (int i = dataSize; i > mid;i--)
			// 			{
			// 				data[i] = data[i - 1];
			// 			}
			data[mid] = elm;
		}
		return FindPos;
	}

	int binaryGetInVector(Elem elm)
	{
		int dataSize = _vecElems.size();
		int left = 0;
		int right = dataSize - 1;
		int mid = left + ((right - left) >> 1);
		int FindPos = -1;
		while (left <= right)
		{
			if (_vecElems[mid].content > elm.content)
				right = mid - 1;
			else if (_vecElems[mid].content < elm.content)
				left = mid + 1;
			else if (_vecElems[mid].content == elm.content)
			{
				FindPos = mid;
				return FindPos;
			}
			else
				break;
			mid = left + ((right - left) >> 1);
		}
		mid++;
		if (mid > dataSize - 1)
		{
			//_vecElems[dataSize] = elm;
			_vecElems.push_back(elm);
		}
		else
		{
			_vecElems.insert(std::begin(_vecElems) + mid, elm);
		}
		return FindPos;
	}


	int binarySearch(Elem* data, int dataSize, int target) {
		if (dataSize == 0) return -1;
		int left = 0;
		int right = dataSize - 1; // 注意
		int Pos = -1;
		while (left <= right) { // 注意
			int mid = (left + right) / 2;
			if (data[mid].content == target)
			{
				Pos = mid;
				break;
			}
			else if (data[mid].content < target)
			{

				left = mid + 1;
			}
			else if (data[mid].content > target)
			{
				right = mid - 1;
			}
		}
		return Pos;
	}

	void binarySort(Elem* data, int dataSize, Elem elm)
	{
		int left = 0;
		int right = dataSize - 1;
		int mid = left + ((right - left) >> 1);
		while (left <= right)
		{
			if (data[mid].content > elm.content)
				right = mid - 1;
			else if (data[mid].content < elm.content)
				left = mid + 1;
			else
				break;
			mid = left + ((right - left) >> 1);
		}
		mid++;
		if (mid > dataSize - 1)
		{
			data[dataSize] = elm;
		}
		else
		{
			const int size = (dataSize - mid) * sizeof(Elem);
			// 			Elem* elmTemp = new Elem[size];
			memcpy(_elemTemp, data + mid, size);
			memcpy(data + mid + 1, _elemTemp, size);
			//memcpy(data + mid, data + mid - 1, size);


			/*delete[] elmTemp;*/
			// 			for (int i = dataSize; i > mid;i--)
			// 			{
			// 				data[i] = data[i - 1];
			// 			}
			data[mid] = elm;
		}
	}

	void ShellSort(Elem *data, int len)
	{
		int h = 1;
		while (h < len)
			h = 3 * h + 1;
		while (h > 0)
		{
			for (int j = h; j < len; j++)
			{
				Elem key = data[j];
				int i = j - h;
				while (i >= 0 && data[i].content > key.content)
				{
					data[i + h] = data[i];
					i = i - h;
				}
				data[i + h] = key;
			}
			h = h / 3;
		}
	}

	void shellSortImproved(Elem* data, int len)
	{
		if (data == nullptr || len <= 0)
		{
			return;
		}
		for (int gap = len / 2; gap > 0; gap /= 2)   // 划分间隔大小
		{
			for (int i = gap; i < len; i++)
			{
				Elem temp = data[i];
				int k = i;
				for (int j = i - gap; j >= 0; j = j - gap)
				{
					if (temp.content < data[j].content)
					{
						data[j + gap] = data[j];
						k = j;
					}
				}
				data[k] = temp;
			}
		}
	}

	int binarySearchImproved(Elem* data, int dataSize, int value)
	{

		int index = -1;             //指定值的位置，找不到返回-1
		int low = 0;                //区间段内最小下标，初始时为0
		int high = dataSize - 1;  //区间段内最大下标，初始时为数组长度-1

								  //在进入循环之前先对边界值进行比较
		if (data[low].content == value) {
			index = low;
		}
		else if (data[high].content == value) {
			index = high;
		}
		else {
			while (low <= high) {
				int mid = (low + high) / 2;
				if (data[mid].content == value) {
					index = mid;
					break;
				}
				else if (data[mid].content > value) {
					high = mid - 1;             //将查找区间改为【low , mid-1】
					if (data[high].content == value) {   //对刚修改的边界值arr[high]进行判断
						index = high;
						break;
					}
				}
				else {
					low = mid + 1;              //将查找区间改为【mid+1 , high】
					if (data[low].content == value) {    //对刚修改的边界值arr[low]进行判断
						index = low;
						break;
					}
				}

			}
		}
		return index;

	}


	//归并排序
	//本质上是把两个已经排好的序列合并成一个
	//如果对一个随机序列的两两元素来看，那么每个元素都是排好的序列
	//可以把一个数组拆分成前后两半来做这件事
	//这个算法需要额外的辅助空间，用来存放归并好的结果
	void mergeSort(Elem* data, int start, int end)
	{
		if (start >= end)
		{
			return;
		}
		int i = start;
		int mid = (start + end) / 2;
		int j = mid + 1;
		mergeSort(data, i, mid);
		mergeSort(data, j, end);

		//合并
		//其实我觉得不用这个额外的空间也行，两个子序列再排一次能减少空间，不过速度肯定会有影响
		//Elem* temp = (Elem*)malloc((end - start + 1) * sizeof(int));
		Elem* temp = new Elem[(end - start + 1) * sizeof(int)];
		int index = 0;
		//开始对比两个子序列，头部最小的那个数放到新空间
		while (i <= mid&&j <= end)
		{
			if (data[i].content <= data[j].content)
			{
				temp[index++].content = data[i++].content;
			}
			else
			{
				temp[index++].content = data[j++].content;
			}
		}
		//总有一个序列是还没有放完的，这里再遍历一下没放完的
		while (i <= mid)
		{
			temp[index++] = data[i++];
		}
		while (j <= end)
		{
			temp[index++] = data[j++];
		}
		//排完再把新空间的元素放回旧空间
		int k = start;
		for (k;k <= end;k++)
		{
			//哎，temp的下标写错，排查了一个钟，真菜
			data[k] = temp[k - start];
		}
		//free(temp);
		delete[] temp;
	}

	void Merge_SortDC(Elem* data,int low ,int high,int size)
	{/* 用分治法对R[low..high]进行二路归并排序 */
		int mid;
		if(size > 1)
		{/* 区间长度大于1 */
			int low = 0;
			int high = size - 1;
			mid = (low + high) / 2; /* 分解 */
			Merge_SortDC(data,low, mid,size); /* 递归地对R[low..mid]排序 */
			Merge_SortDC(data,mid + 1, high,size); /* 递归地对R[mid+1..high]排序 */
			Merge(data,low, mid, high); /* 组合，将两个有序区归并为一个有序区 */
		}
	}

	void Merge(Elem* data,int low, int m, int high)
	{/* 将两个有序的子文件R[low..m)和R[m+1..high]归并成一个有序的 */
	 /* 子文件R[low..high] */
		int i = low, j = m + 1, p = 0; /* 置初始值 */
		Elem *R1; /* R1是局部向量，若p定义为此类型指针速度更快 */
		R1 = (Elem *)malloc((high - low + 1) * sizeof(int));
		if (!R1) /* 申请空间失败 */
		{
			puts("Insufficient memory available!");
			return;
		}
		while (i <= m&&j <= high) /* 两子文件非空时取其小者输出到R1[p]上 */
			R1[p++] = (data[i].content <= data[j].content) ? data[i++] : data[j++];
		while (i <= m) /* 若第1个子文件非空，则复制剩余记录到R1中 */
			R1[p++] = data[i++];
		while (j <= high) /* 若第2个子文件非空，则复制剩余记录到R1中 */
			R1[p++] = data[j++];
		for (p = 0, i = low;i <= high;p++, i++)
			data[i] = R1[p];/* 归并完成后将结果复制回R[low..high] */
	}





};

