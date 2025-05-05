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

    std::ifstream inFile(inputName.c_str());
	if (!inFile) {
        std::cout << "Unable to open file";
    	return (1);
    }
    std::string outName = inputName + ".replaced";
    std::ofstream outFile(outName.c_str());
	while (getline(inFile, line))
	{
		while (l != std::string::npos) {
			l = line.find(toRep, l);
			if (l != std::string::npos) {
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