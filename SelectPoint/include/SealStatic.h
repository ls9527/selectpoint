#pragma once

class CSealStatic : public CStatic
{
public:
	CSealStatic(void);
	~CSealStatic(void);

	
public:

	DECLARE_MESSAGE_MAP();
private:
	
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

};

