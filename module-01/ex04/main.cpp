#include <fstream>
#include <iostream>

void	createReplacement(
		std::ifstream& file,
		const std::string& new_filename,
		const std::string& find,
		const std::string& replace)
{
	if (new_filename.empty() || find.empty())
	{
		std::cerr << "Error: empty argument." << std::endl;
		return ;
	}

	std::string		line;
	std::ofstream	outFile(new_filename.c_str());

	if (!outFile.is_open())
	{
		std::cerr << "Error: unable to open file" << std::endl;
		std::cerr << "File: " << new_filename << std::endl;
		return ;
	}

	while (std::getline(file, line))
	{
		std::size_t	pos = line.find(find);
		std::size_t	prev_pos = 0;

		while (pos != std::string::npos)
		{
			outFile << line.substr(prev_pos, pos - prev_pos);
			outFile << replace;
			prev_pos = pos + find.size();
			pos = line.find(find, prev_pos);
		}
		outFile << line.substr(prev_pos);
		outFile << '\n';
	}

	outFile.close();
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream	inFile(argv[1]);
		std::string		new_filename(argv[1]);
		std::string		find(argv[2]);
		std::string		replace(argv[3]);

		if (!inFile.is_open())
		{
			std::cerr << "Error: unable to open file" << std::endl;
			std::cerr << "File: " << argv[1] << std::endl;
			return (1);
		}
		new_filename += ".replace";
		createReplacement(inFile, new_filename, find, replace);
		inFile.close();
	}
	else
	{
		if (argc > 4)
			std::cout << "Too many arguments." << std::endl;
		else
			std::cout << "Too few arguments." << std::endl;
		return (1);
	}
	return (0);
}
