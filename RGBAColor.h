#ifndef RGBACOLOR_H
#define RGBACOLOR_H

class RGBAColor 
{
public:
	RGBAColor();
	RGBAColor(const unsigned short iR, const unsigned short iG, const unsigned short iB, const unsigned short iA);
	RGBAColor(const RGBAColor& iColor);
	~RGBAColor();

	void SetColor(const unsigned short iR, const unsigned short iG, const unsigned short iB, const unsigned short iA);
	void GetColor(unsigned short& oR, unsigned short& oG, unsigned short& oB, unsigned short& oA) const;

	const RGBAColor& operator=(const RGBAColor& iColor);

private:
	unsigned short m_R;
	unsigned short m_G;
	unsigned short m_B;
	unsigned short m_A;
};

#endif
