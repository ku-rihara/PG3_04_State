#pragma once


class BaseScene{
protected:



public:
	BaseScene();
	virtual ~BaseScene();

	virtual void  Init() = 0;
	virtual void  Update() = 0;
	virtual void  Draw() = 0;

};

