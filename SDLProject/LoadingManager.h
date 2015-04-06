#include "string"

#include <tmx_map.hpp>
#include <tsx_tileset.hpp>
#include <xml_utils.hpp>

class  LoadingManager
{
public:
	 LoadingManager();
	~ LoadingManager();
	void loadMap(std::string path);
	void unloadCurrentMap();
	void loadTiles();
	void loadObjects();

private:
	TMX::Map* map;
	int mapHeight;
	int mapWidth;
	int tileHeight;
	int tileWidth;

	std::vector<int> tileMap;

};