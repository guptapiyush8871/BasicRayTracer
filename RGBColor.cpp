#include "RGBAColor.h"

RGBAColor::RGBAColor() 
{
	m_R = 0;
	m_G = 0;
	m_B = 0;
	m_A = 0;
}

RGBAColor::RGBAColor(const unsigned short iR, const unsigned short iG, const unsigned short iB, const unsigned short iA) 
{
	m_R = iR;
	m_G = iG;
	m_B = iB;
	m_A = iA;
}

RGBAColor::RGBAColor(const RGBAColor& iColor) 
{
	m_R = iColor.m_R;
	m_G = iColor.m_G;
	m_B = iColor.m_B;
	m_A = iColor.m_A;
}

RGBAColor::~RGBAColor() 
{
}

void RGBAColor::SetColor(const unsigned short iR, const unsigned short iG, const unsigned short iB, const unsigned short iA) 
{
	m_R = iR;
	m_G = iG;
	m_B = iB;
	m_A = iA;
}

void RGBAColor::GetColor(unsigned short& oR, unsigned short& oG, unsigned short& oB, unsigned short& oA) const 
{
	oR = m_R;
	oG = m_G;
	oB = m_B;
	oA = m_A;
}
