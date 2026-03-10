#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

int	main(int argc, char** argv)
{
	std::string line;
	std::string replaced;
	size_t l = 0;

	if (argc != 4)
		return (-1);

	std::string inputName(argv[1]);
	std::string toRep(argv[2]);
	std::string rep(argv[3]);

	if (toRep.empty())
	{
		std::cout << "Cannot replace emptyness" << std::endl;;
		return (1);
	}

    std::ifstream inFile(inputName.c_str());
	if (!inFile) {
        std::cout << "Unable to open file" << std::endl;;
    	return (1);
    }

    std::string outName = inputName + ".replaced";
    std::ofstream outFile(outName.c_str());
	if (!outFile.is_open())
	{
		std::cout << "Unable to create output file" << std::endl;
		return (1);
	}

	while (getline(inFile, line))
	{
		while (l != std::string::npos) {
			l = line.find(toRep, l);
			if (l != std::string::npos) {
				//std::cout << l << " :: " << line << " :: " << &line[l] << std::endl;
				line.erase(l, toRep.size());
				line.insert(l, rep);
				l += rep.size();
			}
		}
		l = 0;
		outFile << line;
		outFile << "\n";
	}
}