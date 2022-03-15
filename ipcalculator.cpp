#include <iostream>

int main( void)
{
	std::string		ip;
	std::string		mask;
	std::string		delimiter = ".";
	std::string		octet[3];

	std::cout	<< std::endl;
	std::cout	<< "Please, enter IP: ";
	std::getline(std::cin, ip);
	std::cout	<< "Please, enter Mask: ";
	std::getline(std::cin, mask);

	size_t			pos = 0;
	int				i = 0;
	while ((pos = ip.find(delimiter)) != std::string::npos)
	{
		octet[i] = ip.substr(0, pos);
		ip.erase(0, pos + delimiter.length());
		i++;
	}

	int			octed4 = std::stoi(ip);
	int			subMask;
	int			nOfHosts;
	int			start = 0;

	if (mask == "24")
		subMask = 0;
	if (mask == "25")
		subMask = 128;
	if (mask == "26")
		subMask = 192;
	if (mask == "27")
		subMask = 224;
	if (mask == "28")
		subMask = 240;
	if (mask == "29")
		subMask = 248;
	if (mask == "30")
		subMask = 252;

	nOfHosts = 256 - subMask;
	std::cout	<< std::endl
				<< "IP Subnet Calculator for "
				<< octet[0] << "." 
				<< octet[1] << "." 
				<< octet[2] << "." 
				<< "* /" << mask << " (" << subMask << ")"
				<< std::endl << std::endl;
	while (start < 256)
	{
		if (octed4 >= start && octed4 < start + nOfHosts)
			std::cout	<< "* ";
		else
			std::cout	<< "  ";

		std::cout	<< octet[0] << "." 
					<< octet[1] << "." 
					<< octet[2] << "." 
					<< start << ": \t";
		std::cout	<< octet[0] << "." 
					<< octet[1] << "." 
					<< octet[2] << "." 
					<< start + 1 << " - ";
		std::cout	<< octet[0] << "." 
					<< octet[1] << "." 
					<< octet[2] << "." 
					<< start + nOfHosts - 2 << std::endl;
		start += nOfHosts;
	}
	return 0;
}
