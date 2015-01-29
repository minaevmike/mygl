#ifndef __MODEL_H
#define __MODEL_H
#include <string>
#include <vector>
class Model {
	public:
		Model(std::string filename);
		~Model();
		int nverts();
		int nfaces();
		std::vector<int> face(int i);

}

#endif //__MODEL_H
