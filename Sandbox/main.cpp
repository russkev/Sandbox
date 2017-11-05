//Move semantics
//#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <string>


struct object
{
	std::string m_name;
	std::vector<float> m_data;
};

struct transform
{
	std::string m_name;
	float m_position;
};

struct container
{
	std::vector<object>					objects;
	std::vector<transform>				transforms;
	std::map<std::string, int>			objects_map;
	std::map<std::string, int>			transforms_map;
	std::map<std::string, std::string>	connections;

	void appendObject(object s_object)
	{
		objects.push_back(s_object);
		objects_map.insert(std::pair<std::string, int>(s_object.m_name, objects.size() - 1));
	}
	void appendTransform(transform s_transform)
	{
		transforms.push_back(s_transform);
		transforms_map.insert(std::pair<std::string, int>(s_transform.m_name, transforms.size() - 1));
	}
	void connect(std::string s_source, std::string s_target)
	{
		connections.insert(std::pair<std::string, std::string>(s_source, s_target));
		for (auto i : objects.at(objects_map.find(s_target)->second).m_data)
		{
			i = i * transforms.at(transforms_map.find(s_source)->second).m_position;
		}
	}

	
};


int main() {
	object object1, object2, object3;
	transform trans1, trans2, trans3;
	container container1;

	object1.m_name = "cheese";
	object2.m_name = "grapes";
	object3.m_name = "nuts";
	trans1.m_name  = "nuts_transform";
	trans2.m_name  = "cheese_transform";
	trans3.m_name  = "grapes_transform";

	object1.m_data = { 3.0f, 6.0f, 5.0f };
	object1.m_data = { 1.0f, 2.0f, 9.0f };
	object1.m_data = { 3.0f, 1.0f, 0.0f };
	trans1.m_position = 3.456f;
	trans2.m_position = 4.216f;
	trans3.m_position = 5.185f;

	container1.appendObject(object1);
	container1.appendObject(object2);
	container1.appendObject(object3);
	container1.appendTransform(trans1);
	container1.appendTransform(trans2);
	container1.appendTransform(trans3);

	container1.connect("cheese_transform",	"cheese");
	container1.connect("grapes_transform",	"grapes");
	container1.connect("nuts_transform",	"nuts");

}

