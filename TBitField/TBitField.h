#pragma once

#include <iostream>
typedef unsigned int TELEM;
class TBitField
{
	int BitLen;
	TELEM* pMem;
	int MemLen;
	int GetMemIndex(const int n) const;
	TELEM GetMemMask(const int n) const;
public:
	TBitField(int len);
	TBitField(const TBitField& bf);
	~TBitField();
	int GetBit(const int n);
	void SetBit(const int n);
	void CleanBit(const int n);
	friend std::ostream& operator<<(std::ostream& os, const TBitField& bf);
	TBitField& operator= (const TBitField& bf);
};