#include <iostream>
#include <fstream>

void print_status( std::string const msg)
{
	std::cout	<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( int argc, char **argv )
{
	if (argc == 4)
	{
		std::string		filename(argv[1]);
		std::ifstream	ifs(filename);

		if( ifs.fail() )
		{
			std::cerr << "Error: File " << filename << " can not be opened!" << std::endl;
			return (1);
		}

		std::ofstream	ofs(filename + ".replace");
		std::string		find = argv[2];
		std::string		replace = argv[3];

		std::string		line;
		size_t			pos = 0;
		while ( getline( ifs, line ) )
		{
			while ((pos = line.find(find)) != std::string::npos)
			{
				ofs << line.substr(0, pos);
				ofs << replace;
				line.erase(0, pos + find.length());
			}
			ofs << line << "\n";
		}
		ifs.close();
		ofs.close();
		print_status("--- File " + filename + ".replace created ");
	}
	else
	{
		std::cerr << "Formating error: ./replace <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	return (0);
}
