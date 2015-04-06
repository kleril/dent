#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <LoadingManager.h>
#include <iostream>

LoadingManager::LoadingManager()
{

}

LoadingManager::~LoadingManager()
{

}

void LoadingManager::loadMap(std::string path)
{
	char* c = new char[path.length() + 1];
	strcpy(c, path.c_str());
	try
	{
		map = TMX::parse(c);

		loadTiles();
		loadObjects();
	}
	catch (std::exception& e)
	{
		throw e;
		std::cout << "Map parse failed! \n";
	}
	delete[] c;
}

void LoadingManager::loadTiles()
{
	std::cout << "Loading Tiles... \n";
	for (TMX::TileLayer* layer : map->tile_layers_below)
	{
		//layer->Print();
		for (std::vector<int> tileMap : layer->tiles)
		{
			for (int tile : tileMap)
			{
				//std::cout << tile;
			}
		}
	}
}

void LoadingManager::loadObjects()
{
	std::cout << "Loading Objects... \n";
	for (std::pair <std::string, TMX::ObjectGroup> objectGroup : map->object_groups)
	{
		std::cout << objectGroup.first.data();
		std::cout << "\n";

		for (std::pair<std::string, TMX::Object> currentObject : objectGroup.second.objects)
		{
			std::cout << currentObject.first.data();
			std::cout << ": ";
			std::cout << currentObject.second.type;
			//std::cout << currentObject.second.property._Myhead->_Myval.first;
			/* for (TMX::Object::property property : currentObject.second.property)
			{
				std::cout << property.data();
			} */
			std::cout << "\n";
		}
	}
}

void LoadingManager::unloadCurrentMap()
{

}