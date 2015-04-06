#include <String>
#include <vector>
#include <BaseComponent.h>

class MapComponent : public BaseComponent
{
public:
	MapComponent();
	~MapComponent();
	//Change entity's type to a better identifier... Int could cause problems
	bool addEntity(std::pair<int, int> position, int entity);
	bool moveEntity(std::pair<int, int> newPosition, std::vector<int> entity);
	bool unloadMap();
private:
	std::pair<int, int> mapPosition;
	//Does not actually hold entities. Just tracks the *expected* set of entities at the given position.
	std::vector<std::pair<int, int>, std::vector<int>> entityAtPosition;
};