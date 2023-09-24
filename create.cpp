#include "create.hpp"

int	ft_check_f_flag(char **av)
{
	std::string str;

	for (int i = 0; av[i]; i++)
	{
		str = av[i];
		if (str == "-f")
			return (1);
	}
	return (0);
}

int	ft_check_c_flag(char **av)
{
	std::string str;

	for (int i = 0; av[i]; i++)
	{
		str = av[i];
		if (str == "-c")
			return (1);
	}
	return (0);
}

std::string stringToUpper(std::string str)
{
	std::string result;

	for (int i = 0; str[i]; i++)
	{
		result += toupper(str[i]);
	}
	return (result);
}

//if headerOrMain == 1 -> create a constructor for main file, else create constructor for header file
std::string	ft_create_constructor(std::string className, int headerOrMain)
{
	std::string result;

	if (headerOrMain)
		result = className + "::" + className + "()\n{\n\n}\n";
	else
		result = "\t\t" + className + "();\n";
	return (result);
}

//if headerOrMain == 1 -> create a constructor for main file, else create constructor for header file
std::string	ft_create_destructor(std::string className, int headerOrMain)
{
	std::string result;

	if (headerOrMain)
		result = className + "::" + "~" + className + "()\n{\n\n}\n";
	else
		result = "\t\t~" + className + "();\n";
	return (result);
}

//if headerOrMain == 1 -> create a constructor for main file, else create constructor for header file
std::string	ft_create_copy_constructor(std::string className, int headerOrMain)
{
	std::string result;

	if (headerOrMain)
		result = className + "::" + className + "(const " + className + " &another)\n{\n\n}\n";
	else
		result = "\t\t" + className + "(const " + className + " &another);\n";
	return (result);
}

//if headerOrMain == 1 -> create a constructor for main file, else create constructor for header file
std::string	ft_create_operator_overload(std::string className, int headerOrMain)
{
	std::string result;

	if (headerOrMain)
		result = className + "\t&" + className + "::operator=(const " + className + " &another)\n{\n\n}\n";
	else
		result = "\t\t" + className + "\t&" + className + "::operator=(const " + className + " &another);\n";
	return (result);
}

void	ft_create_header_file(std::string className, char **av)
{
	std::ofstream outfile(className + ".hpp");
	outfile << "#ifndef " + stringToUpper(className) + "_HPP\n";
	outfile << "#define " + stringToUpper(className) + "_HPP\n\n";
	outfile << "#include <iostream>\n\n";
	outfile << "class " + className + "\n";
	outfile << "{\n";
	if (!ft_check_c_flag(av))
	{
		outfile << "\tpublic :\n";
		outfile << ft_create_constructor(className, 0);
		outfile << ft_create_destructor(className, 0);
		outfile << ft_create_copy_constructor(className, 0);
		outfile << ft_create_operator_overload(className, 0);
	}
	outfile << "};\n\n";
	outfile << "#endif\n";
	outfile.close();
}

void	ft_create_main_file(std::string className, char **av)
{
	std::ofstream outfile(className + ".cpp");
	outfile << "#include \"" + className + ".hpp\"\n\n";
	if (!ft_check_c_flag(av))
	{
		outfile << ft_create_constructor(className, 1) << "\n";
		outfile << ft_create_destructor(className, 1) << "\n";
		outfile << ft_create_copy_constructor(className, 1) << "\n";
		outfile << ft_create_operator_overload(className, 1) << "\n";
	}
	outfile.close();
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		char *fileName = ft_strtrim(av[1], ".hpp");
		ft_create_header_file(fileName, av);
		if (ft_check_f_flag(av))
			ft_create_main_file(fileName, av);
		free(fileName);
	}
	return (0);
}
