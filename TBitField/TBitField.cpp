#include "TBitField.h"

#include<iostream>

TBitField::TBitField(int len)
{
	BitLen = len;
	MemLen = (len + 31) >> 5;
	pMem = new TELEM[MemLen];
	if (pMem != NULL)
	{
		for (int i = 0; i < MemLen; i++)
		{
			pMem[i] = 0;
		}
	}
}

TBitField::TBitField(const TBitField& bf)
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[bf.MemLen];
	if (pMem != NULL)
	{
		for (int i = 0; i < MemLen; i++)
		{
			pMem[i] = bf.pMem[i];
		}
	}
}

TBitField& TBitField::operator=(const TBitField& bf)
{
	BitLen = bf.BitLen;
	if (MemLen != bf.MemLen)
	{
		MemLen = bf.MemLen;
		if (pMem != NULL)
			delete(pMem);
		pMem = new TELEM[MemLen];
	};
	if (pMem != NULL)
	{
		for (int i = 0; i < MemLen; i++)
		{
			pMem[i] = bf.pMem[i];
		};
	};
	return *this;
}

int GetMemMask(const int n)
{
	int k = n >> 5;
	int pos = n & 31;
	return pos;
}

int GetMemIndex(const int n)
{
	int k = n >> 5;
	return k;
}

void TBitField::SetBit(const int n)
{
	if ((n > -1) && (n < BitLen))
	{
		pMem[GetMemIndex(n)] |= GetMemMask(n);
	}
}

void TBitField::CleanBit(const int n)

{
	if ((n > -1) && (n < BitLen))
	{
		pMem[GetMemIndex(n)] &= ~GetMemMask(n);
	}
}


int TBitField::GetBit(const int n)

{
	if ((n > -1) && (n < BitLen))
	{
		int k = pMem[GetMemIndex(n)] & GetMemMask(n);
		return k;
	}
	return 0;
}

std::ostream& operator<<(std::ostream & os, const TBitField & bf)
{
	for (int i = 0; i < bf.MemLen; i++)
	{
		if (bf.GetBit(i)) {
			os << '1';
		}
		else
		{
			os << '0';
		}
	}
	return os;
}



int main()
{


}