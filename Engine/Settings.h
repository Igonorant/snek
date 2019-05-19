#pragma once
#include<fstream>
#include<string>
#include<assert.h>


class Settings {
public:
	Settings()
	{
		std::fstream set;
		set.open(fileName,std::fstream::in);
		assert(set.is_open() == true);

		// loop search trought each line of the file until reach eof
		while (!set.eof()) {
			std::getline(set, buffer);
			if (buffer != "") {
				// check every needed information on the settings file
				if (buffer == "[Tile Size]") {
					buffer.clear();
					std::getline(set, buffer);
					tileSize = std::stoi(buffer);
				}
				if (buffer == "[Board Size]") {
					buffer.clear();
					set >> buffer;
					width = std::stoi(buffer);
					buffer.clear();
					set >> buffer;
					height = std::stoi(buffer);
				}
				if (buffer == "[Speedup Rate]") {
					buffer.clear();
					std::getline(set, buffer);
					speedupRate = std::stof(buffer);
				}
				if (buffer == "[Poison Amount]") {
					buffer.clear();
					std::getline(set, buffer);
					poisonAmount = std::stoi(buffer);
				}
				if (buffer == "[Food Amount]") {
					buffer.clear();
					std::getline(set, buffer);
					foodAmount = std::stoi(buffer);
				}
			}
			buffer.clear();
		}
		// check if every variable are initialized
		assert(tileSize != 0 && width != 0 && height != 0 && speedupRate != 0 && poisonAmount != 0 && foodAmount != 0);
		set.close();
	}

public:
	int tileSize = 0;
	int width = 0;
	int height = 0;
	float speedupRate = 0;
	int poisonAmount = 0;
	int foodAmount = 0;
private:
	std::string fileName = "settings.txt";
	std::string buffer;
};