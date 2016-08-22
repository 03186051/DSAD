#include <vector>

#ifndef xPRIORITY_QUEUE_H
#define xPRIORITY_QUEUE_H

// Ĭ���ڲ�ʹ��vector��Ϊ�洢.
template <typename T, typename Sequence = std::vector<T>>
class xPriority_Queue {
public:
	xPriority_Queue();
	const T& top() const;
	void push(const T& item);
	void pop();
	size_t size() const;
	bool empty() const;
private:
	// �ؼ�����: �ϸ�����.
	void swim(size_t i);
	// �ؼ�����: �³�����.
	void sink(size_t i);
	Sequence c;
};

// ���캯����ʵ��.
template <typename T, typename Sequence>
xPriority_Queue<T, Sequence>::xPriority_Queue()
	: c(1)
{
	// ��ʼ��c�ĳ���Ϊ1, c[0]��Ϊ�ڱ��������ʵԪ��.
}

// �������Ԫ�ĳ����汾.
template <typename T, typename Sequence>
const T& xPriority_Queue<T, Sequence>::top() const
{
	// ע�ⲻ�ɷ�������, ��ִ�б�������Ҫ�����ȼ����зǿ�.
	return c[1];
}

// ����Ԫ�ط������ȼ�����.
template <typename T, typename Sequence>
void xPriority_Queue<T, Sequence>::push(const T& item)
{
	// ��Ԫ���Ȳ���c��ĩβ.
	c.push_back(item);
	// ����ڲ��������ϸ�����.
	swim(c.size() - 1);
}

// ɾ�����Ԫ.
template <typename T, typename Sequence>
void xPriority_Queue<T, Sequence>::pop()
{
	// ǰ�������ȼ����зǿ�, ����c[1]����Ԫ��.
	c[1] = c[ c.size() - 1 ];
	// ����c�Ĵ�С.
	c.pop_back();
	// ��1λ��ִ���³�����.
	sink(1);
}

// �������ȼ����еĴ�С.
template <typename T, typename Sequence>
size_t xPriority_Queue<T, Sequence>::size() const
{
	// ʵ��Ԫ��Ϊc.size() - 1.
	return c.size() - 1;
}

// �ж����ȼ������Ƿ�Ϊ��.
template <typename T, typename Sequence>
bool xPriority_Queue<T, Sequence>::empty() const
{
	// c����Ϊ1ʱ�����ȼ�����Ϊ��.
	return (c.size() == 1);
}

// �ڽ��i��ִ���ϸ�����.
template <typename T, typename Sequence>
void xPriority_Queue<T, Sequence>::swim(size_t i)
{
	// ��c[0]�������ڱ�����ֹѭ��, �������ʼ���i��������.
	c[0] = c[i];
	// ���c[i]���ڸ��׽��c[i / 2]�򲻶��ϸ�,
	// ����ʼ��㴦�������ݲ�����, ��ֵ����c[0].
	while (c[i / 2] < c[i])
	{
		c[i] = c[i / 2];
		i = i / 2;
	}
	// ����ʼ��㴦�����ݴ����ϸ���������ͣ����λ��.
	c[i] = c[0];
}

// �ڽ��i��ִ���³�����.
template <typename T, typename Sequence>
void xPriority_Queue<T, Sequence>::sink(size_t i)
{
	// �ݴ�c[i]����.
	c[0] = c[i];
	// �����Һ��ӱ��.
	size_t rChildNo = 2 * i + 1;
	// �Һ��Ӵ���(�����Һ��Ӿ�����)ʱ���³�.
	while (rChildNo < c.size())
	{
		size_t MAX = i;
		// �Һ��ӽϴ���MAX��Ϊ�Һ��ӱ��.
		if (c[MAX] < c[rChildNo])
			MAX = rChildNo;
		// ���ӽϴ���MAX��Ϊ���ӱ��.
		if (c[MAX] < c[rChildNo - 1])
			MAX = rChildNo - 1;
		// ����: ����Ҫ�������³�����.
		if (MAX == i)
			break;
		// ��Ҫ����ʱ�Ƚ��ϴ�ĺ��Ӵ���iλ��.
		c[i] = c[MAX];
		// ���������ж�.
		i = MAX;
		rChildNo = 2 * i + 1;
	}
	// �����������.
	if (rChildNo == c.size())
	{
		// ������������.
		if (c[i] < c[rChildNo - 1])
		{
			// ��Ҫ����ʱ�Ƚ����Ӵ���iλ��.
			c[i] = c[rChildNo - 1];
			// �������ͣ��λ��.
			i = rChildNo - 1;
		}
	}
	// ����ʼ��㴦�����ݴ����³���������ͣ����λ��.
	c[i] = c[0];
}

#endif  // xPRIORITY_QUEUE_H

