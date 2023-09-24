#ifndef CREATE_HPP
#define CREATE_HPP

#include <iostream>
#include <fstream>

//utils
char		*ft_strtrim(char const *s1, char const *set);
std::string	stringToUpper(std::string str);

//create file
void		ft_create_main_file(std::string className, char **av);
void		ft_create_header_file(std::string className, char **av);

//create functions
std::string	ft_create_constructor(std::string className, int headerOrMain);
std::string	ft_create_destructor(std::string className, int headerOrMain);
std::string	ft_create_copy_constructor(std::string className, int headerOrMain);
std::string	ft_create_operator_overload(std::string className, int headerOrMain);

//check flags
int			ft_check_c_flag(char **av);
int			ft_check_f_flag(char **av);
#endif
