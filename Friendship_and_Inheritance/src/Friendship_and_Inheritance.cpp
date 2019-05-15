//============================================================================
// Name        : Friendship_and_Inheritance.cpp
// Author      : jrangel
// Version     :
// Copyright   : cplusplus - Frienship and Inheritance
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * In principle, private and protected members of a class cannot be accessed from outside the same class in which they are declared.
 * However, this rule does not affect friends.
 * Friends are functions or classes declared with the friend keyword.
 * */
/*							FRIEND FUNCTION BEGIN
#include <iostream>
using namespace std;

class CRectangle {
	private:
    	int width, height;
	public:
		CRectangle ();
		CRectangle (int, int);
		~CRectangle (){};
		int area () {return (width * height);}
		friend CRectangle duplicate (CRectangle);		//class duplicate has access to the private & protected members
};

CRectangle::CRectangle(){width = 0; height = 0;}

CRectangle::CRectangle (int a, int b) { width = a; height = b;}

CRectangle duplicate (CRectangle rectparam) {
  CRectangle rectres;
  rectres.width = rectparam.width*2;
  rectres.height = rectparam.height*2;
  return (rectres);
}

int main () {
  CRectangle rect (2,3);
  CRectangle rectb;
  rectb = duplicate (rect);
  cout << rectb.area();
  return 0;
}							FRIEND FUNCTION END
*/

//							FRIEND CLASS BEGIN
#include <iostream>
using namespace std;

class CSquare;					//Even if ain´t define CSquare at this point, since I need such class in CRectangle def I can makea draft like this

class CRectangle {
  private:
    int width, height;
  public:
    int area ()
      {return (width * height);}
    void convert (CSquare a);	//convert an object of the CSquare class as a parameter, is the reason why it was declared beforewards
};

class CSquare {
  private:
    int side;
  public:
    void set_side (int a)
      {side=a;}
    friend class CRectangle;
};

void CRectangle::convert (CSquare a) {
  width = a.side;
  height = a.side;
}

int main () {
  CSquare sqr;
  CRectangle rect;
  sqr.set_side(4);
  rect.convert(sqr);
  cout << rect.area();
  return 0;
}
//							FRIEND CLASS END
