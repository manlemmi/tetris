#ifndef __PIXEL__
#define __PIXEL__

class Pixel 
{
public:
	virtual void movingRight() & = 0;
	virtual void movingLeft() & = 0;
	virtual void falling() & = 0;
};

#endif  __PIXEL__
