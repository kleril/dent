#pragma once
//Figure out what all objects have in common. Throw that nonsense in here (then create the .cpp to go with it)

class GameObject
{
public:
	void onTick(float ticks);
	//Stole load and unload from here, put them in Renderable.h instead. Figure out what loading entails.
	//Don't put constructors in here maybe?
	/*
	GameObject();
	~GameObject();
	*/
protected:

private:
};